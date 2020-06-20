#include<cstdio>
#include<algorithm>
#include<cstring>
#define ls (u<<1)
#define rs (u<<1|1)
#define mid ((l+r)>>1)
using namespace std;

const int maxn=10005;
int t,n,q,lx,ly,rx,ry,ans;
int a[maxn];

struct Node{
    int ml,mr,mz,sum;
    Node(){
        ml=mr=mz=sum=0;
    }
    Node operator +(const Node &x)const{
        Node ans;
        ans.ml=max(ml,sum+x.ml);
        ans.mr=max(x.mr,x.sum+mr);
        ans.sum=sum+x.sum;
        ans.mz=max(mr+x.ml,max(mz,x.mz));
        return ans;
    }
}tree[maxn<<2];

void build(int u,int l,int r){
    if(l==r){
        tree[u].ml=tree[u].mr=tree[u].mz=tree[u].sum=a[l];
        return ;
    }
    build(ls,l,mid);
    build(rs,mid+1,r);
    tree[u]=tree[ls]+tree[rs];
    return ;
}

Node query(int u,int l,int r,int ql,int qr){
    if(ql>qr){
        Node a;
        return a;
    } 
    if(ql<=l&&qr>=r)
        return tree[u];
    if(qr<=mid)
        return query(ls,l,mid,ql,qr);
    if(ql>mid)
        return query(rs,mid+1,r,ql,qr);
    Node t1,t2;
	t1=query(ls,l,mid,ql,qr), t2=query(rs,mid+1,r,ql,qr);
    return t1+t2;
}

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
            scanf("%d",&a[i]);
        memset(tree,0,sizeof(tree));
        build(1,1,n);
        scanf("%d",&q);
        while(q--){
            scanf("%d%d%d%d",&lx,&ly,&rx,&ry);
            if(ly==rx-1)
                printf("%d\n",query(1,1,n,lx,ly).mr+query(1,1,n,rx,ry).ml);
            else if(ly==rx)
                printf("%d\n",max(query(1,1,n,lx,ly).mr+query(1,1,n,rx+1,ry).ml,query(1,1,n,lx,ly).mr));
            else if(rx>ly){
                Node t1=query(1,1,n,lx,ly), t2=query(1,1,n,ly+1,rx-1), t3=query(1,1,n,rx,ry);
                printf("%d\n",t1.mr+t2.sum+t3.ml);
            }
            else if(lx==rx&&ly==ry)
                printf("%d\n",query(1,1,n,lx,ly).mz);
            else if(lx==rx)
                printf("%d\n",max(query(1,1,n,lx,ly).mz,query(1,1,n,lx,ly).mr+query(1,1,n,ly+1,ry).ml));
            else if(ly==ry)
                printf("%d\n",max(query(1,1,n,rx,ry).mz,query(1,1,n,lx,rx-1).mr+query(1,1,n,rx,ry).ml));
            else{
				Node t1=query(1,1,n,lx,rx-1), t2=query(1,1,n,rx,ly), t3=query(1,1,n,ly+1,ry);
                ans=max(t1.mr+t2.ml,t1.mr+t2.sum+t3.ml);
                ans=max(ans,max(t2.mz,t2.mr+t3.ml));
                printf("%d\n",ans);
            }  
        }
    }
    return 0;
}
