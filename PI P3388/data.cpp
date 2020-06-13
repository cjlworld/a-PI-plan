#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<iostream>
#define LL long long
#define rint register int
using namespace std;
int main()
{
	srand((unsigned)time(0));
	int i,j;
	int n,m;
	int x,y,z;
	n=rand()%5+1; m=rand()%min(10,n*n)+1;
	printf("%d %d\n",n,m);
	for(i=1;i<=m;i++) 
		printf("%d %d\n",rand()%n+1,rand()%n+1);
	return 0;
}

