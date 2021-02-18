#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<ctype.h>
#define lc son[x][0]
#define rc son[x][1]
int temp,i,ch;
#define swap(x,y)temp=x,x=y,y=temp;
int max(int x,int y) {
	return x>y?x:y;
}
int fa[20000],son[20000][2],tag[20000],mx[20000],n,T,val[20000];
int nroot(int x) {
	return son[fa[x]][0]==x||son[fa[x]][1]==x;
}
void pushr(int x) {
	tag[x]^=1;
	swap(lc,rc);
}
void pushdown(int x) {
	if(tag[x]) {
		if(lc)pushr(lc);
		if(rc)pushr(rc);
		tag[x]=0;
	}
}
void pushup(int x) {
	mx[x]=max(max(mx[son[x][0]],mx[son[x][1]]),val[x]);
}
void pushall(int x) {
	if(nroot(x))pushall(fa[x]);
	pushdown(x);
}
void rotate(int x) {
	int f=fa[x],witch=son[f][1]==x,ff=fa[f],y=son[x][witch^1];
	if(nroot(f))son[ff][son[ff][1]==f]=x;
	fa[x]=ff;
	son[x][witch^1]=f;
	fa[f]=x;
	son[f][witch]=y;
	if(y)fa[y]=f;
	pushup(f);
	pushup(x);
}
void splay(int x) {
	pushall(x);
	while(nroot(x)) {
		int f=fa[x],ff=fa[f];
		if(nroot(f))rotate((son[f][1]==x)^(son[ff][1]==f)?x:f);
		rotate(x);
	}
}
void access(int x) {
	for(ch=0; x; x=fa[ch=x]) {
		splay(x);
		rc=ch;
		pushup(x);
	}
}
void makeroot(int x) {
	access(x);
	splay(x);
	pushr(x);
}
int findroot(int x) {
	access(x);
	splay(x);
	while(lc)pushdown(x),x=lc;
	splay(x);
	return x;
}
void split(int x,int y) {
	makeroot(x);
	access(y);
	splay(y);
}
void link(int x,int y) {
	makeroot(x);
	if(findroot(y)!=x)fa[x]=y;
}
void cut(int x,int y) {
	makeroot(x);
	if(findroot(y)==x&&fa[y]==x&&!son[y][0]) {
		fa[y]=son[x][1]=0;
		pushup(x);
	}
}
int main() {
	scanf("%d",&T);
	while(T--){
//		std::cerr<<T<<std::endl;
		memset(fa,0,sizeof(fa));
		memset(son,0,sizeof(son));
		memset(tag,0,sizeof(tag));
		memset(mx,0,sizeof(mx));
		memset(val,0,sizeof(val));
		scanf("%d",&n);
		for(i=1; i<n; i++) {
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			val[n+i]=z;
			link(x,n+i);
			link(n+i,y);
		}
		char s[10];
		while(1) {
			scanf("%s",s);
			if(s[0]=='D')break;
			if(s[0]=='C') {
				int x,y;
				scanf("%d%d",&x,&y);
				splay(n+x);
				val[n+x]=y;
			} else {
				int x,y;
				scanf("%d%d",&x,&y);
				split(x,y);
				printf("%d\n",mx[y]);
			}
		}
	}
	return 0;
}
