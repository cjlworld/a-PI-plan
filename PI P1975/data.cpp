#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<iostream>
typedef long long LL;
typedef unsigned long long ULL;
using namespace std;
template<class T>
inline T rm(T x,T y)
{
	return ((T)(long long)rand()/32767ll*(9223372036854775807ll)|(rand()<<5)|rand())%(y-x+1)+x;
}
int main()
{
	srand((unsigned)time(0));
	int n,m;
	int x,y;
	int i;
	n=rm(1,5); m=rm(1,5);
	printf("%d\n",n);
	for(i=1;i<=n;i++) 
		printf("%d ",rm(1,10));
	printf("\n%d\n",m);
	while(m--) {
		x=rm(1,n-1);
		y=rm(x+1,n);
		if(rand()&1) 
			swap(x,y);
		printf("%d %d\n",x,y);
	}
	return 0;
}


