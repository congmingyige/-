#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=1e3+10;

char str[maxn],c=' ';
int i,j,len,w=0;

///结构体：函数相互调用
struct node
{
    //void error()
    //{
    //    printf("wrong at %d",i);
    //    exit(0);
    //}

    void print(int x,int y)
    {
        if (x<=y)
        for (int z=x;z<=y;z++)
            printf("%c",str[z]);
    }

    void pb()
    {
        for (int k=1;k<=w*2;k++)
            printf("%c",c);
    }

    void cls()
    {
        while (str[i]==' ')
            i++;
    }

    ///a line with end character ';'
    void work5()
    {
        pb();
        j=i;
        while (str[i]!=';')
            i++;
        print(j,i);
        i++;
        printf("\n");
    }

    ///condtion
    ///前后都可能有空格
    ///中间有可能有多个括号
    void work4()
    {
        printf("%c",c);
        cls();
        j=i;

        i++;
        int g=1;
        while (g!=0)
        {
            if (str[i]=='(')
                g++;
            if (str[i]==')')
                g--;
            i++;
        }
        i--;

        print(j,i),i++;
        cls();
        printf("%c",c);
    }

    ///for while
    void work3()
    {
        pb();
        if (str[i]=='f')
            printf("for"),i+=3;
        else
            printf("while"),i+=5;
        work4();
        work1(str[i]=='{');
    }

    ///if
    void work2()
    {
        pb();
        printf("if"),i+=2;
        work4();
        work1(str[i]=='{');

        ///如果可以没有else: if else 就近原则
        cls();
        if (len-i>=4 && str[i]=='e' && str[i+1]=='l' && str[i+2]=='s' && str[i+3]=='e')
        {
            pb();
            printf("else%c",c),i+=4;
            cls();
            work1(str[i]=='{');
        }
    }

    ///{}
    void work1(int cond)
    {
        cls();
        if (cond==2)
            pb();
        printf("{\n");
        if (cond!=0)
            i++;
        w++;
        while (1)
        {
            cls();
            if (str[i]=='}')
                break;
            cls();
            if (len-i>=1 && str[i]=='{')
                work1(2);
            else if (len-i>=2 && str[i]=='i' && str[i+1]=='f')
                work2();
            else if ((len-i>=3 && str[i]=='f' && str[i+1]=='o' && str[i+2]=='r')
                     ||
                     (len-i>=5 && str[i]=='w' && str[i+1]=='h' && str[i+2]=='i' && str[i+3]=='l' && str[i+4]=='e'))
                work3();
            else
                work5();
            if (cond==0)
                break;
        }
        w--;
        pb();
        printf("}\n");
        cls();
        if (cond!=0)
            i++;
        if (i==len)
            return;
    //    if (str[i]=='{')
    //        print(i,i);
    //    else
    //        error();
    }
}f;


int main()
{
    int j,k;
    fgets(str,maxn,stdin);
    len=strlen(str);

    ///special
    if (str[len-1]=='\n')
        len--,str[len]=0;

    for (i=0;i<len;i++)
        if (str[i]=='{')
            break;

    j=0;
    while (str[j]==' ')
        j++;
    k=i-1;
    while (k>=0 && str[k]==' ')
        k--;
    if (j<=k)
        f.print(j,k);
    printf("\n");
    if (i!=len)
        f.work1(2);
    return 0;
}

///if else
/*
int main(){int i;if (3>2) { i=1; } else {i=2;} }

int main(){int i;if (3>2) if (5>4) i=3; else i=1; else i=2;}

int main(){int i=0; if (3>2) while (i<2) { if (3>2) printf("Y"); else printf("N"); while (i<3) i++;} else i--; return 0;}

int main(){int i=0; if (3>2) i++;else if (3>2) i++;else if (3>2)i++; else i+=2; return 0;}

int main(){ if (3>2) while (3>2) while (4>3) i++; else while (4>3) j--; }
*/

///if ...
/*
int main() {if (3>2) { printf("Y"); } return 0;}

int main() {if (3>2) printf("Y"); return 0;}

int main(){if (3>2) {if (4>3) { if (5>3) {int i=3;}   }}}

int main(){if (3>2)  if (4>3) if (5>3) int i=3;}

int main() {if (3>2) while (3>2) {if (3>2) printf("Y"); if (3>2) printf("Y"); } return 0;}

int main() {  if (3>2) if (4>3) if (6>-2) printf("Y\n");    else if (3>2) printf("Y\n"); else printf("N\n");    return 0; }

int main(){if (3>2)  while(3>2){if (3>2) return 3; else return 2; }else while(3>2){while(5>3) printf("Y");} return 0;}

int main(){if (3>2)  while(3>2)if (3>2) return 3; else return 2; else while(3>2){while(5>3) printf("Y");} return 0;}

int main(){int i=0; if (2<3) {if (3>2) while (i<2) while (i<3) i++; printf("Y"); } return 0; }

int main(){int i=0; if (3>2) i++;else if (3>2) i++;else if (3>2)i++; return 0;}

*/
///while
/*
int main(){while (1>3)  while (3>2) while (5>3) i++; j--; k++;}

int main(){while (1>3) if (3>2) printf("Y\n"); else printf("N"); }

int main(){while (1>3) if (3>2) printf("Y\n"); }


*/
///for
/*
int main()  { for (int i=1;i<=3;i++) for (int j=1;j<=5;j++) k++; }

int main() { for (int i=1;i<=3;i++) while (3>2) if(3>2) printf("Y\n");}

int main() { for (int i=1;i<=3;i++) while (3>2) if(3>2) printf("Y\n");}


*/
///{}
/*
int main() { {int i=2;} if (3>2) if (4>3) else 5>3; else i=1; }

int main(){ { i=3; {i=5;} } }

int main() { if (3>2) i++; {int i=2;} {int i=2;} }

int main() { {int i=2;} { {} } {} }

int main() { {int i=2;} { {i=3; {}} {} } }

int main() {{{{}}}}

int main() {{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{ }}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}
{}
*/
///blank
/*
   int main()  {   return 0;   }
int main(){}

int main()  {    if           (3>2)        i++;    else    j--;    for (i=1;i<=5;i++)              j++;      while          (3>2)    i-;        }

int main()  {    if           (3>2)   {     i++;   }  else   {   j--;  }  for (i=1;i<=5;i++)   {           j++;    }  while          (3>2)   {  i-;   }     }

int main() { if (  3>2   )  i++;  else if (   5>3 &2<3) j--;  for (  i=1;i<=3;i++   )    i--;   while (1>3   )  j--; }

int main() { if ( if (3>2) i++;  ) i++;}
*/
///in addition to "int main() {}"
/*

//仅多个空格

const int maxn=10;

#include <cstdio>

void work1(); void work2();

const int maxn=10; int main() { i=3; }

int work1() { return 1; } int main() { printf("%d",work1()); }

///not need, can't work
int main(){void work1() {i=1; void work2(){ i=2; } }}
*/
