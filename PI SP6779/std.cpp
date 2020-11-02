#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define mem(a,b) memset(a,b,sizeof (a))
#define ios std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
// ios  can not be used with scanf,printf.  IF  ios MUST cin,cout. 
typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;
const ll mod=1000000007;
const int INF=0x3f3f3f3f;
ll ksm(ll a,ll b){ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

const int N=1e5+10,M=N*2;
int n,m;
int h[N],e[M],ne[M],idx;
int w[N];
int fa[N],son[N],sz[N],dep[N],id[N],nw[N],top[N],cnt;
struct node{
    int l,r;
    int sum,maxsum,lmax,rmax,tag;
}tr[N*4];
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
void dfs1(int u,int father,int depth){
    dep[u]=depth,fa[u]=father,sz[u]=1;
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(j==father)continue;
        dfs1(j,u,depth+1);
        sz[u]+=sz[j];
        if(sz[son[u]]<sz[j])son[u]=j;
    }
}
void dfs2(int u,int t){
    id[u]=++cnt,nw[cnt]=w[u],top[u]=t;
    if(!son[u])return;
    dfs2(son[u],t);
    for(int i=h[u];~i;i=ne[i]){
        int j=e[i];
        if(j==fa[u]||j==son[u])continue;
        dfs2(j,j);
    }
}
void calc(node &u,int k){
    u.sum=k*(u.r-u.l+1);
    if(k>=0) u.lmax=u.rmax=u.maxsum=u.sum;
    else u.lmax=u.rmax=u.maxsum=0;
    u.tag=k;
}
void pushup(node &u,node lson,node rson){
    u.sum=lson.sum+rson.sum;
    u.lmax=max(lson.lmax,lson.sum+rson.lmax);
    u.rmax=max(rson.rmax,rson.sum+lson.rmax);
    u.maxsum=max(lson.rmax+rson.lmax,max(lson.maxsum,rson.maxsum));
}
void pushdown(int u){
    node &root=tr[u],&lson=tr[u<<1],&rson=tr[u<<1|1];
    if(root.tag!=INF){
        calc(lson,root.tag);
        calc(rson,root.tag);
        root.tag=INF;
    }
}
void build(int u,int l,int r){
    tr[u].l=l,tr[u].r=r;
    tr[u].maxsum=tr[u].lmax=tr[u].rmax=max(0,nw[l]);
    tr[u].sum=nw[l];
    tr[u].tag=INF;
    if(l==r)return;
    int mid=l+r>>1;
    build(u<<1,l,mid),build(u<<1|1,mid+1,r);
    pushup(tr[u],tr[u<<1],tr[u<<1|1]);
}
void update(int u,int l,int r,int k){
    if(tr[u].l>=l&&tr[u].r<=r){
        calc(tr[u],k);
        return;
    }
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    if(l<=mid)update(u<<1,l,r,k);
    if(r>mid)update(u<<1|1,l,r,k);
    pushup(tr[u],tr[u<<1],tr[u<<1|1]);
}
node query(int u,int l,int r){
    if(tr[u].l>=l&&tr[u].r<=r){
        return tr[u];
    }
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    if(r<=mid)return query(u<<1,l,r);
    if(l>mid)return query(u<<1|1,l,r);
    node lson=query(u<<1,l,r),rson=query(u<<1|1,l,r),res;
    pushup(res,lson,rson);
    return res;
}
void update_path(int u,int v,int k){
    while(top[u]!=top[v]){
        if(dep[top[u]]<dep[top[v]])swap(u,v);
        update(1,id[top[u]],id[u],k);
        u=fa[top[u]];
    }
    if(dep[u]<dep[v])swap(u,v);
    update(1,id[v],id[u],k);
}
int query_path(int u,int v){
    node ans1,ans2;
    ans1.sum=ans1.maxsum=ans1.lmax=ans1.rmax=0;
    ans2.sum=ans2.maxsum=ans2.lmax=ans2.rmax=0;
    while(top[u]!=top[v]){
        if(dep[top[u]]<dep[top[v]])swap(u,v),swap(ans1,ans2);
        node tmp=query(1,id[top[u]],id[u]);
        pushup(ans1,tmp,ans1);
        u=fa[top[u]];
    }   
    if(dep[u]<dep[v])swap(u,v),swap(ans1,ans2);
    node tmp=query(1,id[v],id[u]);
    swap(ans2.lmax,ans2.rmax);
    pushup(ans2,ans2,tmp);
    pushup(ans1,ans2,ans1);
    return ans1.maxsum;
}
int main(){
    memset(h,-1,sizeof h);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&w[i]);
    for(int i=1;i<=n-1;i++){
        int a,b;scanf("%d%d",&a,&b);
        add(a,b),add(b,a);
    }
    dfs1(1,-1,1);
    dfs2(1,1);
    build(1,1,n);
    scanf("%d",&m);
    while(m--){
        int op,u,v,k;
        scanf("%d%d%d",&op,&u,&v);
        if(op==1)printf("%d\n",query_path(u,v));
        else scanf("%d",&k),update_path(u,v,k);
    }
    return 0;
}
