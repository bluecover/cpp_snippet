// DuplicatedVirtualFunction.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class IUnknow
{
public:
    virtual void AddRef() = 0;
    virtual void Release() = 0;
};

class I1 : public IUnknow
{

};

class I2 : public IUnknow
{

};

class I3 : public I1, public I2
{
public:
    // I3有两个概念上的vtbl，分别来自I1和I2，而I1和I2部分又有不同的vptr
    // 所以下面两个函数的地址既要写入vtbl中I1的部分，又要写入vtbl中I2的部分
    virtual void AddRef()
    {
        printf("I3::AddRef()\n");
    }

    virtual void Release()
    {
        printf("I3::Release()\n");
    }
};

int _tmain(int argc, _TCHAR* argv[])
{
    I2* p = new I3;
    
    p->AddRef();
    p->Release();

	return 0;
}

