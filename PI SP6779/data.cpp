#include<set>
#include<map>
#include<queue>
#include<stack>
#include<ctime>
#include<cmath>
#include<bitset>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

struct dsu
{
	std::vector<int> par;
	int x_,y_;
	dsu(int n) { while((signed)par.size()<n+5) par.push_back(par.size()); }
	int Find(const int &x)
	{
		if(par[x]!=x) return par[x]=Find(par[x]);
		return x;
	}
	inline void Join(const int &x,const int &y)
	{
		x_=Find(x);
		y_=Find(y);
		if(x_==y_) 
			return;
		par[x_]=y_;
		return;
	}
	inline bool Judge(const int &x,const int &y) 
	{
		x_=Find(x); y_=Find(y);
		return (x_==y_);
	}
	inline void clear()
	{
		par.clear();
		x_=y_=0;
		return;
	}
	inline void reset(int n)
	{
		clear();
		while((signed)par.size()<n+5) par.push_back(par.size());
		return;
	}
};
template<class T>
inline T rm(T x,T y)
{
	return ((T)(long long)rand()/32767ll*(9223372036854775807ll)|(rand()<<5)|rand())%(y-x+1)+x;
}
struct data_maker
{
	int x,y,z;
	int i,j;
	void make_tree_without_val(int n)
	{
		dsu *p=new dsu(n);
		srand((unsigned)time(0));
		for(i=1;i<=n-1;i++) {
			x=rm(1,n); y=rm(1,n);
			if(x==y||p->Judge(x,y)) {
				i--;
				continue;
			}
			p->Join(x,y);
			printf("%d %d\n",x,y);
		}
		delete p;
		return;
	} 
};

int n,m;

int main()
{
	srand((unsigned)time(0));
	int i,x,y,z,opt;
	data_maker A;
	n=rm(1,4);
	printf("%d\n",n);
	for(i=1;i<=n;i++) 
		printf("%d ",rm(1,n));
	printf("\n");
	A.make_tree_without_val(n);
	m=rm(1,4);
	printf("%d\n",m);
	for(i=1;i<=m;i++) {
		opt=rm(1,2),x=rm(1,n),y=rm(1,n),z=rm(1,n);
		if(opt==1) printf("1 %d %d\n",x,y);
		else printf("2 %d %d %d\n",x,y,z);
	}
	return 0;
}

