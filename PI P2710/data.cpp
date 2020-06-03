#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<iostream>
#define LL long long
using namespace std;
int n,m;
int main()
{
	srand(time(0));
	n=rand()%10000+1;
	m=rand()%10000+1;
	printf("%d %d\n",n,m);
	int i,j;
	int x,y,z;
	int opt;
	int len=n;
	for(i=1;i<=n;i++) {
		z=rand()%1001;
		if(rand()&1) z=-z;
		printf("%d ",z);
	}	
	printf("\n");
	for(i=1;i<=m;i++) {
		opt=rand()%7+1;
		if(len==0) opt=1;
		switch(opt) {
			case 1 : {
				x=rand()%(len+1);
				y=rand()%((200000-len+100000001)%(rand()%1000+1)+1)+1;
				printf("INSERT %d %d ",x,y);
				for(j=1;j<=y;j++) {
					z=rand()%1001;
					if(rand()&1)
						z=-z;
					printf("%d ",z);
				}
				len+=y;
				break;
			}
			case 2 : {
				y=rand()%(len)+1;
				x=rand()%(len-y+1)+1;
				printf("DELETE %d %d",x,y);
				len-=y;
				break;
			}
			case 3 : {
				y=rand()%len+1;
				x=rand()%(len-y+1)+1;
				printf("REVERSE %d %d",x,y);
				break;
			}
			case 4 : {
				y=rand()%len+1;
				x=rand()%(len-y+1)+1;
				z=rand();
				printf("MAKE-SAME %d %d %d",x,y,z);
				break;
			}
			case 5 : {
				y=rand()%len+1;
				x=rand()%(len-y+1)+1;
				printf("GET-SUM %d %d",x,y);
				break;
			}
			case 6 : {
				x=rand()%len+1;
				printf("GET %d",x);
				break;
			}
			case 7 : {
				y=rand()%len+1;
				x=rand()%(len-y+1)+1;
				printf("MAX-SUM %d %d",x,y);
				break;
			}
		}
		printf("\n");
	}
	return 0;
}

