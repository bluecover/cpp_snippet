
#include <stdio.h>

void foo() {}
void bar() {}
int baz(int i, int j) { return i + j; }



int guess() {
  int i = 0;
  scanf("%d", &i);
  return i;
}

int main() {
  int g = guess();
  if (g != 100)
    return g + 100;
  switch(g) {
    case 1:
      foo();
      printf("%d\n", 1);
      break;
    case 200:
      bar();
      printf("%d\n", 2);
      break;
    case 33:
      printf("%d\n", baz(100,200));
      break;
    default:
      break;
  }


  return 0;
}