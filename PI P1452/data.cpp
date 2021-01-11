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
	
	int n=10;
	printf("%d\n",n);
	while(n--)
		printf("%d %d\n",rand()%1000,rand()%1000);
	return 0;
}

