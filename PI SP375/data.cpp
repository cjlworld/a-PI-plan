#include<set>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<vector>
#include<cstdio>
#include<complex>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
typedef long long LL;

int T;

int main()
{
	srand(time(0));
	int n,m;
	
	T=rand()%20+1;
	printf("%d\n",T);
	while(T--) {
		n=rand()%9999+2;
		printf("%d\n",n);
		for(int i=2;i<=n;i++) {
			int fa=rand()%(i-1)+1;
			printf("%d %d %d\n",fa,i,rand()+1);
		}
		m=rand()%9999+2;
		while(m--) {
			int x=rand()%n+1,y=rand()%n+1;
			if(rand()&1) 
				printf("CHANGE %d %d\n",rand()%(n-1)+1,rand()+1);
			else printf("QUERY %d %d\n",x,y);
		}
		puts("DONE");
	}
	return 0;
}

