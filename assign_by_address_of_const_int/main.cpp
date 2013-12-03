#include <iostream> 
using namespace std; 
int main(){ 
  const int b = 10; 
  const int &c = b; //b的引用。 
  unsigned d = (unsigned)(&b); 
  int *p = (int*) d; 
  *p = 12; 
  //接下来就是奇怪的时候 
  if(b == c)//c是b的引用 
  { 
    cout<<"true"<<endl; 
  } 
  else 
  { 
    cout<<"false"<<endl; 
  } 
  cout<<"b:"<<b<<",c:"<<c<<endl; 
  cout<<"根据b的地址来取值"<<endl; 
  cout<<*(int *)(unsigned)(&b)<<endl; 
  system("pause"); 
  return 0; 
}