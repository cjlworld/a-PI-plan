#include<bits/stdc++.h>
#define F(x,y,z) for (int x=y;x<=z;++x)
#define ll long long
using namespace std;
int head[1000005],v[1000005],k,b[1000005],dfn[1000005],low[1000005],t,tot,rt;
struct edg
{
	int to,ne;
}e[2000005];
void add(int x,int y)
{
	e[++tot].to=y;e[tot].ne=head[x];head[x]=tot;
}
void dfs(int rot,int a)
{
	v[a]=1;
	dfn[a]=++t;
	low[a]=t;
	int tp=0;
	for (int j=head[a];j;j=e[j].ne)
		{
			int p=e[j].to;
			if (!v[p])
				{
					if (a==rot)
					    rt++;
					dfs(rot,p);
					low[a]=min(low[a],low[p]);
					if (low[p]>=dfn[a] && a!=rot && !tp)
						{
							b[++k]=a;tp=1;
						}
				}
			else
				{
					low[a]=min(low[a],dfn[p]);//!!!!!!!!!!!!!!!!
				}
		}
	if (rt>=2 && a==rot)
	    b[++k]=rot;
	return;
}
int main()
{
	int x,y,n,m;
	scanf("%d%d",&n,&m);
	F(i,1,m)
		{
			scanf("%d%d",&x,&y);
			add(x,y);add(y,x);
		} 
	F(i,1,n)
		{
			if (!v[i])
				{
					rt=0;t=0;dfs(i,i);
				}
		}
	sort(b+1,b+k+1);
	printf("%d\n",k);
	F(i,1,k)
		printf("%d ",b[i]); 
	return 0;
}

