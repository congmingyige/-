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
    ///a*b�� -> ��һ�� a/b �����ʽ�����Ƶ�
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d/",a);
    if (b<0)
        printf("(%d)",b);
    else
        printf("%d",b);
    if (b==0)
        printf("=Error");
    else
        printf("=%.2f",1.0*a/b);    ///1.0*
    return 0;
}
