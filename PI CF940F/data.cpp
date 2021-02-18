#include<set>
#include<map>
#include<queue>
#include<stack>
#include<ctime>
#include<cmath>
#include<bitset>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<complex>
#include<iostream>
#include<algorithm>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

inline int rnd()
{
	return 1ll*rand()*rand()%1000000000;
//	return rand()%10;
}

int main()
{
	srand((unsigned) time(0));
	int i;
	int n=rnd()%100000+1,m=rnd()%100000+1;
	printf("%d %d\n",n,m);
	for(i=1;i<=n;i++) 
		printf("%d ",rnd()+1);
	printf("\n");
	
	int x,y,opt;
	for(i=1;i<=m;i++) {
		opt=rand()%2+1;
		if(opt==1) {
			x=rnd()%n+1,y=rnd()%n+1;
			if(x>y) swap(x,y);
		}
		else {
			x=rnd()%n+1; 
			y=rnd()+1;
		}
		printf("%d %d %d\n",opt,x,y);
	}
		
	return 0;
}

