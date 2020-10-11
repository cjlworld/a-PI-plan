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
#include<iostream>
#include<algorithm>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

int main()
{
	srand((unsigned)time(0));
	int n=rand()%10+1,m=rand()%15+1,i,j;
	printf("%d %d\n",n,m);
	for(i=1;i<=n;i++,printf("\n")) 
		for(j=1;j<=m;j++) 
			printf("%d ",rand());
	return 0;
}

