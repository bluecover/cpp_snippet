
// int Add(int a, int b) {
//   return a + b;
// }

float Add(float a, float b) {
  return a + b;
}

template<typename T1, typename T2>
int Add(T1 a1, T2 a2) {
  return a1 + a2;
}

int main() {
  float n3 = Add(1,2);

  return 0;
}