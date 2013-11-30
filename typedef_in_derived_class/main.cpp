
class A
{
public:
    typedef int MyType;
};

class B
{
public:
    typedef float MyType;

    B()
    {
        MyType a;
        a = 2;
    }
};

int main()
{
    B::MyType var;

    return 0;
}