#include<cstdio>
#include<iostream>
#include<cstring>
#define rint register int
#define N 2501
#define M -4000000
#define Eps 1e-4
#define mymin(x,y) (((x)<(y))?(x):(y))
#define mymax(x,y) (((x)>(y))?(x):(y))
using namespace std;
int n,m,a,b,c;
int first[N],next[N],go[N],w[N],v[N],tot;
double l,r,mid,ans,f[N][N];
inline void add(int u,int v)
{
	next[++tot]=first[u];first[u]=tot;go[tot]=v;
}
inline int read()
{
	char c=getchar();
	int num=0;
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){num=num*10+c-'0',c=getchar();}
	return num;	
} 
inline void input()
{
	m=read(),n=read();
	for(rint i=1;i<=n;++i)
		w[i]=read(),v[i]=read(),c=read(),add(c,i);
}
int dp(int x,int fa)
{
	f[x][0]=0;
	f[x][1]=v[x]*1.0-w[x]*1.0*mid;
	int sum=1,t=0;
	for(rint i=first[x];i;i=next[i])
	{
		int son=go[i];
		if(son==fa) continue; 
		t=dp(son,x); sum+=t;
		for(rint j=mymin(sum,m+1);j>=1;--j)
			for(rint k=0;k<=mymin(t,j-1);++k)
				f[x][j]=mymax(f[x][j],f[x][j-k]+f[son][k]);
	}
	return sum;
}
bool check(double mid)
{
	for(rint i=0;i<=n;++i)
		for(rint j=0;j<=n;++j) 
			f[i][j]=M;
	dp(0,-1);
	return f[0][m+1]>=0;
}
void binary()
{
	l=0,r=10000;
	while((r-l)>Eps)
	{
		mid=(l+r)*0.5;
		if(check(mid))ans=l=mid;
		else r=mid;
	}
}
void print()
{
	printf("%.3lf",ans);
}
int main()
{
	input();
	binary();
	print();
	return 0;	
} 
