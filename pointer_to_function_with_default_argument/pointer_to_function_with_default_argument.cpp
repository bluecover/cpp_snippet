
int Add(int a, int b, int c = 10) {
  return a + b + c;
}

int main() {
  int(*p_add)(int,int) = &Add;
  int s = p_add(1, 2);

  return 0;
}
