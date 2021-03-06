
class Foo;
class Bar;
class Baz;

//#include "Baz.h"

int main() {
  Baz* baz = (Baz*)64;
  Bar* b1 = (Bar*)baz;  // OK, implicit cast can work without type information!
  //Bar* b2 = static_cast<Bar*>(baz);  // can't compile
  Bar* b3 = reinterpret_cast<Bar*>(baz);  // OK b3只有声明时和b1相等，include "Baz.h"时和b1不相等
  int n = sizeof(Baz); // sizeof must see type definition.
  return 0;
}         