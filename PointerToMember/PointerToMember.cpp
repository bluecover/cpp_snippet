// PointerToMember.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class Foo
{
public:
	int i1;
	int i2;
	int i3;
};


int _tmain(int argc, _TCHAR* argv[])
{
	int Foo::*pi1 = &Foo::i1;
	int Foo::*pi2 = &Foo::i2;
	int Foo::*pi3 = &Foo::i3;

	printf("%p \n", pi1);
	printf("%p \n", pi2);
	printf("%p \n", pi3);

	Foo f;
	f.i1 = 1;
	f.i2 = 2;
	f.i3 = 3;

	printf("%d \n", f.*pi3);

	return 0;
}

