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

const int N=1e3+5;
int a[N];
int n,m;

int get()
{
	int x;
	for(x=rand()%(n*m)+1;!a[x];x=rand()%(n*m)+1);
	return x;
}
void put()
{
	int x=get()-1;
	printf("%d %d ",x/m+1,x%m+1);
//	printf("%d\n",get());
}
int main()
{
	srand((unsigned)time(0));
	int i;
	n=3,m=3;
	printf("%d %d 1\n",n,m);
	a[1]=a[2]=a[3]=a[4]=1;
	for(i=5;i<=n*m;i++) 
		a[i]=rand()&1;
	random_shuffle(a+1,a+n*m+1);
	for(i=1;i<=n*m;i++) {
		printf("%d ",a[i]);
		if(i%m==0) printf("\n");
	}
	put(),put(),put(),printf("\n");
	return 0;
}

