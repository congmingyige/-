#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <stdbool.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;
#define maxn 100000+5
#define inf 100000+5

///复杂，不建议学习
//还可以求第k大(k值固定)
//要删除指定值的话只能自己写一个优先队列

struct node
{
    int d,g;
};

int f[maxn],treenum[maxn];
//posa[i],posb[i]:a/b中第i个点在输入中的位置
//input[i]:输入中第i个点在树的位置(pos标记是在哪棵树)
int a[maxn],b[maxn],posa[maxn],posb[maxn],input[maxn];

//最大堆
struct cmp1
{
    bool operator() (int a,int b)
    {
        return f[a]<f[b];
    }
};

//最小堆
struct cmp2
{
    bool operator() (int a,int b)
    {
        return f[a]>f[b];
    }
};

//从小到大排序
//前(n+1)/2个数：a(最大堆)
//后n/2个数：b(最小堆)
//中位数永远是a的最大值
//增添和删除：也许需要a的最大值移向b或b的最小值移向a
//priority_queue<int,vector<int>,cmp1 > a;
//priority_queue<int,vector<int>,cmp2 > b;

void up_min(int t[],int pos[],int input[],int i)
{
    int j,temp;
    while (i>1)
    {
        j=i>>1;
        //j<i
        if (t[j]>t[i])
        {
            temp=t[i];
            t[i]=t[j];
            t[j]=temp;

            temp=pos[i];
            pos[i]=pos[j];
            pos[j]=temp;

            input[pos[i]]=i;
            input[pos[j]]=j;
        }
        else
            break;
        i=j;
    }
}

void down_min(int t[],int pos[],int input[],int i)
{
    int j,temp;
    while (( i<<1)<=t[0])
    {
        j=i<<1;
        if (j!=t[0] && t[j+1]<t[j])
            j=j|1;
        //i<j
        if (t[i]>t[j])
        {
            temp=t[i];
            t[i]=t[j];
            t[j]=temp;

            temp=pos[i];
            pos[i]=pos[j];
            pos[j]=temp;

            input[pos[i]]=i;
            input[pos[j]]=j;
        }
        else
            break;
        i=j;
    }
}

void push_min(int t[],int pos[],int input[],struct node p)
{
    t[0]++;
    t[t[0]]=p.d;
    pos[t[0]]=p.g;
    input[p.g]=t[0];
    up_min(t,pos,input,t[0]);
}

void pop_min(int t[],int pos[],int input[])
{
    t[1]=t[t[0]];
    pos[1]=pos[t[0]];
    input[pos[1]]=1;
    t[0]--;
    down_min(t,pos,input,1);
}

void minus_min(int t[],int pos[],int input[],int w,int d)
{
    t[w]-=d;
    up_min(t,pos,input,w);
}

void plus_min(int t[],int pos[],int input[],int w,int d)
{
    t[w]+=d;
    down_min(t,pos,input,w);
}


void up_max(int t[],int pos[],int input[],int i)
{
    int j,temp;
    while (i>1)
    {
        j=i>>1;
        //j<i
        if (t[j]<t[i])
        {
            temp=t[i];
            t[i]=t[j];
            t[j]=temp;

            temp=pos[i];
            pos[i]=pos[j];
            pos[j]=temp;

            input[pos[i]]=i;
            input[pos[j]]=j;
        }
        else
            break;
        i=j;
    }
}

void down_max(int t[],int pos[],int input[],int i)
{
    int j,temp;
    while ((i<<1)<=t[0])
    {
        j=i<<1;
        if (j!=t[0] && t[j+1]>t[j])
            j=j|1;
        //i<j
        if (t[i]<t[j])
        {
            temp=t[i];
            t[i]=t[j];
            t[j]=temp;

            temp=pos[i];
            pos[i]=pos[j];
            pos[j]=temp;

            input[pos[i]]=i;
            input[pos[j]]=j;
        }
        else
            break;
        i=j;
    }
}

void push_max(int t[],int pos[],int input[],struct node p)
{
    int i,j,temp;
    t[0]++;
    t[t[0]]=p.d;
    pos[t[0]]=p.g;
    input[p.g]=t[0];
    up_max(t,pos,input,t[0]);
}

void pop_max(int t[],int pos[],int input[])
{
    t[1]=t[t[0]];
    pos[1]=pos[t[0]];
    input[pos[1]]=1;
    t[0]--;
    down_max(t,pos,input,1);
}

void plus_max(int t[],int pos[],int input[],int w,int d)
{
    t[w]+=d;
    up_max(t,pos,input,w);
}

void minus_max(int t[],int pos[],int input[],int w,int d)
{
    t[w]-=d;
    down_max(t,pos,input,w);
}

int size(int t[])
{
    return t[0];
}

struct node top(int t[],int pos[])
{
    struct node p;
    p.d=t[1];
    p.g=pos[1];
    return p;
}

bool empty(int t[])
{
    if (t[0]==0)
        return true;
    else
        return false;
}

void change()
{
    struct node cond;
    int d;
    if (size(a)<size(b))
//    if (a.size()<b.size())
    {
        cond=top(b,posb);
        pop_min(b,posb,input);
        push_max(a,posa,input,cond);
//        d=b.top();
//        b.pop();
//        a.push(d);
        treenum[cond.g]=0;
    }
    else if (size(a)>size(b)+1)
//    else if (a.size()>b.size()+1)
    {
        cond=top(a,posa);
        pop_max(a,posa,input);
        push_min(b,posb,input,cond);
//        d=a.top();
//        a.pop();
//        b.push(d);
        treenum[cond.g]=1;
    }
}

int main()
{
    struct node cond;
    int n,g;
    char s[20];
    a[0]=0; b[0]=0;
    scanf("%d",&n);
    while (n)
    {
        n--;
        scanf("%s",s);
        if (strcmp(s,"Pop")==0)
        {
            if (g==0)
            {
                printf("Invalid\n");
                continue;
            }
            printf("%d\n",f[g]);
            if (treenum[g]==0)
            {
//                f[g]+=inf;
//                a.pop();
                plus_max(a,posa,input,input[g],inf);
                pop_max(a,posa,input);
            }
            else
            {
//                f[g]-=inf;
//                b.pop();
                minus_min(b,posb,input,input[g],inf);
                pop_min(b,posb,input);
            }
            g--;
            change();
        }
        else if (strcmp(s,"Push")==0)
        {
            g++;
            scanf("%d",&f[g]);
//            if (a.empty() || f[g]<=f[a.top()])
            if (empty(a) || f[g]<=top(a,posa).d)
            {
                cond.d=f[g];
                cond.g=g;
//                a.push(g);
                push_max(a,posa,input,cond);
                treenum[g]=0;
            }
            else
            {
                cond.d=f[g];
                cond.g=g;
//                b.push(g);
                push_min(b,posb,input,cond);
                treenum[g]=1;
            }
            change();
        }
        else
        {
            if (g==0)
                printf("Invalid\n");
            else
//                printf("%d\n",f[a.top()]);
                printf("%d\n",top(a,posa).d);
        }
    }
    return 0;
}
/*
100
Push 1
PeekMedian
Push 2
PeekMedian
Push 3
PeekMedian
Push 4
PeekMedian
Push 5
PeekMedian
Pop
PeekMedian
Pop
PeekMedian
Pop
PeekMedian
Pop
PeekMedian
Pop
PeekMedian
Pop


100
Push 5
PeekMedian
Push 4
PeekMedian
Push 3
PeekMedian
Push 2
PeekMedian
Push 1
PeekMedian
Pop
PeekMedian
Pop
PeekMedian
Pop
PeekMedian
Pop
PeekMedian
Pop
PeekMedian
Pop

*/
