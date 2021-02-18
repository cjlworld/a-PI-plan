#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>

using namespace std;

string randstring(int len)
{
	string s;
	for(int i=0;i<len;i++) {
		char c=rand()%5+'a';
		s=s+c;
	}
	return s;
}

int main()
{
	srand(time(0));
	int n=2;
	printf("%d\n",n);
	for(int i=1;i<=n;i++)
		cout<<randstring(rand()%4+1)<<endl;
	cout<<randstring(7)<<endl;
	puts("0");
	return 0;
}

