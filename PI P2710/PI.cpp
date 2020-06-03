#include<bits/stdc++.h>
#include<windows.h>
#define LL long long
using namespace std;
LL s,t;
int sum;
int main()
{
	system("cls");
	system("taskkill /f /im data.exe");
	system("taskkill /f /im std.exe");
	system("taskkill /f /im test.exe");
	bool sign=false;
	if(system("data.exe > data.txt")) printf("error : data not found\n"),sign=true;
	if(system("std.exe < data.txt > nul")) printf("error : std not found\n"),sign=true;
	if(system("test.exe < data.txt > nul")) printf("error : test not found\n"),sign=true;
	system("taskkill /f /im data.exe");
	system("taskkill /f /im std.exe");
	system("taskkill /f /im test.exe");
	system("cls");
	if(sign) {
		printf("\nplease try again!\n");
		system("pause > nul");
		return 0;;
	}
    for(LL i=1;i>0;i++) {
		if(i%100==0) system("cls"),printf("AC times %lld\n",i);      
        system("data.exe > data.txt");
        s=clock();
        system("std.exe < data.txt > std.txt");
        t=clock();
        system("test.exe < data.txt > test.txt");
        printf("#test<%lld>     ",i);
        if(system("fc std.txt test.txt > nul")) {
        	printf("WA        %lldms\n",t-s);
        	system("fc std.txt test.txt");
        	system("pause > nul");
		}
        else if(t-s>1000) {
            printf("TLE       %lldms\n",t-s);
            system("pause > nul");
		}
        else printf("AC        %lldms\n",t-s);
    }
    return 0;
}

