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
typedef pair<LL,LL> PLL;
typedef PLL Point;
typedef PLL Vector;

#define x first
#define y second

LL dist(Point a,Point b) 
{
	LL dx=a.x-b.x;
	LL dy=a.y-b.y;
	return dx*dx+dy*dy; 
}
const int N=1e5+5;

int n;
Point a[N];

int main()
{
    int i,j;

    scanf("%d",&n);
    for(i=1;i<=n;i++) 
        scanf("%lld%lld",&a[i].x,&a[i].y);
	
	LL ans=0;
	for(i=1;i<=n;i++) 
		for(j=i+1;j<=n;j++) 
			ans=max(ans,dist(a[i],a[j]));
	
	cout<<ans<<endl;
    return 0;
}
