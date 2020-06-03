#include<bits/stdc++.h>
#define rint register int
#define INF 2147483646
using namespace std;
int n,m,q;
int a,b,c;
int main()
{
	srand(time(NULL));
	n=5000;
	m=10000;
	printf("%d %d\n",n,m);
	for(int i=1;i<=m;i++) {
		a=rand()%n+1;
		b=rand()%n+1;
		if(a==b) {
			i--;
			continue;
		}
		c=rand()%9+1;
		printf("%d %d %d\n",a,b,c);
	}
	q=30000;
	printf("%d\n",q);
	for(int i=1;i<=q;i++) {
		a=rand()%n+1;
		b=rand()%n+1;
		if(a==b) {
			i--;
			continue;
		}
		printf("%d %d\n",a,b);
	}
	return 0;
}
