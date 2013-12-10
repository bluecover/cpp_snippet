
#include "Foobar.h"

class Baz
{

};

FooBar* dynamic_cast_without_type_info(Foo* f);

int main(int argc, char* argv[])
{
  Bar* pb = new Bar;
  FooBar* pfb_1 = (FooBar*)pb;

  FooBar* pfb = new FooBar;
  pfb->fun2();
  pfb->fun5();

  Baz* pbaz1 = (Baz*)pb;

  dynamic_cast_without_type_info(new Foo);

  return 0;
}

