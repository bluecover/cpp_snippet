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
    // I3�����������ϵ�vtbl���ֱ�����I1��I2����I1��I2�������в�ͬ��vptr
    // �����������������ĵ�ַ��Ҫд��vtbl��I1�Ĳ��֣���Ҫд��vtbl��I2�Ĳ���
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

