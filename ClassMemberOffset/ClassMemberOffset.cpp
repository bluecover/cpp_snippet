// ClassMemberOffset.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class Foo {
public:
  int m_1;
  int m_2;
  int m_3;
};

int _tmain(int argc, _TCHAR* argv[])
{
  int offset_m1 = (int)(&(((Foo*)0)->m_1));
  int offset_m2 = (int)(&(((Foo*)0)->m_2));
  int offset_m3 = (int)(&(((Foo*)0)->m_3));

  Foo* f = new Foo;
  int m_2 = f->m_2;
  
	return 0;
}

