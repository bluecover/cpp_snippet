
#include "Foo.h"
class FooBar;

// 没有类型信息的情况下dynamic_cast，编译不过
// 'FooBar *' : invalid target type for dynamic_cast
FooBar* dynamic_cast_without_type_info(Foo* f) {
  FooBar* fb = dynamic_cast<FooBar*>(f);
  return fb;
}