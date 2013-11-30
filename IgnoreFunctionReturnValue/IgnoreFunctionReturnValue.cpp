// IgnoreFunctionReturnValue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class Foo
{
public:
    Foo()
    {
        printf("ctor\n");
    }

    ~Foo()
    {
        printf("dtor\n");
    }

    Foo(const Foo& other)
    {
        printf("hello\n");
    }
};

Foo fun()
{
	Foo f;
    return f;
}

int _tmain(int argc, _TCHAR* argv[])
{
    Foo f = fun();

	return 0;
}

