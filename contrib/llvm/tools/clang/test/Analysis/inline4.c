// RUN: %clang_cc1 -analyze -inline-call -analyzer-store region -analyze-function f -verify %s

int g(int a) {    
  return a;
}

int f(int a) {
  // Do not remove block-level expression bindings of caller when analyzing 
  // in the callee.
  if (1 && g(a)) // The binding of '1 && g(a)' which is an UndefinedVal 
                 // carries important information.
    return 1;
  return 0;
}
