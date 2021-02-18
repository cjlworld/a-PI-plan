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
#include<complex>
#include<iostream>
#include<algorithm>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

int main()
{
	while(true) {
		system("data.exe > data.txt");
		LL s=clock();
		system("test.exe < data.txt > test.txt");
		LL t=clock();
		printf("%lld ms\n",t-s);
	}
	return 0;
}

