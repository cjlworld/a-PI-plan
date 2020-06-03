#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,m;
const int N=10000+5;
int par[N];
int Find(int x)
{
	if(par[x]!=x) return par[x]=Find(par[x]);
	return x;
}
void Join(int x,int y)
{
	int x_=Find(x);
	int y_=Find(y);
	if(x_==y_) 
		return;
	par[x_]=y_;
	return;
}
int main()
{
	srand(time(0));
	int i,j;
	int x,y,z,opt;
	n=5; m=7;
	printf("%d %d\n",n,m);
	for(i=1;i<=n;i++) 
		par[i]=i;
	for(i=1;i<=n;i++) 
		printf("%d ",rand()%5);
	printf("\n");
	for(i=1;i<=n-1;i++) {
		x=rand()%n+1;
		y=rand()%n+1;
		if(Find(x)==Find(y)) {
			i--;
			continue;
		}
		Join(x,y);
		printf("%d %d\n",x,y);
	}
	for(i=1;i<=m;i++) {
		opt=rand()%3+1;
		x=rand()%n+1;
		printf("%d %d ",opt,x);
		if(opt==1||opt==2) {
			z=rand()%10+1;
			printf("%d",z);
		}
		printf("\n");
	}
	return 0;
}

