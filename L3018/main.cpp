#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

/*
maybe
Setting->Compiler->C++11
*/

const int maxn=1e4+10;
const double eps=1e-8;
int a[101][101],cond[101][101],b,c,d,e;
double value[101][101];
int dx[8]={-1,0,0,1,-1,-1,1,1};
int dy[8]={0,-1,1,0,-1,1,-1,1};
int zzzz[2]={-1,1};
bool vis[101][101];

struct node
{
    int x,y;
    double v;
    bool operator<(const node &b) const ///第二个const必须有
    {
        return b.v<v;   ///opposite
    }
};
priority_queue<node,vector<node> >st;

int main()
{
    int n,m,b,c,d,e,x,y,xx,yy,zzz,zz,i,j;
    double v,vv,dif,f=0,ans=0;
    scanf("%d%d",&n,&m);
    swap(n,m);
    for (j=0;j<m;j++)
        for (i=0;i<n;i++)
            scanf("%d",&a[i][j]);
    scanf("%d%d%d%d",&b,&c,&d,&e);

    if (d!=b)
        dif=c-1.0*(e-c)/(d-b)*b;
    for (j=0;j<m;j++)
        for (i=0;i<n;i++)
        {
            if (d==b)
            {
                if (i<b)
                    cond[i][j]=-1;
                else if (i>b)
                    cond[i][j]=1;
                else
                    cond[i][j]=0;
            }
            else
            {
                f=dif+1.0*(e-c)/(d-b)*i;
                if (j>f+eps)
                    cond[i][j]=1;
                else if (j<f-eps)
                    cond[i][j]=-1;
                else
                    cond[i][j]=0;
            }
        }

//    for (j=0;j<m;j++)
//        for (i=0;i<n;i++)
//            printf("%d%c",cond[i][j],i==n-1?'\n':' ');

    for (j=0;j<m;j++)
        for (i=0;i<n;i++)
            value[i][j]=1.0e15;
    value[b][c]=0;

    ans=0;
    for (zzz=0;zzz<=1;zzz++)
    {
        value[d][e]=1.0e15;
        zz=zzzz[zzz];
        memset(vis,0,sizeof(vis));
        while (!st.empty())
            st.pop();
        st.push({b,c,0});
        while (1)
        {
            while (!st.empty() && vis[st.top().x][st.top().y])  ///第一个可以不加，肯定可以找到解
                st.pop();
            if (st.empty())
                break;
            x=st.top().x;
            y=st.top().y;
            v=st.top().v;
            vis[x][y]=1;
            st.pop();
            if (x==d && y==e)
            {
                ans+=v;
                break;
            }
            for (i=0;i<8;i++)
            {
                xx=x+dx[i];
                yy=y+dy[i];
                if (xx>=0 && xx<n && yy>=0 && yy<m && (cond[xx][yy]==zz || (xx==d && yy==e)))
                {
                    vv=v+a[xx][yy];
                    if (i>=4)
                        vv+=(sqrt(2)-1)*(a[x][y]+a[xx][yy]);
                    if (vv<value[xx][yy])
                    {
                        value[xx][yy]=vv;
                        st.push({xx,yy,vv});
                    }
                }
            }
        }
    }
    printf("%.2f",ans+a[b][c]-a[d][e]);
    return 0;
}
/*
3 3
1 1 1
2 0 3
3 0 1
1 0 1 2
*/
