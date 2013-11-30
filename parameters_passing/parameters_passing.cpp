// parameters_passing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

extern "C" _declspec(naked) int __stdcall basic_param(int a, char c, int* p)
{
    __asm
    {
        push ebp
        mov ebp, esp
        
        // *p = 5
        mov eax, dword ptr [ebp + 10h]
        mov dword ptr [eax], 5

        // a + c
        mov eax, dword ptr [ebp + 8]
        add eax, dword ptr [ebp + 0Ch]

        mov esp, ebp
        pop ebp
        ret 12
    }
}

extern "C" _declspec(naked) void __stdcall struct_param(int a, char c, int* p)
{

}

struct foo
{
    foo()
    {

    }

    foo(const foo& o)
    {
        m_1 = 1;
        m_2 = 2;
        m_3 = 3;
        m_4 = 4;
    }

    int m_1;
    int m_2;
    int m_3;
    int m_4;
};

extern "C" void __stdcall fun2(foo f)
{
    f.m_1 = 1;
    f.m_2 = 2;
}

int _tmain(int argc, _TCHAR* argv[])
{
    int local_int;

    int i = basic_param(1, 'a', &local_int);

    foo f;
   // f.m_1 = 2;
    //f.m_2 = 3;
    fun2(f);

	return 0;
}

