#include<bits/stdc++.h>
#define LL long long
#define rint register int
using namespace std;
const int N=1e5;
const int M=5e5;
set<int> S[N+5];
template<class T>
inline T rm(T x,T y)
{
	return ((T)(long long)rand()/32767ll*(9223372036854775807ll)|(rand()<<5)|rand())%(y-x+1)+x;
}
int par[N];
int Find(const int &x)
{
	if(par[x]!=x) 
		return par[x]=Find(par[x]);
	else return x;
}
int main()
{
	srand((unsigned)time(0));
	rint i,j;
	int x,y,z;
	int n=rm(3,1000),m=rm(n-1,(n>10000) ? M : min(M,n*(n-1)/2));
	printf("%d %d\n",n,m);
	for(i=1;i<=n;i++) 
		par[i]=i;
	for(i=1;i<=n-1;i++) {
		x=rm(1,n); y=rm(1,n);
		if(x==y||Find(x)==Find(y)) {
			i--;
			continue;
		} 
		par[Find(x)]=Find(y);
		printf("%d %d\n",x,y);
		S[x].insert(y);
		S[y].insert(x);
	}
	for(i=n;i<=m;i++) {
		x=rm(1,n); y=rm(1,n);
		if(x==y||S[x].count(y)||S[y].count(x)) {
			i--;
			continue;
		}
		printf("%d %d\n",x,y);
		S[x].insert(y);
		S[y].insert(x);
	}
	return 0;
}

