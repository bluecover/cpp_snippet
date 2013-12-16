class Bar {
public:
  Bar(int x) : n_(x) {}
  int n() const { return n_; }
private:
  int n_;
};

int operator-(const Bar& b1, const Bar& b2) {
  return b1.n() - b2.n();
}

int operator+(const Bar& b1, const Bar& b2) {
  return b1.n() + b2.n();
}

template<typename T1, typename T2>
int foo(T1 a1, T2 a2) {
  return a1 - a2;
}

template<typename T1, typename T2>
int foo(const T1& a1, const T2& a2) {
  return a1 + a2;
}

int main()
{
  Bar b1(1);
  Bar b2(2);
  const Bar& rb1 = b1;
  const Bar& rb2 = b2;
  int k = foo(rb1, rb2);

	return 0;
}

