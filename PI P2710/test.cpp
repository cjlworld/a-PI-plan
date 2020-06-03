#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
using namespace std;
const int inf=2147483647;
int n,m,id,rt;
inline int read(){
    int s=0,w=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')w=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        s=(s<<1)+(s<<3)+(ch^48);
        ch=getchar();
    }
    return s*w;
}
char opt[20];
struct node{
    int ch[2],val,sum,rev;
    int tag,fa,ls,ms,rs,siz;
}tr[500010];
inline void swap(int &x,int &y){x^=y^=x^=y;}
inline void pushup(int x){
    int lc=tr[x].ch[0],rc=tr[x].ch[1];
    tr[x].sum=tr[x].val+tr[lc].sum+tr[rc].sum;
    tr[x].siz=tr[lc].siz+tr[rc].siz+1;
    tr[x].ls=max(tr[lc].ls,tr[lc].sum+tr[x].val+tr[rc].ls);//注意子段和的维护 
    tr[x].rs=max(tr[rc].rs,tr[lc].rs+tr[rc].sum+tr[x].val);//可以自己理解一下，比较难描述 
    tr[x].ms=max(tr[lc].ms,max(tr[rc].ms,tr[lc].rs+tr[x].val+tr[rc].ls));
    //前缀就等于左孩子的前缀 和左孩子的全部加上x的值加上右孩子的前缀的max 
    //后缀就等于右孩子的后缀 和左孩子的后缀加上x的值加上右孩子的全部的max
    //上面的全部即sum
    //那么区间最大子段和就是代码上所说的
    //等于左孩子的最大子段和，右孩子的最大子段和，左孩子后缀加x的值加右孩子前缀的最大值。 
} 
inline void pushdown(int x){
    int lc=tr[x].ch[0],rc=tr[x].ch[1];
    if(tr[x].tag!=-inf){
        int p=tr[x].tag;
        if(lc){
            tr[lc].val=tr[lc].tag=p;
            tr[lc].sum=p*tr[lc].siz;
            if(p>=0)tr[lc].ls=tr[lc].rs=tr[lc].ms=tr[lc].sum;
            else tr[lc].ls=tr[lc].rs=0,tr[lc].ms=p;
        }
        if(rc){
            tr[rc].val=tr[rc].tag=p;
            tr[rc].sum=p*tr[rc].siz;
            if(p>=0)tr[rc].ls=tr[rc].rs=tr[rc].ms=tr[rc].sum;
            else tr[rc].ls=tr[rc].rs=0,tr[rc].ms=p;
        }
        tr[x].tag=-inf,tr[x].rev=0;
    }
    if(tr[x].rev){
        tr[x].rev=0;
        tr[lc].rev^=1;
        tr[rc].rev^=1;
        swap(tr[lc].ls,tr[lc].rs);
        swap(tr[rc].ls,tr[rc].rs);
        swap(tr[lc].ch[0],tr[lc].ch[1]);
        swap(tr[rc].ch[0],tr[rc].ch[1]);
    }
}
inline void rotate(int x){
    int y=tr[x].fa,z=tr[y].fa,k=tr[y].ch[1]==x;
    tr[z].ch[tr[z].ch[1]==y]=x;tr[x].fa=z;
    tr[y].ch[k]=tr[x].ch[k^1];tr[tr[x].ch[k^1]].fa=y;
    tr[x].ch[k^1]=y;tr[y].fa=x;pushup(y);pushup(x);
}
inline void splay(int x,int g){
    while(tr[x].fa!=g){
        int y=tr[x].fa,z=tr[y].fa;
        if(z!=g)
            (tr[y].ch[0]==x)^(tr[z].ch[0]==y)?rotate(x):rotate(y);
        rotate(x);
    }
    if(!g)rt=x;
}
inline int Kth(int x){
    int u=rt;
    if(!x)return 0;
    while(u){
        pushdown(u);
        int y=tr[u].ch[0];
        if(tr[y].siz>=x)u=y;
        else{
            x-=tr[y].siz+1;
            if(!x)return u;
            u=tr[u].ch[1];
        }
    }
    return 0;
}
inline void Ins(int x,int val){
    int F=Kth(x);splay(F,0);
    int p=++id;
    tr[p].siz=1;tr[p].val=tr[p].sum=val;
    tr[p].ms=val;tr[p].rev=0;tr[p].tag=-inf;
    tr[p].fa=F;tr[p].siz=1;
    if(val>=0)tr[p].ls=tr[p].rs=val;
    if(F){
        tr[p].ch[1]=tr[F].ch[1];
        tr[tr[F].ch[1]].fa=p;
        tr[F].ch[1]=p;pushup(p);
        pushup(F);
    }
    splay(p,0);
}
inline void change(int x,int y){
    int L=Kth(x),R=Kth(y+2);
    splay(L,0);splay(R,L);
    int g=tr[R].ch[0];
    if(tr[g].tag==-inf){
        tr[g].rev^=1;
        swap(tr[g].ls,tr[g].rs);
        swap(tr[g].ch[0],tr[g].ch[1]);
    }
    pushup(R);pushup(L);
}
inline int Get(int x,int y){
    int L=Kth(x),R=Kth(y+2);
    splay(L,0);splay(R,L);
    return tr[tr[R].ch[0]].sum;
}
inline void Del(int x,int y){
    int L=Kth(x),R=Kth(y+2);
    splay(L,0);splay(R,L);
    tr[R].ch[0]=0;
    pushup(R);pushup(L);
}
inline void Make(int x,int y,int z){
    int L=Kth(x),R=Kth(y+2);
    splay(L,0);splay(R,L);
    int g=tr[R].ch[0];
    tr[g].val=z;tr[g].tag=z;
    tr[g].sum=tr[g].siz*z;
    if(z>=0)tr[g].ls=tr[g].rs=tr[g].ms=tr[g].sum;
    else tr[g].ls=tr[g].rs=0,tr[g].ms=z;
    pushup(R);pushup(L);
}
inline int Get_pos(int x){
    return tr[Kth(x+1)].val;
}
int main(){
    tr[0].ms=-99999999;
    n=read(),m=read();
    Ins(0,-99999999);
    for(int i=1,x;i<=n;++i){
        scanf("%d",&x);
        Ins(i,x);
    }
    int x,y,l,r,tot;
    Ins(n+1,-99999999);
    while(m--){
        cin>>opt;
        if(opt[0]=='I'){
            x=read(),tot=read();
            for(int i=1;i<=tot;++i){
                x++;
                y=read();
                Ins(x,y);
            }
        }
        else if(opt[0]=='R'){
            l=read(),r=read();
            r=l+r-1;
            change(l,r);
        }
        else if(opt[0]=='G'){
            if(strlen(opt)>4){
                l=read(),r=read();
                r=l+r-1;
                if(r<l){
                    printf("0\n");
                    continue;
                }
                else printf("%d\n",Get(l,r));
            }
            else{
                x=read();
                printf("%d\n",Get_pos(x));
            }
        }
        else if(opt[0]=='D'){
            l=read(),r=read();
            r=l+r-1;
            Del(l,r);
        }
        else if(opt[0]=='M'){
            if(opt[2]=='K'){
                l=read(),r=read(),x=read();
                r=l+r-1;
                Make(l,r,x);
                continue;
            }
            else{
                l=read(),r=read();
                r=l+r-1;
                int L=Kth(l),R=Kth(r+2);
                splay(L,0);splay(R,L);
                cout<<tr[tr[R].ch[0]].ms<<endl;
            }
        }
    }
    return 0;
}
