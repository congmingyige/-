#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#define ll long long

const int maxn=1e4+10;
const int inf=1e9;
const double eps=1e-8;



int main()
{
    char s[100];
    int k,i;
    scanf("%d",&k);
    k++;
    for (i=1;;i++)
    {
        scanf("%s",s);
        if (strcmp(s,"End")==0)
            break;
        if (i%k==0)
        {
            printf("%s\n",s);

        }
        else
        {
            if (strcmp(s,"ChuiZi")==0)
                printf("Bu\n");
            if (strcmp(s,"JianDao")==0)
                printf("ChuiZi\n");
            if (strcmp(s,"Bu")==0)  ///don't need to write 'else', copy three times
                printf("JianDao\n");

        }
    }
    return 0;
}
