
struct true_type {};
struct false_type {};

template<typename T>
struct ReferenceTraits {
  typedef false_type is_reference;
};

template<typename T>
struct ReferenceTraits<T&> {
  typedef true_type is_reference;
};


template<typename T>
struct ReferenceTraits<const T&> {
  typedef true_type is_reference;
};

void foo(true_type tt) {

}

void foo(false_type tt) {

}

int main() {
  int i = 0;
  int& ri = i;
  
  ReferenceTraits<int>::is_reference is_ref1;
  ReferenceTraits<int&>::is_reference is_ref2;
  ReferenceTraits<const int&>::is_reference is_ref3;

  foo(is_ref1);
  foo(is_ref2);
  foo(is_ref3);

  return 0;
}