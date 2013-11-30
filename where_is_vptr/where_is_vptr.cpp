// where_is_vptr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class Point2d
{
public:
	int m_x;
	int m_y;
public:
	virtual int z() { return 0; }
};

class Point3d : public Point2d
{
public:
	int m_z;
	virtual int z() 
	{ 
		this->m_z = 2;
		return m_z; 
	}
};

class Vertex
{
public:
	virtual void vfun1() {}
	virtual void vfun2() {}

private:
	int m_test;
};

class Vertex3d : public Point3d, public Vertex
{
public:
// 	virtual int z() 
// 	{
// 		this->m_z = 2;
// 		return m_z; 
// 	}
	virtual void vfun1() {};
	virtual void vfun2() 
	{
        z();
        vfun1();

		this->m_x = 1;
	}
private:
	int m_test2;
};

struct Foo
{
	int x;
	int y;
};

class Bar : public Foo
{
public:
	virtual void fun() {}

private:
	int z;
};

int _tmain(int argc, _TCHAR* argv[])
{
	Vertex3d* pv3d = new Vertex3d;
	Point2d* p2d = pv3d;
	p2d->z();

	// ���ൽ�ڶ��������ָ��ת��
	Vertex* pv = pv3d;

	// virtual function�ĵ���
	pv->vfun2();
    /*
        vptr vptr_Vertex = *((vptr*)pv);
        (*(vptr + 1))(pv);
    */
	_asm
	{
		mov eax, dword ptr [pv] 
		mov edx, dword ptr [eax] 
		mov eax, dword ptr [edx + 4] 
		call eax  
	}

	// Bar�Ļ�����һ��û��virtual function��struct
	// �ɿ���vptr����������ʼ��
	Bar* pb = new Bar;
	pb->fun();
	Foo* pf = pb;

	return 0;
}

