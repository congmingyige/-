#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e3+10;
const double eps=1e-8;

char a[maxn],b[maxn];

bool judge(char s[maxn])
{
    int i,len;
    len=strlen(s);
    for (i=0;i<len;i++)
        if (!(s[i]>='0' && s[i]<='9'))
            return 0;
    ///很多个0
    int v=atoi(s);
    if (v==0)
        return 0;
    /**
    如果输入的确是两个正整数
    如果某个输入不合要求

    感觉这两个不对等，

    如果某个输入符合要求，则按格式A + B = 和输出。
    如果某个输入不合要求，则在相应位置输出?，显然此时和也是?。
    **/
    if (len>4 || (len==4 && strcmp(s,"1000")!=0))
        return 0;
    return 1;
}

int main()
{
    bool x,y;
    scanf("%s ",a);
    /**
    题目保证至少存在一个空格，并且B不是一个空字符串：
    遇到这种奇怪的写法，应考虑B可能有多个空格
    **/
    fgets(b,maxn,stdin);
    ///根据测试，一定要处理'\n'。要不要处理具体要看数据，如果.in里没有多余的换行符，是不用处理的。
    if (b[strlen(b)-1]=='\n')
        b[strlen(b)-1]=0;
//    ///也可以写成
//    int lenb=0;
//    while (1)
//    {
//        scanf("%c",&b[lenb]);
//        if (b[lenb]=='\n')
//        {
//            b[lenb]=0;
//            break;      ///遇到break，continue，要分行写。遇到printf,scanf，可以连着写
//        }
//        else
//            lenb++;
//    }

    x=judge(a);
    y=judge(b);
    if (x)
        printf("%d",atoi(a));
    else
        printf("?");

    printf(" + ");

    if (y)
        printf("%d",atoi(b));
    else
        printf("?");

    printf(" = ");

    if (x && y)
        printf("%d",atoi(a)+atoi(b));
    else
        printf("?");
    return 0;
}
