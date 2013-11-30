// Named_Return_Value.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class Foo
{
public:
  Foo()
  {
    printf("Foo::Foo()\n");
    a = 1;
    b = 2;
    c = 3;
  }

  Foo(const Foo& o)
  {
    printf("Foo::Foo(const Foo& o)\n");
    a = o.a;
    b = o.b;
    c = o.c;
  }

  ~Foo()
  {
    printf("~Foo()\n");
  }

  Foo& operator=(const Foo* x) {
    if (x != this) return *this;
    a = x->a;
    b = x->b;
    c = x->c;
    a++;
    return *this;
  }

  int a;
  int b;
  int c;
};

Foo get_foo()
{
  Foo f;
  f.a = 3;
  f.b = 2;
  f.c = 1;
  return f;
}

int _tmain(int argc, _TCHAR* argv[])
{
  Foo f;
  f = get_foo();

  return 0;
}

