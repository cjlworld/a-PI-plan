#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<iostream>
#define LL long long
#define rint register int
using namespace std;
template<class T>
inline T rm(T x,T y)
{
	return ((T)(long long)rand()/32767ll*(9223372036854775807ll)|(rand()<<5)|rand())%(y-x+1)+x;
}
int n,m;
int main()
{
	srand((unsigned)time(0));
	rint i;
	int x,y;
	printf("1\n");
	n=rm(1,5); m=rm(1,5);
	printf("%d\n",n);
	for(i=1;i<=n;i++) 
		printf("%d ",rm(-5,5));
	printf("\n%d\n",m);
	for(i=1;i<=m;i++) {
		x=rm(1,n); y=rm(x,n);
		printf("%d %d ",x,y);
		x=rm(x,n); y=rm(y,n);
		printf("%d %d\n",x,y);
	}
	return 0;
}

