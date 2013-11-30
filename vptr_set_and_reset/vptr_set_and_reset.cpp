// vptr_set_and_reset.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class Foo
{
public:
    Foo()
    {
       m_i = 0;
    }

    ~Foo()
    {
        m_i = 0;
    }

    virtual void fun()
    {
        m_i = 2;
        printf("Foo::fun()\n");
    }

private:
    int m_i;
};

class Bar : public Foo
{
public:
    Bar()
    {
        m_j = 0;
    }
    ~Bar()
    {
        m_j = 0;
        fun();
    }

    virtual void fun()
    {
        m_j = 2;
        printf("Bar::fun()\n");
    }

private:
    int m_j;
};

int _tmain(int argc, _TCHAR* argv[])
{
    Bar b;

	return 0;
}

