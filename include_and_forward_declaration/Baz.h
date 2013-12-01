
#include "Foo.h"
#include "Bar.h"

class Baz : public Foo, public Bar {
private:
  int m_;
  int n_;
public:
  Baz(int a, int b, int c, int d, int e, int f) 
    : Foo(a,b), Bar(c, d), m_(e), n_(f) {

  }
};