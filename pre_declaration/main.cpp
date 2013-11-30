#include <vector>

class Foo;

class Bar {
private:
  std::vector<Foo> foos_;
};

class Foo {};

int main() {
  Bar b;
}