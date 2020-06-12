#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int MOD=20+3;
int m;
int memory[N];
int cnt=0;
int pool=0;
int rm()
{
	int x,y;
	while(true) {
		y=rand()%cnt+1;
		if(memory[y]!=0) {
			x=memory[y];
			break;
		}
	}
	return x;
}
int main()
{
	srand(time(NULL));
	m=rand()%10+1;
	printf("%d\n",m);
	int opt,x,y;
	for(int i=1;i<=m;i++) {
		opt=rand()%6+1;
		if(opt==1||cnt<3||pool<3) {
			x=rand()%MOD+1;
			memory[++cnt]=x;
			pool++;
			opt=1;
		}
		else if(opt==2) {
			while(true) {
				y=rand()%cnt+1;
				if(memory[y]!=0) {
					x=memory[y];
					memory[y]=0;
					break;
				}
			}
			pool--;
		}
		else if(opt==3) {
			x=rm();
		}
		else if(opt==4) {
			x=rand()%pool+1;
		}
		else if(opt==5) {
			x=rm();
		}
		else if(opt==6) {
			x=rm();
		}
		printf("%d %d\n",opt,x);
	}
	return 0;
}

