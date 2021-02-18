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
	srand(time(0));
	int n=3,m=1;
	printf("%d\n",n);
	for(int i=1;i<=n;i++) 
		printf("%d ",rand()%10+1);
	printf("\n%d\n",m);
	for(int i=1;i<=m;i++) {
		int x=rand()%n+1,y=rand()%n+1;
		if(x>y) swap(x,y);
		int k=rand()%(y-x+1)+1;
		printf("Q %d %d %d\n",x,y,k);	
	}	
	return 0;
}

