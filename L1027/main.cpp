#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e3+10;

/**
���ʵ�ڲ��У���java��һ�£��ҹ��ɣ����������²�
���԰Ѵ���ĳ�c++����һ��
�۲����ݹ��ɣ���ϴ���
**/

char str[20];
bool vis[20],v;
int ind[20],g;

int main()
{
    int i;
    scanf("%s",str);
    for (i=0;i<11;i++)
        vis[str[i]-48]=1;
    printf("int[] arr = new int[]{");
    for (i=9;i>=0;i--)
        if (vis[i])
        {
            if (!v)
                v=1;
            else
                printf(",");
            printf("%d",i);
            ind[i]=g++;
        }
    printf("};\nint[] index = new int[]{"); ///���߿�������һ�����

    for (i=0;i<11;i++)
    {
        if (i!=0)
            printf(",");
        printf("%d",ind[str[i]-48]);
    }
    printf("};");
    return 0;
}
