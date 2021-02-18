#include<ctime>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

int main()
{
	srand(time(0));
	int T=2000;
	printf("%d\n",T);
	while(T--) {
		ULL x=1ull*rand()*rand()%19260817ull*rand()%998244353ull*rand()*rand()*rand();
		x%=((ULL)(1e18-2)+2);
		printf("%llu\n",x);
	}
//	int T=1e5;
//	printf("%d\n",T);
//	for(int i=2;i<=T+1;i++) 
//		printf("%d\n",i);
 	return 0;
}

