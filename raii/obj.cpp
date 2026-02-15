
#include <stdio.h>
#include "shape.h"
#include <utility>

// Inference collapse


void foo(const shape&)
{
  puts("foo(const shape&)");
}

void foo(shape&&)
{
  puts("foo(shape&&)");
}

void bar(const shape& s)
{
  puts("bar(const shape&)");
  foo(s);
}

// Named rvalue references are lvalues.
void bar(shape&& s)
{
  puts("bar(shape&&)");
  foo(s); // s is an lvalue here !
}

// To keep the value category, lvalue is always lvalue, rvalue is rvalue
template <typename T>
void bar(T&& s)
{
  foo(std::forward<T>(s));
  // std::forward restores the original value category.
  // That equals static_cast<circle&&>(s)
}

// g++ shape.cpp obj.cpp -std=c++17 -o main.out
int main()
{
  bar(circle());
}