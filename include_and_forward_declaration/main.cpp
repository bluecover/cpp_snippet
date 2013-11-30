
#include "Foo.h"

class Bar;

void fun(Foo* f) {
  Bar* b = (Bar*)f;
}

int main() {
  Foo* foo = new Foo(1, 2);
  Bar* b1 = (Bar*)foo;  // 
  //Bar* b2 = static_cast<Bar*>(foo);
  Bar* b3 = reinterpret_cast<Bar*>(foo);  // 

  return 0;
}         