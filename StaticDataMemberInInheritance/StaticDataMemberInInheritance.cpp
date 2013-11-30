// StaticDataMemberInInheritance.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class false_type
{};

class true_type
{};

template<class T>
struct IsPtr
{
    typedef false_type Ret;
};

template<class T>
struct IsPtr<T*>
{
    typedef true_type Ret;
};

class Base
{
public:
	static int sbase;
};

int Base::sbase = 0;

class Derived : public Base
{
public:
	//static int sbase;
};

//int Derived::sbase = 1;

void fun(true_type t)
{

}

void fun(false_type t)
{

}

int _tmain(int argc, _TCHAR* argv[])
{
    int i = Derived::sbase;
    int j = Base::sbase;

    IsPtr<const int*>::Ret ret;
    fun(ret);

	return 0;
}

