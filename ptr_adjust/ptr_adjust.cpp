// ptr_adjust.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class Base1
{
public:
    int m_base1_data;
    int m_base1_data2;

    virtual ~Base1() {}
    virtual void fun_b1() {}
    virtual Base1* clone() { return 0; }
};

class Base2
{
public:
    int m_base2_data;

    virtual ~Base2() {}
    virtual Base2* clone() { return 0; }
    virtual void fun_b2() 
    {
        m_base2_data = 2;
    }
};

class Derived1 : public Base1, public Base2
{
public:
    int m_d1_data;

    virtual ~Derived1()
    {
        m_base1_data = 1;
        m_base2_data = 2;
    }

    virtual void fun_b1() 
    {
        m_base1_data = 1;
        m_base2_data = 2;
    }

    virtual void fun_b2() 
    {
        m_base1_data = 1;
        m_base2_data = 2;
    }
    
    virtual Derived1* clone() 
    { 
        return 0; 
    }

};



int _tmain(int argc, _TCHAR* argv[])
{
    Derived1* pd1 = new Derived1;
    Base2* pb2 = pd1;

    pd1->fun_b1();

    int szd1 = sizeof(Derived1);
    pd1->clone();

    pb2->fun_b2();
    pb2->clone();
    delete pb2;

    Derived1* pdsc = static_cast<Derived1*>(pb2);
    Derived1* pdoc = (Derived1*)(pb2);

	return 0;
}

