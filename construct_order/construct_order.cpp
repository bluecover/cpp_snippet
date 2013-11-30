// construct_order.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class foo
{
public:
    foo()
    {
        printf("foo::foo()\n");
    }
};

class bar
{
public:
    bar(int i)
    {
        printf("bar::bar()\n");
    }
};

class widget
{
public:
    widget()
        : b(1)
    {
        printf("widget::wdiget()\n");
    }

    bar b;
    foo f;
};

int _tmain(int argc, _TCHAR* argv[])
{
    widget w;

	return 0;
}

