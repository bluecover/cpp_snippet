// PlacementNew.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <new.h>
#include <string>
#include <windows.h>
#pragma comment(lib, "Winmm.lib") // for timeGetTime()

class Foo
{
public:
	Foo(const std::wstring& fileName = L"")
		:m_fileName(fileName)
	{
		m_fileName = L"C:/Windows/system32/ATL80.dll";
	}
private:
	std::wstring m_fileName;
};

class Bar
{
public:
	void Test1()
	{
		for (int i = 0; i < 1000000; ++i)
		{
			Foo* pf = new Foo(L"Hello");
			delete pf;
		}
	}
	void Test2()
	{
		for (int i = 0; i < 1000000; ++i)
		{
			Foo* pf = new (buf) Foo(L"Hello");
			pf->~Foo();
		}
	}

private:
	char buf[32];
};

class Base 
{
public:
	int i;
	virtual void f()
	{
		printf("Base::f()\n");
	}
};

class Derived : public Base
{
public:
	void f()
	{
		printf("Derived::f()\n");
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
// 	Base b;
// 	b.f();
// 	b.~Base();
// 	new (&b) Derived;
// 	b.f();
// 
// 	Base* pb = &b;
// 	pb->f();

	Bar b;
	DWORD timeStart = timeGetTime();
	b.Test1();
	DWORD duration = timeGetTime()  - timeStart;

	return 0;
}

