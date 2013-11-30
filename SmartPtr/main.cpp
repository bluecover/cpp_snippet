
#include <string.h>
#include <iostream>

template<typename T>
class SmartPtr {
public:
  SmartPtr(T* p = 0) : pointee_(p) {}
  SmartPtr(const SmartPtr& rhs) : pointee_(rhs.pointee_) {}
  ~SmartPtr() {
    if (pointee_) {
      delete pointee_;
      pointee_ = 0;
    }
  }
  
  SmartPtr& operator=(const SmartPtr& rhs) {
    pointee_ = rhs.pointee_;
  }

  T* operator->() const { return pointee_; }
  T& operator*() const { return *pointee_; }

private:
  T* pointee_;
};

class Foo {
public:
  Foo(int x) : n_(x) {}
  int GetNumber() const { return n_; }
private:
  int n_;
};

class String {
public: 
  String(const char* s = "") {
    value_ = new StringValue(s);
  }
  String(const String& rhs) {
    value_ = rhs.value_;
    value_->ref_count_++;
  }
  String& operator=(const String& rhs) {
    if (this == &rhs) return *this;
    if (--value_->ref_count_ == 0)
      delete value_;
    value_ = rhs.value_;
    value_->ref_count_++;
    return *this;
  }
  ~String() {
    if (--value_->ref_count_ == 0)
      delete value_;
  }

  char& operator[](int index) {
    if (value_->ref_count_ > 1) {
      value_->ref_count_--;
      value_ = new StringValue(value_->data_);
    }
    return value_->data_[index];
  }

  const char& operator[](int index) const {
    return value_->data_[index];
  }

  const char* GetString() const { return value_->data_; } 

private:
  struct StringValue {
    char* data_;
    int ref_count_;
    StringValue(const char* s) : ref_count_(1) {
      data_ = new char[strlen(s) + 1];
      strcpy(data_, s);
    }
    ~StringValue() {
      delete [] data_;
    }
  };

private:
  StringValue* value_;
};

std::ostream& operator<<(std::ostream& o, const String& s) {
  o << s.GetString();
  return o;
}

int main() {
  {
    SmartPtr<int> spi(new int(5));
    *spi = 8;
    int i11 = 3 + *spi;
  }
  
  SmartPtr<Foo> spf(new Foo(11));
  int i33 = 22 + spf->GetNumber();

  String s1 = "Reference Counting";
  String s2 = s1;

  s1[2] = 'X';
  std::cout << s2 << std::endl;

  return 0;
}