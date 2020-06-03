#include<ctime>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<iostream>
//#include"makedata.cpp"
#define LL long long
#define rint register int
using namespace std;
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
	return (((T)(long long)rand()/32767ll*(9223372036854775807ll))|(rand()<<5)|(rand()<<3)|rand())%(y-x+1)+x;
}
void make_tree_without_val(int n)
{
	int x,y;
	dsu *p=new dsu(n);
	srand((unsigned)time(0));
	for(int i=1;i<=n-1;i++) {
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
int main()
{
	srand((unsigned)time(0));
	int n,m;
	int x,y,z;
	int i,j;
	n=rm(1,5); m=rm(1,5);
	printf("%d %d\n",n,m);
	for(i=1;i<=n;i++) 
		printf("%d ",rm(1,5));
	printf("\n");
	make_tree_without_val(n);
	for(i=1;i<=m;i++) {
		x=rand()&1;
		if(x==1)
			printf("C %d %d %d\n",rm(1,n),rm(1,n),rm(1,5));
		else printf("Q %d %d\n",rm(1,n),rm(1,n));
	}
	return 0;
}

