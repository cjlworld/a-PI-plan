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

int n,m,e,v;
int rnd(int l,int r) { return rand()%(r-l+1)+l; }
int main()
{
	srand((unsigned)time(0));
	int i;
	n=rnd(1,3),m=rnd(1,3),v=rnd(1,3),e=rnd(v-1,5);
	printf("%d %d %d %d\n",n,m,v,e);
	for(i=1;i<=n;i++)
		printf("%d ",rnd(1,v));
	printf("\n");
	for(i=1;i<=n;i++) 
		printf("%d ",rnd(1,v));
	printf("\n");
	for(i=1;i<=n;i++) 
		printf("%.1lf ",rand()*1.0/32767.0);
	printf("\n");
	for(i=1;i<=v-1;i++) 
		printf("%d %d %d\n",i,i+1,rnd(1,5));
	for(i=v;i<=e;i++) 
		printf("%d %d %d\n",rnd(1,v),rnd(1,v),rnd(1,5));
		
	return 0;
}

