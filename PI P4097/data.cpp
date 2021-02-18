#include<cmath>
#include<ctime>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
typedef long long LL;

const int M=29989;

int main()
{
	srand(time(0));
	int n=rand()%M+1;
	printf("%d\n",n);
	for(int i=1;i<=n-1;i++) 
		printf("1 %d %d %d %d\n",rand()%M+1,rand()%M+1,rand()%M+1,rand()%M+1);
	printf("0 %d\n",rand()%10+1);
	return 0;
}

