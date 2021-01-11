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

void rndstr(int len)
{
	for(int i=1;i<=len;i++) 
		putchar('a'+rand()%25);
	putchar('\n');
}

int main()
{
	srand((unsigned) time(0));
	int n=5;
	printf("%d\n",n);
	for(int i=1;i<=n;i++) rndstr(5);
	rndstr(10);
	return 0;
}

