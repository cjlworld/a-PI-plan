#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<cctype>
#include<cstdio>
#include<list>
using namespace std;
char buf[(int)3e7],*ss=buf;
inline int init(){buf[fread(buf,1,(int)3e7-1,stdin)]='\n';fclose(stdin);return 0;}
const int __START__=init();
inline int readint(){
    int d=0;
    while(!isdigit(*ss))++ss;
    while(isdigit(*ss))d=d*10+(*ss++^'0');
    return d;
}
const int siz=300,blocks=235;
#define bel(x)((x-1)/siz+1)
list<int>s[300];
typedef list<int>::iterator iter;
int pre[70500][300],prb[300][300],m,ans,L[300],R[300],n,tot[70500],tob[300];
int sta[666],top=0;
inline int modify(list<int>&l,int x,int v){
	iter it=l.begin();
	while(x--)++it;
	const int ret=*it;
	*it=v;
	return ret;
}
void get(list<int>&l,int x,int s){
	iter it=l.begin();
	while(x--)++it;
	while(s--)++tot[sta[++top]=*it],++tob[bel(*it)],++it;
}
int main(){
	n=readint();
	for(int i=1;i<=blocks;++i)L[i]=R[i-1]+1,R[i]=i*siz;
	for(int i=1;i<=n;++i){
		int x=readint()+1;
		const int id=bel(i);
		s[id].push_back(x);
		int*P=pre[x],*B=prb[bel(x)];
		for(int j=id;j<=blocks;++j)++P[j],++B[j];
	}
	for(m=readint()^ans;m--;){
		while(isspace(*ss))++ss;
		switch(*ss){
			case'Q':{
				int l=readint()^ans,r=readint()^ans,k=readint()^ans;
				top=0;
				const int bL=bel(l),bR=bel(r);
				if(bL==bR){
					get(s[bL],l-L[bL],r-l+1);
					for(int i=1;;++i)
					if(k>tob[i])k-=tob[i];else{
						for(int j=L[i];;++j)
						if(k>tot[j])k-=tot[j];else{ans=j;break;}
						break;
					}
				}else{
					get(s[bL],l-L[bL],R[bL]-l+1),get(s[bR],0,r-L[bR]+1);
					for(int i=1;;++i)
					if(k>tob[i]+prb[i][bR-1]-prb[i][bL])k-=tob[i]+prb[i][bR-1]-prb[i][bL];else{
						for(int j=L[i];;++j)
						if(k>tot[j]+pre[j][bR-1]-pre[j][bL])k-=tot[j]+pre[j][bR-1]-pre[j][bL];else{ans=j;break;}
						break;
					}
				}
				printf("%d\n",--ans);
				for(int i=0;i<=top;++i)tot[sta[i]]=tob[bel(sta[i])]=0;
				break;
			}
			case'M':{
				int x=readint()^ans,v=readint()^ans;
				++v;
				const int id=bel(x);
				int old=modify(s[id],x-L[id],v);
				int*Po=pre[old],*Pn=pre[v],*Bo=prb[bel(old)],*Bn=prb[bel(v)];
				for(int i=id;i<=blocks;++i)
				--Po[i],--Bo[i],++Pn[i],++Bn[i];
				break;
			}
			case'I':{
				int x=readint()^ans,v=readint()^ans;
				++v;
				const int id=bel(x);
				iter it=s[id].begin();
				for(int i=x-L[id];i--;)++it;
				s[id].insert(it,v);
				int*P=pre[v],*B=prb[bel(v)];
				for(int i=id;i<=blocks;++i)++P[i],++B[i];
				for(int i=id+1;i<=blocks;++i)
				if(s[i-1].size()<=siz)break;else{
					int vl=s[i-1].back();
					--pre[vl][i-1],--prb[bel(vl)][i-1];
					s[i-1].pop_back();
					s[i].push_front(vl);
				}
				break;
			}
		}
	}
	return 0;
}
