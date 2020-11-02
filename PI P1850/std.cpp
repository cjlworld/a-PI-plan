#include<cstdio>
#include<cstring>
#define INF 0x3f3f3f
#define minn(a,b) (a)<(b)?(a):(b)
#define li for(i=1;i<=n;++i)
int n,m,e,v;
int w[301][301];
int c[2001],d[2001];
double k[2001],save[2001][2001][2];
template<typename T>
inline void read(T &x){
  char ch;while((ch=getchar()),(ch>'9'||ch<'0'));
  x=ch-'0';while((ch=getchar()),(ch>='0'&&ch<='9')) x=x*10+ch-'0';
}
double dp(int i,int m,bool s)
{
    if(i==1) return 0;
    if(save[i][m][s]) return save[i][m][s];
    double p1,p2;
    double &u=save[i][m][s];
    if(s==0) {
        p2=w[c[i-1]][c[i]];
        p1=(1-k[i-1])*w[c[i-1]][c[i]]+k[i-1]*w[d[i-1]][c[i]];
        if(m==0) return u=p2+dp(i-1,0,0);
        else return u=minn(p1+dp(i-1,m-1,1),p2+dp(i-1,m,0));
    }
    else { 
        p2=(1-k[i])*w[c[i-1]][c[i]]+k[i]*w[c[i-1]][d[i]];
        p1=(1-k[i-1])*(1-k[i])*w[c[i-1]][c[i]]+
            k[i-1]*(1-k[i])*w[d[i-1]][c[i]]+
                (1-k[i-1])*k[i]*w[c[i-1]][d[i]]+
                    k[i-1]*k[i]*w[d[i-1]][d[i]];
        if(m==0) return u=p2+dp(i-1,0,0);            
        else return u=minn(p1+dp(i-1,m-1,1),p2+dp(i-1,m,0));
    }
}
int main(){
    read(n),read(m),read(v),read(e);
    register int i,a,b,t;
    li read(c[i]);
    li read(d[i]);
    li scanf("%lf",&k[i]);
    memset(w,INF,sizeof w);
    for(i=1;i<=e;++i){
        read(a),read(b),read(t);
        if(a==b) continue;
        if(w[a][b]==INF) w[a][b]=w[b][a]=t;
        else w[a][b]=w[b][a]=minn(w[a][b],t);
    }
    for(int t=1;t<=v;++t)
        for(a=1;a<=v;++a)
            for(b=1;b<=v;++b)
                w[a][b]=minn(w[a][b],w[a][t]+w[t][b]);
    for(int t=1;t<=v;++t) w[t][t]=0;
//    for(int i=1;i<=v;i++,printf("\n")) 
//    	for(int j=1;j<=v;j++) 
//    		printf("%d ",w[i][j]);
    double ans=dp(n,m,0);
    if(m!=0) ans=minn(ans,dp(n,m-1,1));
    printf("%.2lf",ans);
}
