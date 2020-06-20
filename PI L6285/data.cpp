#include<bits/stdc++.h>
#define LL long long
#define rint register int
using namespace std;
int n;
int main()
{
	srand((unsigned)time(0));
	rint i;
	int x,y;
	n=rand()%10+1;
	printf("%d\n",n);
	for(i=1;i<=n;i++) 
		printf("%d ",rand()%10);
	printf("\n");
	for(i=1;i<=n;i++) {
		x=rand()%n+1;
		y=rand()%n+1;
		if(x>y) 
			swap(x,y);
		printf("%d %d\n",x,y);
	}
	return 0;
}

