#include<windows.h>
#include<bits/stdc++.h>

using namespace std;
typedef long long LL;

const int N=2e4+5;

LL s,t;
int n;
string ns[N];

int main()
{
	// read in 
	printf("How many cpps do you wany to PI? : ");
	scanf("%d",&n);
	printf("names : \n");
	for(int i=1;i<=n;i++) cin>>ns[i];
	
	// task kill
	system("taskkill /f /im data.exe");
	for(int i=1;i<=n;i++)
		system(("taskkill /f /im "+ns[i]+".exe").c_str());
	system("cls");
	
	// begin to PI
    for(LL i=0;;i++) {
		if(i%100==0) system("cls"),printf("AC times %lld\n",i);    
		
		s=clock();
        system("data.exe > data.txt");
        for(int j=1;j<=n;j++)
        	system((ns[j]+".exe < data.txt > "+ns[j]+".txt").c_str());
        	
        printf("#test<%lld>     ",i);
    	
    	bool flag=false;
    	for(int j=1;j<=n;j++) 
    		for(int k=j+1;k<=n;k++) {
    			if(system(("fc "+ns[j]+".txt "+ns[k]+".txt > nul").c_str())) {
    				if(!flag) printf("WA : \n");
    				flag=true;
    				cout<< ns[j] << " and " << ns[k] << " are not the same !\n";
				}
			}
    	
    	t=clock();
    	if(flag) system("pause > nul"); 
        else printf("AC        %lldms\n",t-s);
    }
    return 0;
}

