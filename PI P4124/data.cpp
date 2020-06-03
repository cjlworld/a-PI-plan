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
	LL x=rm(10000000000ll,99999999999ll),y=rm(x,99999999999ll);
	printf("%lld %lld\n",x,y);
	return 0;
}

