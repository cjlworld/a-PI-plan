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
	return rand()%1000*rand();
}

int main()
{
	srand((unsigned) time(0));
	
	int n=1e5,m=1e5;
	printf("%d %d\n",n,m);
	for(int i=1;i<=n;i++) printf("%d ",rnd());
	printf("\n");
	for(int i=1;i<=m;i++) {
		int x=rnd()%n+1,y=rnd()%n+1;
		if(x>y) swap(x,y);
		printf("%d %d\n",x,y);
	}
	return 0;
}

