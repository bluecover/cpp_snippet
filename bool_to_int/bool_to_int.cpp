// bool_to_int.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void fun(bool b)
{
    b = false;
}

int _tmain(int argc, _TCHAR* argv[])
{
    fun(true);
 
    int i = 2;
    bool b2 = i; 

	return 0;
}

