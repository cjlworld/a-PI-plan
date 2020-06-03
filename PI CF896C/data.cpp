#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<iostream>
#define LL long long
#define rint register int
using namespace std;
template<class T>
inline T rm(T x,T y)
{
	return ((T)(long long)rand()/32767ll*(9223372036854775807ll)|(rand()<<5)|rand())%(y-x+1)+x;
}
int main()
{
	srand((unsigned)time(0));
	printf("%d %d %d %d\n",rm(1,100000),rm(1,100000),rm(0,1000000006),rm(1,1000000000));
	return 0;
}

