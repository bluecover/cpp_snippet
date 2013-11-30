
#include <string>
using namespace std;

int main()
{
    int i = 0x12345678;
    int j;
    __asm
    {
        mov eax,dword ptr[i]
        mov dword ptr[j],eax
    }
    int k = i >> 24;

    void* p = malloc(sizeof(int));
    memcpy(p, &i, sizeof(int));

    string s = "hello,world!";
    string sub = s.substr(string::npos);
    return 0;
}