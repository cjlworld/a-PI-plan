#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=300000+5;
int par[N];
int n,m;
int Find(int x)
{
	if(par[x]!=x) return par[x]=Find(par[x]);
	return x;
}
inline void Join(int x,int y)
{
	int x_=Find(x);
	int y_=Find(y);
	if(x_==y_) 
		return;
	par[x_]=y_;
	return;
}
LL random()
{
	return rand()|(rand()<<15);
}
int main()
{
	srand(time(0));
	int i;
	int x,y;
	int z;
	n=random()%50000+2; m=random()%50000+1;
	printf("%d %d\n",n,m);
	for(i=1;i<=n;i++) 
		par[i]=i;
	for(i=1;i<=n-1;i++) {
		x=random()%n+1;
		y=random()%n+1;
		if(Find(x)==Find(y)) {
			i--;
			continue;
		}
		Join(x,y);
		z=rand()%10000+1;
		printf("%d %d %d\n",x,y,z);
	}
	for(i=1;i<=m;i++) {
		x=random()%n+1;
		y=random()%n+1;
		printf("%d %d\n",x,y);
	}
	return 0;
}

