#include <cmath>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

template<typename T>void read(T &x) {
    T f = 1;x = 0;char s = getchar();
    while(s < '0' || s > '9') {if(s == '-')f = -1;s = getchar();}
    while(s >= '0' && s <= '9') {x = x * 10 + s - '0';s = getchar();}
    x *= f;
}
template<typename T>void print(T x) {
    if(x < 0) putchar('-'),x = -x;
    if(x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

const int maxn = 100005;

int nxt[maxn << 1],ver[maxn << 1],head[maxn],tot;
void addEdge(int x,int y) {
	nxt[++ tot] = head[x];ver[tot] = y;head[x] = tot;
}

int l[maxn * 20],r[maxn * 20],val[maxn * 20];
int n,m,a[maxn],b[maxn],dep[maxn],root[maxn],fa[maxn][20],lg[maxn],num,cnt;

int newnode(int k) {
	l[++ cnt] = l[k];
	r[cnt] = r[k];
	val[cnt] = val[k];
	return cnt;
}

int build(int b,int e,int k) {
	k = ++ cnt;
	if (b == e) return k;
	int mid = b + e >> 1;
	l[k] = build(b,mid,l[k]);
	r[k] = build(mid + 1,e,r[k]);
	return k;
}

int update(int b,int e,int k,int x,int y) {
	k = newnode(k);
	if (b == e) val[k] += y;
	else {
		int mid = b + e >> 1;
		if (x <= mid) l[k] = update(b,mid,l[k],x,y);
		else r[k] = update(mid + 1,e,r[k],x,y);
		val[k] = val[l[k]] + val[r[k]];
	}
	return k;
}

int query(int L,int R,int fa,int faa,int b,int e,int k) {
	if (b == e) return b;
	int mid = b + e >> 1;
	int sum = val[l[L]] + val[l[R]] - val[l[fa]] - val[l[faa]];
	return sum >= k ? query(l[L],l[R],l[fa],l[faa],b,mid,k) : query(r[L],r[R],r[fa],r[faa],mid + 1,e,k - sum);
}

void dfs(int u,int faa) {
	fa[u][0] = faa;
	dep[u] = dep[faa] + 1;
	root[u] = update(1,num,root[faa],a[u],1);
	for (int i = 1 ; i <= lg[dep[u]]; ++ i) fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (int i = head[u] ; i ; i = nxt[i]) {
		int v = ver[i];
		if (v == faa) continue;
		dfs(v,u);
	}
}

int LCA(int x, int y) {
	if(dep[x] < dep[y]) {
		int tmp = x;
		x = y;
		y = tmp;
	}
	while(dep[x] > dep[y]) x = fa[x][lg[dep[x] - dep[y]] - 1];
	if(x == y) return x;
	for(int k = lg[dep[x]] - 1; ~k ; --k)
		if(fa[x][k] != fa[y][k])
			x = fa[x][k], y = fa[y][k];
	return fa[x][0];
}

int main () {
	read(n);read(m);
	
	for (int i = 1 ; i <= n ; ++ i) read(a[i]),b[i] = a[i],lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
	sort(b + 1,b + 1 + n);
	num = unique(b + 1,b + 1 + n) - b - 1;
	for (int i = 1 ; i <= n ; ++ i) a[i] = lower_bound(b + 1,b + 1 + num,a[i]) - b;
	
	root[0] = build(1,num,0);
	
	int x,y,k;
	for (int i = 1 ; i < n ; ++ i) {
		read(x);read(y);
		addEdge(x,y);addEdge(y,x);
	}
	
	dfs(1,0);
	
	for (int i = 1 ; i <= m ; ++ i) {
		read(x);read(y);read(k);
		int lca = LCA(x,y);
		print(b[query(root[x],root[y],root[lca],root[fa[lca][0]],1,num,k)]),putchar('\n');
	}
	return 0;
}
