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
    char a[100];  ///һ������������Ŀ����������20/10���ַ����ڣ�ѡ�񿪴�һ�㣬���ٿ���Ŀ����ʡʱ��(���˶���)
    scanf("%d",&n);
    while (n--)
    {
        scanf("%s%d%d",a,&b,&c);
        if (!(b>=15 && b<=20 && c>=50 && c<=70))    ///����˼��������ȡ��
            printf("%s\n",a);
    }
    return 0;
}
/*
��������
250
*/
