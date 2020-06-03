#include<cstdio>
#include<iostream>
#define LL long long
#define rint register int
using namespace std;
int dim[24];
inline bool check(LL x)
{
	rint top=0;
	bool ex8=false,ex4=false;
	while(x>0) {
		dim[++top]=x%10;
		x=x/10;
		if(dim[top]==4) ex4=true;
		if(dim[top]==8) ex8=true;
	}
	if(ex4&&ex8) return false;
	for(rint i=1;i<=top-2;i++) 
		if(dim[i]==dim[i+1]&&dim[i+1]==dim[i+2]) 
			return true;
	return false;
}
int main()
{
//	freopen("1.in","r",stdin);
	LL a,b;
	LL ans=0;
	cin>>a>>b;
	for(register LL i=a;i<=b;i++) {
		if(check(i)) {
//			cout<<i<<endl;
			ans++;
		}
	}
//	cout<<"ans:"<<ans<<endl;
	cout<<ans<<endl;
	return 0;
}

