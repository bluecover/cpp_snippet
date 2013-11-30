#pragma once

class Foo
{
public:
    Foo() : i(1), j(2), k(3) {}
    int get_i() { return i; }
    int get_j() { return j; }
    int get_k() { return j; }
    
    inline int I();
    inline int J();
    inline int K();

    void update()
    {
        i += 1;
        j += 1;
        k += 1;
    }

private:
    int i, j, k;
};