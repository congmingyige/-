#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
using namespace std;



int main()
{
    int n,b,c;
    char a[100];  ///一般天梯赛的题目，姓名都在20/10个字符以内，选择开大一点，不再看题目，节省时间(因人而异)
    scanf("%d",&n);
    while (n--)
    {
        scanf("%s%d%d",a,&b,&c);
        if (!(b>=15 && b<=20 && c>=50 && c<=70))    ///减轻思考量，不取补
            printf("%s\n",a);
    }
    return 0;
}
/*
测试数据
250
*/
