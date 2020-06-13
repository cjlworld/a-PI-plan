#include<cstdio>
#include<iostream>
#define ll long long
#define N 100050
#define M 1000050
using namespace std;
int n,m,a,b;
int first[N],nxt[M],go[M],tot;
int dfn[N],low[N],size[N],cnt;
bool cut[N];
ll ans[N];
void add(int u,int v)
{
	nxt[++tot]=first[u];first[u]=tot;go[tot]=v;
}
void tarjan(int x,int f)
{
	int son=0,sum=0;
	dfn[x]=low[x]=++cnt; size[x]=1;
	for(int i=first[x];i;i=nxt[i])
	{
		int v=go[i];
		if(!dfn[v])
		{
			son++; tarjan(v,x); size[x]+=size[v];
			low[x]=min(low[x],low[v]);
			if(low[v]>=dfn[x])
			{
				ans[x]+=(ll)size[v]*(n-size[v]);
				sum+=size[v];
				if(f!=x||son>=2) cut[x]=true;
			}
		}
		low[x]=min(low[x],dfn[v]);
	}
	if(!cut[x]) ans[x]=2*(n-1);
	else ans[x]+=(ll)(sum+1)*(n-sum-1)+(n-1);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		add(a,b); add(b,a);	
	} 
	for(int i=1;i<+n;i++)
		if(!dfn[i])
			tarjan(i,i);
	for(int i=1;i<=n;i++) printf("%lld\n",ans[i]);
}

