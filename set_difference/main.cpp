#include <algorithm>

int main() 
{
  int a[] = {1, 3, 5, 7};
  int b[] = {2, 4, 6, 8};
  int c[10];

  std::set_difference(a, a + 6, b, b + 4, c);
  return 0;
}