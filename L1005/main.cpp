#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>              ///good for lots of modifying, search log log
#include <unordered_map>    ///good for just search. search log
#include <iostream>
using namespace std;

const int maxn=1e3+10;

///O(nlogn+mlogn) roughly

unordered_map<int,pair<string,int> > f;
//map<int,pair<string,int> > f;
/*
D:\Software\CodeBlocks\MinGW\lib\gcc\mingw32\4.9.2\include\c++\bits\c++0x_warning.h|32|error: #error This file requires compiler and library support for the ISO C++ 2011 standard. This support is currently experimental, and must be enabled with the -std=c++11 or -std=gnu++11 compiler options.|
Setting->Compiler->C++11 ISO
*/

int main()
{
	int n,q,b,c;
	string a;
	scanf("%ld",&n);
	while (n--)
	{
		cin>>a>>b>>c;
		f[b]=make_pair(a,c);
	}
	scanf("%d",&q);
	while (q--)
	{
		scanf("%d",&b);
		cout<<f[b].first<<" "<<f[b].second<<endl;
	}
	return 0;
}
