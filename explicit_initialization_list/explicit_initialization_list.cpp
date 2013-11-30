// explicit_initialization_list.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class widget
{
public:
    int a;
    int b;
    int c;
};

int _tmain(int argc, _TCHAR* argv[])
{
    widget w = { 1, 2, 3};

	return 0;
}

