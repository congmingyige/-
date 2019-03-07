#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e4+10;

char a[maxn],b[maxn];
bool v[257];

int main()
{
    int lena,lenb,i;
    fgets(a,maxn,stdin);///can't use gets in cccc
    fgets(b,maxn,stdin);
    lena=strlen(a);
    lenb=strlen(b);
    for (i=0;i<lenb;i++)
        v[b[i]]=1;
    for (i=0;i<lena;i++)
        if (!v[a[i]])
            printf("%c",a[i]);
    return 0;
}
