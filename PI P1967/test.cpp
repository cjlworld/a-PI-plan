#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define LL long long
using namespace std;
const int N=1e4+5;
int one[N];
int Next[10*N],ver[10*N],edge[10*N];
int tot=0;
inline void AddEdge(int a,int b,int c)
{
	tot++;
	Next[tot]=one[a];
	one[a]=tot;
	ver[tot]=b;
	edge[tot]=c;
	return;
}
struct quiz
{
	int u,v;
	int ans;
	int o;
}an[3*N];
inline bool cmp(const quiz &a,const quiz &b)
{
	if(a.u!=b.u) 
		return a.u<b.u;
	else return a.v<b.v;
}
inline bool rule(const quiz &a,const quiz &b)
{
	return a.o<b.o;
}
int n,m,q;
int dis[N];
bool vis[N];
queue<int> Q;
inline void spfa(int st)
{
	memset(dis,-1,sizeof dis);
	memset(vis,0,sizeof vis);
	while(Q.size()) Q.pop();
	int i,j;
	int x,y,z;
	Q.push(st);
	dis[st]=0x3f3f3f3f;
	vis[st]=true;
	while(Q.size()) {
		x=Q.front(); Q.pop();
		vis[x]=false;
		for(i=one[x];i>0;i=Next[i]) {
			y=ver[i]; z=edge[i];
			if(dis[y]<min(dis[x],z)) {
				dis[y]=min(dis[x],z);
				if(!vis[y]) {
					Q.push(y);
					vis[y]=true;
				}
			}
		}
	}
	return;
}
int main()
{
	int i,j;
	int x,y,z;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++) {
		scanf("%d%d%d",&x,&y,&z);
		AddEdge(x,y,z);
		AddEdge(y,x,z);
	}
	scanf("%d",&q);
	for(i=1;i<=q;i++) {
		scanf("%d%d",&an[i].u,&an[i].v);
		if(an[i].u>an[i].v) 
			swap(an[i].u,an[i].v);
		an[i].o=i;
	}
	sort(an+1,an+q+1,cmp);
	int ago=-1;
	for(i=1;i<=q;i++) {
		if(an[i].u!=ago) 
			spfa(an[i].u),ago=an[i].u;
		an[i].ans=dis[an[i].v];
	}
	sort(an+1,an+q+1,rule);
	for(i=1;i<=q;i++) 
		printf("%d\n",an[i].ans);
	return 0;
}
