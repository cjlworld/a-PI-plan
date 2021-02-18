#include<ctime>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
typedef long long LL;

const int N=2e5+5;

int n,m;

int one[N],idx;
int Next[N],ver[N];
inline void AddEdge(int a,int b)
{
	Next[idx]=one[a]; ver[idx]=b; one[a]=idx++;
	Next[idx]=one[b]; ver[idx]=a; one[b]=idx++;
}

int dep[N],son[N],top[N],fat[N];

void dfs(int x,int fa)
{
	static int siz[N];
	fat[x]=fa;
	dep[x]=dep[fa]+1;
	siz[x]=1;
	for(int i=one[x],y;~i;i=Next[i]) {
		y=ver[i];
		if(y==fa) continue;
		dfs(y,x);
		siz[x]+=siz[y];
		if(siz[y]>siz[son[x]]) 
			son[x]=y;
	}
}

void dfs(int x)
{
	if(son[fat[x]]==x) top[x]=top[fat[x]];
	else top[x]=x;
	for(int i=one[x],y;~i;i=Next[i]) {
		y=ver[i];
		if(y==fat[x]) continue;
		dfs(y);
	} 
}

int lca(int x,int y)
{
	while(top[x]!=top[y]) { 
		if(dep[top[x]]<dep[top[y]]) 
			swap(x,y);
		x=top[x]; x=fat[x];
	}
	if(dep[x]<dep[y]) return x;
	else return y;
}

int dist(int x,int y)
{
	int z=lca(x,y);
	return dep[x]+dep[y]-dep[z]-dep[fat[z]];
}

LL rnd()
{
	return 1ll*rand()*rand();
}

int main()
{
	srand(time(0));
	int i;
	n=rnd()%(100000)+1; m=rnd()%(100000)+1;
	printf("%d %d\n",n,m);
	for(i=1;i<=n;i++) 
		printf("%d ",(int)(rnd()%489375));
	puts("");
	memset(one,-1,sizeof one);
	for(i=2;i<=n;i++) {
		int fa=rnd()%(i-1)+1;
		AddEdge(fa,i);
		printf("%d %d\n",fa,i);
	}
	dfs(1,0); dfs(1);
	
	for(i=1;i<=m;i++) {
		int u=rnd()%n+1,v=rnd()%n+1;
		int w=dist(u,v);
		int k=rnd()%w+1;
		printf("%d %d %d\n",u,v,k);
	}
	return 0;
}

