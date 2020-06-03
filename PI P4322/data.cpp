#include<bits/stdc++.h>
#define N 10005
using namespace std;
int n,m,opt,x,cnt,num[N];
int write(int x)
{
    if(x<0){putchar('-');x=~(x-1);}
    int s[20],top=0;
    while(x){s[++top]=x%10;x/=10;}
    if(!top)s[++top]=0;
    while(top)putchar(s[top--]+'0');
}
int main()
{
	srand(time(0));
	m=rand()%9+2;n=rand()%(m-1)+1; 
	write(n);  putchar(' ');
	write(m);  putchar('\n');
	for(int i=1;i<=m;i++)
	{
		write(rand()%100+1);putchar(' ');
		write(rand()%100+1);putchar(' ');
		if(i==1) write(0);
		else write(rand()%i);
		putchar('\n');
	}
	return 0;
}
