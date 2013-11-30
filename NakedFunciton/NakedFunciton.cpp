// NakedFunciton.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>

const char* msg = "Hello, world";
 
extern "C" _declspec(naked) void __stdcall fun()
{
	_asm
	{
		mov eax, MB_OKCANCEL
		or  eax, MB_ICONQUESTION
		push eax
		push 0
		push dword ptr [msg]
		push 0
		call dword ptr [MessageBoxA] 
		ret
	}
}

extern "C" _declspec(naked) int __stdcall add(int a)
{
	_asm
	{
		mov  eax, dword ptr [a]
        ret 4
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
    int i = add(10);

	return 0;
}

