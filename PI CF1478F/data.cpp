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

int main()
{
	freopen("data.txt","w",stdout);
	srand((unsigned) time(0));
//	int n=rand()%5000+1;
	int n=5000;
	printf("%d\n",n);
	for(int i=1;i<=n;i++) 
		printf("%lld %lld\n",rand(),rand());
	return 0;
}

