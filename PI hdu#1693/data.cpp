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
	srand((unsigned) time(0));
	printf("1\n");
	int n=2,m=4;
	printf("%d %d\n",n,m);
	for(int i=1;i<=n;i++,printf("\n"))
		for(int j=1;j<=m;j++) 
			printf("%d ",rand()%5>0);
		
	return 0;
}

