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
typedef multiset<int>::iterator mit;

multiset<int> S;

inline unsigned rnd()
{
	return (unsigned)rand()*rand()*rand();
}

mit rm(int l,int r)
{
	int lit=rnd()%(r-l+1)+l;
	mit it;
	int i;
	for(i=0,it=S.begin();it!=S.end();it++) {
		i++;
		if(i==lit)
			return it;
	}
	return S.end();
}

int n;

int main()
{
	srand((unsigned) time(0));
	int i;
	int opt,x;
	mit it;
	
	n=5;
	printf("%d\n",n);
	for(i=1;i<=n;i++) {
		opt=rnd()%6+1;
		if(opt==1||S.size()<3||S.count(*S.begin())==S.size()) {
			x=rnd()%n+1;
			S.insert(x);
			opt=1;
		}
		else if(opt==2) {
			it=rm(1,S.size());
			x=*it;
			S.erase(it);
		}
		else if(opt==3) x=rnd()%n+1;
		else if(opt==4) x=rnd()%S.size()+1;
		else if(opt==5) x=*rm(S.count(*S.begin())+1,S.size());
		else if(opt==6) x=*rm(1,S.size()-S.count(*(--S.end())));
		
		printf("%d %d\n",opt,x);
	}
	return 0;
}

