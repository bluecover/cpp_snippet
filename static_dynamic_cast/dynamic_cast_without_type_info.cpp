
#include "Foo.h"
class FooBar;

// û��������Ϣ�������dynamic_cast�����벻��
// 'FooBar *' : invalid target type for dynamic_cast
FooBar* dynamic_cast_without_type_info(Foo* f) {
  FooBar* fb = dynamic_cast<FooBar*>(f);
  return fb;
}