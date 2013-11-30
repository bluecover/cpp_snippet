
#include <new.h>
#include <memory.h>

template <class R, class P>
class Delegate {
  public:
  Delegate(R(*fun)(P)) {
    invoker_ = new(invoker_buffer_) FreeFunctionInvoker(fun);
  }

  template<class T, class R, class P>
  Delegate(T* object, R(T::*function)(P)) {
    invoker_ = new(invoker_buffer_) MemberFunctionInvoker<T>(object, function);
  }

  Delegate(const Delegate& other) {
    memcpy(invoker_buffer_, other.invoker_buffer_, sizeof(invoker_buffer_));
    invoker_ = (Invoker*)invoker_buffer_;
  }

  R operator()(P args) { return invoker_->Invoke(args); }

  bool IsInUse() const { return invoker_ != 0; }
  void Clean() { invoker_ = 0; }

 private:
  class Invoker {
    public:
    virtual R Invoke(P args) = 0;
  };

  class FreeFunctionInvoker : public Invoker {
    public:
    typedef R(*FunctionPointer)(P);

    FreeFunctionInvoker(FunctionPointer f) : function_pointer_(f) {}

    virtual R Invoke(P args) { return function_pointer_(args); }

   private:
    FunctionPointer	function_pointer_;
  };

  template <class T>
  class MemberFunctionInvoker : public Invoker {
    public:
    typedef R(T::*MemberFunctionPointer)(P);

    MemberFunctionInvoker(T* object, MemberFunctionPointer pmf) :
      object_(object),
      member_function_pointer_(pmf)
    {}

    virtual R Invoke(P args) {
      return (object_->*member_function_pointer_)(args);
    }

  private:
    T* object_;
    MemberFunctionPointer	member_function_pointer_;
  };

 private:
  Invoker* invoker_;
  char invoker_buffer_[16]; // buffer for placement new invoker object
};

typedef int TF(void);

int Return3() {
  return 3;
}

void Foo(int& i) {
  i++;
}

int main()
{
  TF* ptf = Return3;
  int i3 = ptf();

  Delegate<void,int&> d(&Foo);
  d(i3);


  return 0;
}