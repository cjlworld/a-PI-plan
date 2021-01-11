#include<bits/stdc++.h>//还是放上来吧
using namespace std;
const int maxn=5e4+5;
int n,m=2;
struct node{
    int x,y;
}p[maxn],ch[maxn];

inline int read(){//快读
    int x=0,f=1;char a=getchar();
    while(!isdigit(a)) {if(a=='-') f=-1;a=getchar();}
    while(isdigit(a)) {x=(x<<3)+(x<<1)+a-'0';a=getchar();}
    return x*f;
}

int dis(node a,node b){//距离
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

int cross(node p0,node p1,node p2){//叉积
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

bool cmp(node A,node B)//排序（以右手定则来排序）（核心）PS：叉积，以及其右手定则自行度娘
{
	int xx=cross(ch[0],A,B);
	if(xx>0)return true;
	if(xx<0)return false;
	return dis(ch[0],A)<dis(ch[0],B);
}

void TuBao(){
    sort(p+1,p+n,cmp);
    ch[0]=p[0];ch[1]=p[1];
	for(int i=2;i<n;++i){
		while(m>0&&cross(ch[m-1],ch[m],p[i])<=0) m--;
		ch[++m]=p[i];
	}
}

int rotating_calipers(){//旋转卡壳（题解中有讲特判的，其实吧，我觉得没必要，毕竟dis中该怼掉的也会怼掉）
    int j=1,ans=0;
    for(int i=0;i<m;++i){
        while(cross(ch[i],ch[i+1],ch[j])<cross(ch[i],ch[i+1],ch[j+1])) j=(j+1)%m;//这就是栗子，会被一条链卡（qia）死
        ans=max(ans,max(dis(ch[i],ch[j]),dis(ch[i+1],ch[j])));
    }
    return ans;
}

int main(){
    n=read();
    for(int i=0;i<n;++i){
    	p[i].x=read(),p[i].y=read();
    	if(p[i].x<p[0].x||(p[i].x==p[0].x && p[i].y<p[0].y)) swap(p[i],p[0]);//找最左下点
	} 
    TuBao();
    printf("%d",rotating_calipers());
    return 0;
}
