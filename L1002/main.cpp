#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e3+10;

///also can use for ... , and copy the code
void print(char c,int g)
{
    for (int i=1;i<=g;i++)
        printf("%c",c);
}

int main()
{
    int n,k,len,i;
    char c;
    scanf("%d %c",&n,&c);
    k=30;
    while (k*k*2-1>n)
        k--;
    len=k*2-1;
    for (i=len;i>=1;i-=2)
    {
        print(' ',(len-i)/2);
        print(c,i);
        ///no extra ' '
        print('\n',1);
    }
    for (i=3;i<=len;i+=2)
    {
        print(' ',(len-i)/2);
        print(c,i);
        print('\n',1);
    }
    printf("%d",n-k*k*2+1);
    return 0;
}
