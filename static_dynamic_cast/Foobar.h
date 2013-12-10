
#pragma once

#include "Foo.h"
#include "Bar.h"

class FooBar : public Foo, public Bar
{
public:
  virtual void fun1() {}
  virtual void fun2() {}
  virtual void fun3() {}

  virtual void fun4() {}
  virtual void fun5() {}
  virtual void fun6() {}
};