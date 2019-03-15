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
    ///�ܶ��0
    int v=atoi(s);
    if (v==0)
        return 0;
    /**
    ��������ȷ������������
    ���ĳ�����벻��Ҫ��

    �о����������Եȣ�

    ���ĳ���������Ҫ���򰴸�ʽA + B = �������
    ���ĳ�����벻��Ҫ��������Ӧλ�����?����Ȼ��ʱ��Ҳ��?��
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
    ��Ŀ��֤���ٴ���һ���ո񣬲���B����һ�����ַ�����
    ����������ֵ�д����Ӧ����B�����ж���ո�
    **/
    fgets(b,maxn,stdin);
    ///���ݲ��ԣ�һ��Ҫ����'\n'��Ҫ��Ҫ�������Ҫ�����ݣ����.in��û�ж���Ļ��з����ǲ��ô���ġ�
    if (b[strlen(b)-1]=='\n')
        b[strlen(b)-1]=0;
//    ///Ҳ����д��
//    int lenb=0;
//    while (1)
//    {
//        scanf("%c",&b[lenb]);
//        if (b[lenb]=='\n')
//        {
//            b[lenb]=0;
//            break;      ///����break��continue��Ҫ����д������printf,scanf����������д
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
