#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  vector<int> vi;
  set<int> si;
  for (int i = 0; i < 20; i++) {
    vi.push_back(i);
    si.insert(i);
  }

  // find numbers in range (3, 7)
  vector<int>::iterator begin = upper_bound(vi.begin(), vi.end(), 3);
  vector<int>::iterator end = lower_bound(vi.begin(), vi.end(), 7);
  while (begin != end) {
    cout << *begin++ << " ";
  }
  cout << endl;

  set<int>::iterator first = si.upper_bound(3);
  set<int>::iterator last = si.lower_bound(7);
  while (first != last) {
    cout << *first++ << " ";
  }
  cout << endl;
}