// static_dynamic_cast.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class Foo
{
public:
    virtual void fun1() {}
    virtual void fun2() {}
    virtual void fun3() {}
};

class Bar
{
public:
    virtual void fun4() {}
    virtual void fun5() {}
    virtual void fun6() {}
};

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

class Baz
{

};

int _tmain(int argc, _TCHAR* argv[])
{
    Bar* pb = new Bar;
    FooBar* pfb_1 = (FooBar*)pb;

    FooBar* pfb = new FooBar;
    pfb->fun2();
    pfb->fun5();

    Baz* pbaz = static_cast<Baz*>(pb);

	return 0;
}

