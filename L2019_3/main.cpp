#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

/**
string -> int

这种情况，我感觉如果用map在时间上允许(logn)，就用map。

O(n)
**/

const int maxn=1e4+10;

char str[5];
///(26+26+10)^4 = 14776336 [0,14776336)
bool v[14776336];

struct node
{
    char a[5];
    int b;
    bool operator<(node y)
    {
        return strcmp(a,y.a)<0;
    }
}x[maxn],y[maxn];

int cal(char str[5])
{
    int x=0,y=1,z,i;
    for (i=0;i<4;i++)
    {
        if (str[i]>='a' && str[i]<='z')
            z=str[i]-'a';
        else if (str[i]>='A' && str[i]<='Z')
            z=str[i]-'A'+26;    ///这样写不容易错，也慢不了多少
        else
            z=str[i]-'0'+52;
        x+=y*z;
        y=y*62;///
    }
    return x;
}

int main()
{
    int n,m,g=0,i;
    bool vis=0;
    double tot=0;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%s",str);
        v[cal(str)]=1;
    }
    scanf("%d",&m);
    for (i=1;i<=m;i++)
    {
        scanf("%s%d",x[i].a,&x[i].b);
        tot+=x[i].b;
    }
    tot/=m;
    for (i=1;i<=m;i++)
        if (x[i].b>tot)
            y[++g]=x[i];
    sort(y+1,y+g+1);

    for (i=1;i<=g;i++)
        if (v[cal(y[i].a)]==0)
            printf("%s\n",y[i].a),vis=1;
    if (!vis)
        printf("Bing Mei You\n");
    return 0;
}
