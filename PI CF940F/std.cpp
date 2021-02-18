#include <cmath>
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

const int maxn = 200005;

int n,m,a[maxn],cnt1,cnt2,ans[maxn],res,vis[maxn],cnt[maxn],num[maxn],pos[maxn],tot,b[maxn],L[maxn],R[maxn],t;

struct Query {
	int l,r,now,id;
	Query() {}
	Query(int L,int R,int N,int I) {l = L,r = R,now = N,id = I;}
}ask[maxn];

struct Maintain {
	int p,c;
	Maintain() {}
	Maintain(int P,int C) {p = P,c = C;}
}up[maxn];

bool cmp(Query x,Query y) {
	if (pos[x.l] ^ pos[y.l]) return x.l < y.l;
	if (pos[x.r] ^ pos[y.r]) return x.r < y.r;
	return x.now < y.now;
}

void Change(int x,int y) {
	if (ask[y].l <= up[x].p && up[x].p <= ask[y].r) {
		cnt[vis[up[x].c]] --;		//×¢ÒâÅ¶
		cnt[++ vis[up[x].c]] ++;
		cnt[vis[a[up[x].p]]] --;
		cnt[-- vis[a[up[x].p]]] ++;
	}
	swap(a[up[x].p],up[x].c);
}

void Add(int x) {
	cnt[vis[a[x]]] --;
	cnt[++ vis[a[x]]] ++;
}

void Sub(int x) {
	cnt[vis[a[x]]] --;
	cnt[-- vis[a[x]]] ++;
}

int op[maxn],x[maxn],y[maxn];

int main () {
	read(n);read(m);
	t = pow(n,0.66666667);
	for (int i = 1 ; i <= n ; ++ i) read(a[i]),b[i] = a[i],pos[i] = i / t;
	tot = n;
	for (int i = 1 ; i <= m ; ++ i) {
		read(op[i]);read(x[i]);read(y[i]);
		if (op[i] == 2) b[++ tot] = y[i];
	}
	sort(b + 1,b + 1 + tot);
	tot = unique(b + 1,b + 1 + tot) - b - 1;
	for (int i = 1 ; i <= n ; ++ i) a[i] = lower_bound(b + 1,b + 1 + tot,a[i]) - b;
	for (int i = 1 ; i <= m ; ++ i) {
		if (op[i] == 2) y[i] = lower_bound(b + 1,b + 1 + tot,y[i]) - b;
		if (op[i] == 1) ++ cnt1,ask[cnt1] = Query(x[i],y[i],cnt2,cnt1);
		if (op[i] == 2) up[++ cnt2] = Maintain(x[i],y[i]);
	}
	sort(ask + 1,ask + 1 + cnt1,cmp);
	int l = 1,r = 0,tm = 0;
	for (int i = 1 ; i <= cnt1 ; ++ i) {
		while (l > ask[i].l) Add(-- l);
		while (r < ask[i].r) Add(++ r);
		while (l < ask[i].l) Sub(l ++);
		while (r > ask[i].r) Sub(r --);
		while (ask[i].now > tm) Change(++ tm,i);
		while (ask[i].now < tm) Change(tm --,i);
		ans[ask[i].id] = 1;
		while (cnt[ans[ask[i].id]]) ans[ask[i].id] ++;
	}
	for (int i = 1 ; i <= cnt1 ; ++ i) print(ans[i]),putchar('\n');
	return 0;
}
