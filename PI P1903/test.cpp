#include<bits/stdc++.h>
using namespace std;
#define reg register
int a[1000000],vis[1000000];
char s[5];
int main() {
   // freopen("sj.txt","r",stdin),freopen("s.out","w",stdout);
    int n,m,x,y;
    cin>>n>>m;
    for(reg int i=1;i<=n;++i) cin>>a[i];
    for(reg int i=1;i<=m;++i) {
        scanf("%s",s);
        cin>>x>>y;
        if(s[0]=='R') a[x]=y;
        else {
            if(x>y) swap(x,y);
            memset(vis,0,sizeof(vis));int ans=0;
            for(reg int j=x;j<=y;++j) vis[a[j]]==0?vis[a[j]]=1,++ans:++vis[a[j]];
            printf("%d\n",ans);
        }
    } 
}

