#include<bits/stdc++.h>
using namespace std;
#define reg register
inline int random(int n) { return (rand()%(n+1))*(rand()%(n+1))%(n+1); }
int main() {
    struct timeb timeSeed;
    ftime(&timeSeed);
    srand(timeSeed.time * 1000 + timeSeed.millitm);  // milli time
    int n=5,m=7;
    cout<<n<<" "<<m<<endl;
    for(reg int i=1;i<=n;++i) cout<<random(30)+1<<" ";cout<<endl;
    for(reg int i=1;i<=m;++i) {
        int opt=random(10000)%2;
        if(!opt) printf("R ");
        else printf("Q "); 
        cout<<random(n-1)+1<<" "<<random(n-1)+1<<endl;
    }
} 
