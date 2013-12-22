
void fun1(int i, int j) {}
void fun1(float f, float g) {}

class Bar {
public:
  Bar(int x) : i_(x) {}
  int Add(int x, int y) { return i_ + x + y; }
  int Add(int x) const { return i_ + x; }
private:
  int i_;
};

int main() {
  void(*pii)(int,int) = &fun1;
  void(*pff)(float,float) = &fun1;
  pff(1.0f, 2.0f);

  int(Bar::*p_bar_ii)(int,int) = &Bar::Add;
  int(Bar::*p_bar_i)(int)const = &Bar::Add;
  Bar b(100);
  int r1 = (b.*p_bar_ii)(1,2);
  int r2 = (b.*p_bar_i)(3);

  return 0;
}