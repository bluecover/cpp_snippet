// inline_fun_not_in_h.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>

#include "Foo.h"

int _tmain(int argc, _TCHAR* argv[])
{
    Foo f;

    DWORD time = timeGetTime();

    int n = 0;
    for (int i = 0; i < 2000000000; ++i)
    {
        n += f.I() + f.J() + f.K();
        n += 1;
        f.update();
    }
    
    printf("%d\n", n);
    printf("%d\n", timeGetTime() - time);

	return 0;
}

