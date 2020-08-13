#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<iostream>
#define LL long long
#define rint register int
using namespace std;
int n,m;
template<class T>
inline T rm(T x,T y)
{
	return ((T)(long long)rand()/32767ll*(9223372036854775807ll)|(rand()<<5)|rand())%(y-x+1)+x;
}
const int N=2000+5;
int par[N];
int Find(int x)
{
	if(x!=par[x]) return par[x]=Find(par[x]);
	return x;
}
void Join(int x,int y)
{
	int x_=Find(x);
	int y_=Find(y);
	if(x_==y_) return;
	par[x_]=y_;
	return;
}
int main()
{
	srand((unsigned)time(0));
	n=rm(2,5); m=rm(1,5);
	int x,y,z;
	printf("%d\n%d\n",n,m);
	for(rint i=1;i<=2*n;i++)
		par[i]=i;
	for(rint i=1;i<=m;i++) {
		z=rm(0,1);
		x=rm(1,n-1);
		y=rm(x+1,n);
		if(rm(0,1)) swap(x,y);
		
		if(z==0&&Find(x+n)!=Find(y)) {
			printf("F %d %d\n",x,y);
			Join(x,y);
		}
		else if(z==1&&Find(x)!=Find(y)) {
			printf("E %d %d\n",x,y);
			Join(x+n,y);
			Join(x,y+n);
		}	
		else {
			i--;
			continue;
		}
	}
	return 0;
}

