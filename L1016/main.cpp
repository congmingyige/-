#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e3+10;

int v[20]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char ch[12]={'1','0','X','9','8','7','6','5','4','3','2'};
char str[20];

bool judge()    ///many branches, result=0/1, use function
{
    int ans=0,i;
    for (i=0;i<17;i++)
        if (str[i]<'0' || str[i]>'9')
            return 0;
        else
            ans+=(str[i]-'0')*v[i];
    ans%=11;
    if (ch[ans]!=str[17])
        return 0;
    return 1;
}

int main()
{
    int n;
    bool vis=1;

    scanf("%d",&n);
    while (n--) ///better than for (i=1;i<=n;i++)
    {
        scanf("%s",str);
        if (!judge())
            vis=0,printf("%s\n",str);
    }
    if (vis)
        printf("All passed");
    return 0;
}
