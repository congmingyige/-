#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e3+10;


int main()
{
    double v=1.0;
    char str[100];
    int len,i,ans=0;
    scanf("%s",str);
    len=strlen(str);
    for (i=0;i<len;i++)
        if (str[i]=='2')
            ans++;
    if (str[0]=='-')
        v*=1.5;
    if ((str[len-1]-48)%2==0)
        v*=2;
    if (str[0]=='-')
        len--;
    printf("%.2f%%",v/len*ans*100);///%% ×ªÒå×Ö·û
    return 0;
}
