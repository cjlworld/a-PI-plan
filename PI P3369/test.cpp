#include<bits/stdc++.h>
#define INF 2147483646
using namespace std;
const int N = 1e6+5;
const double alpha = 0.75;
const double elpha = 0.3;
struct node
{
	int lc,rc;
	int val;
	int cnt;
	int size,fact;
	#define lc(x) tzy[x].lc
	#define rc(x) tzy[x].rc 
	#define c(x) tzy[x].cnt 
	#define s(x) tzy[x].size 
	#define f(x) tzy[x].fact 
	#define v(x) tzy[x].val
};
node tzy[N];
int pool,root;
vector<int> tmp;
void newnode(int &k,const int &key)
{
	k=++pool;
	v(k)=key;
	lc(k)=rc(k)=0;
	c(k)=s(k)=f(k)=1;
	return;
}
bool balance(const int &k)
{
	if(max(s(lc(k)),s(rc(k)))>s(k)*alpha||s(k)-f(k)>s(k)*elpha)
		return false;
	return true; 
}
void ldr(const int &k)
{
	if(!k) return;
	ldr(lc(k));
	if(c(k)) 
		tmp.push_back(k);
	ldr(rc(k));
	return;
}
void lift(int l,int r,int &k)
{
	if(l==r) {
		k=tmp[l];
		s(k)=f(k)=c(k); //????
		lc(k)=rc(k)=0;
		return;
	}
	int mid=(l+r)>>1;
	k=tmp[mid];
	if(l<mid) lift(l,mid-1,lc(k));
	else lc(k)=0;
	lift(mid+1,r,rc(k));
	s(k)=s(lc(k))+s(rc(k))+c(k);
	f(k)=f(lc(k))+f(rc(k))+c(k);
	return;
}
void rebuild(int &k)
{
	tmp.clear();
	ldr(k);
	if(tmp.empty()) { k=0; return; }
	lift(0,tmp.size()-1,k);
	return;
}
void update(const int &k,const int &end)
{
	if(k==end) return;
	if(v(end)<v(k)) 
		update(lc(k),end);
	else update(rc(k),end);
	s(k)=s(lc(k))+s(rc(k))+c(k);
	return;
}
void check(int &k,const int &end)
{
	if(k==end) return;
	if(!balance(k)) {
		rebuild(k);
		update(root,k);
		return;
	}
	if(v(end)<v(k)) check(lc(k),end);
	else check(rc(k),end);
	return;
}
void insert(int &k,const int &key)
{
	if(!k) {
		newnode(k,key);
		check(root,k);
		return;
	}
	++s(k); ++f(k);
	if(v(k)==key) ++c(k);
	else if(key<v(k)) 
		insert(lc(k),key);
	else insert(rc(k),key);
	return;
}
void erase(int &k,const int &key)
{
	if(v(k)==key&&c(k)) {
		--f(k); --c(k);
		check(root,k);
		return;
	}
	--f(k);
	if(key<v(k)) erase(lc(k),key);
	else erase(rc(k),key);
	return;
}
inline int getnum(int rank) 
{
	int x=root;
	while(x) {
		if(c(x)>0&&f(lc(x))<rank&&f(lc(x))+c(x)>=rank) 
			return v(x);
		if(f(lc(x))>=rank) x=lc(x);
		else rank-=f(lc(x))+c(x),x=rc(x);
	}
	return 0;
}
inline int getrank(const int &key)
{
	int x=root,res=0;
	while(x) {
		if(key==v(x)) return res+f(lc(x))+1;
		if(key<v(x)) x=lc(x);
		else res+=f(lc(x))+c(x),x=rc(x);
	}
	return res;
}
inline int find(const int &key)
{
	int now=root;
	while(now) {
		if(v(now)==key) return now;
		if(key<v(now)) now=lc(now);
		else now=rc(now);
	}
	return 0;
}
inline int Query_pre(int now,const int &key)
{
	if(!now) return -INF;
	int res=-INF;
	if(c(now)) {
		if(v(now)<key) 
			res=max(v(now),Query_pre(rc(now),key));
		else 
			res=Query_pre(lc(now),key);
	}
	else 
		res=max(Query_pre(lc(now),key),Query_pre(rc(now),key));
	return res;
}
inline int Query_suf(int now,const int &key) 
{
	if(!now) return INF;
	int res=INF;
	if(c(now)) {
		if(v(now)>key) 
			res=min(v(now),Query_suf(lc(now),key));
		else 
			res=Query_suf(rc(now),key);
	}
	else 
		res=min(Query_suf(lc(now),key),Query_suf(rc(now),key));
	return res;
}
int n;
/*
1、插入 x 数；
2、删除 x 数（若有多个相同的数，因只删除一个）；
3、查询 x 数的排名（若有多个相同的数，因输出最小的排名）；
4、查询排名为 x 的数；
5、求 x 的前趋（前趋定义为小于 x，且最大的数）；
6、求 x 的后继（后继定义为大于 x，且最小的数）。
*/
int main()
{
//	freopen("P3369_1.in","r",stdin);
	scanf("%d",&n);
	int opt,x;
	for(int i=1;i<=n;i++) {
		scanf("%d%d",&opt,&x);
		switch(opt) {
			case 1 : insert(root,x); break;
			case 2 : erase(root,x); break;
			case 3 : printf("%d\n",getrank(x)); break;
			case 4 : printf("%d\n",getnum(x)); break;
			case 5 : printf("%d\n",Query_pre(root,x)); break;
			case 6 : printf("%d\n",Query_suf(root,x)); break; 
		}
	}
//	getchar();
	return 0;
}
