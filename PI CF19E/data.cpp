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
	srand((unsigned) time(0));
	int n=5,m=7;
	printf("%d %d\n",n,m);
	for(int i=1;i<=m;i++) {
		int x=rand()%n+1,y=rand()%n+1;
		printf("%d %d\n",x,y);
	}
	return 0;
}

