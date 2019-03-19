#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e3+10;
const int inf=1e9;
const double eps=1e-8;



int main()
{
    int g=0;
    char str[20],a[20],b[20];
    while (1)
    {
        scanf("%s",str);
        if (strcmp(str,".")==0)
            break;
        g++;
        if (g==2)
            strcpy(a,str);
        if (g==14)
            strcpy(b,str);
    }
    if (g>=14)
        printf("%s and %s are inviting you to dinner...",a,b);  ///copy,Ë«»÷²¢Ìæ»»
    else if (g>=2)
        printf("%s is the only one for you...",a);
    else
        printf("Momo... No one is for you ...");
    return 0;
}
/**
²âÊÔ£ºÕÒ±ßÔµÑùÀı
**/
