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
	int x=rand(),y=rand();
	if(x>y) swap(x,y);
	printf("1\n%d %d\n",x,y);
	return 0;
}

