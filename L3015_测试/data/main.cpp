#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <time.h>
using namespace std;

#define ll long long

const int maxn=1e4+10;
const int inf=1e9;
const double eps=1e-8;



int main()
{
    int i,j,k,n;
    srand(time(NULL));
    n=(rand()*rand()*rand()*rand()*rand()%19+19)%19+2;
//    n=20;
    printf("%d\n",n);
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
            if (i==j)
                printf("-");
            else
            {
                k=rand()%4;
                if (k==0)
                    printf("W");
                else if (k==1)
                    printf("L");
                else
                    printf("D");
            }
        printf("\n");
    }


//    for (i=1;i<=20;i++)
//    {
//        for (j=1;j<=20;j++)
//            if (i==j)
//                printf("-");
//            else
//                printf("W");
//        printf("\n");
//    }
    return 0;
}
/*

*/
