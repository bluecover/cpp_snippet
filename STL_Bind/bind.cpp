
#include <algorithm>
#include <functional>
#include <list>
using namespace std;

int main() 
{
  int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

  //int* p = partition(a, a + _countof(a), bind1st(less<int>(), 10));

  list<int> li(a, a + _countof(a));
  li.sort();

  return 0;
}