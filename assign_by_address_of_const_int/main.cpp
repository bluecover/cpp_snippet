#include <iostream> 
using namespace std; 
int main(){ 
  const int b = 10; 
  const int &c = b; //b�����á� 
  unsigned d = (unsigned)(&b); 
  int *p = (int*) d; 
  *p = 12; 
  //������������ֵ�ʱ�� 
  if(b == c)//c��b������ 
  { 
    cout<<"true"<<endl; 
  } 
  else 
  { 
    cout<<"false"<<endl; 
  } 
  cout<<"b:"<<b<<",c:"<<c<<endl; 
  cout<<"����b�ĵ�ַ��ȡֵ"<<endl; 
  cout<<*(int *)(unsigned)(&b)<<endl; 
  system("pause"); 
  return 0; 
}