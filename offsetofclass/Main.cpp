
class Base1
{
    int b1;
    char c;
};

class Base2
{
    int b2_a;
    int b2_b;
    int b2_c;
};

class Derived : public Base1, public Base2
{
    int d1;
};

int main()
{
    Derived* pd = (Derived*)(8);
    Base2* pb = static_cast<Base2*>(pd);

    int offset = (int)(pb) - 8;
    
    return 0;
}