#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<iostream>
typedef long long LL;
typedef unsigned long long ULL;
using namespace std;
int main()
{
	srand((unsigned)time(0));
	int n=rand()%10+1;
	printf("%d\n",n);
	for(int i=1;i<=n;i++) 
		printf("%d\n",rand()%8+1);
	return 0;
}

