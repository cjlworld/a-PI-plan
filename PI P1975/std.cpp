#include<iostream>
#include<cstdio>
using namespace std;
int i,n,q,h[100002],o[100002],p[100002],ans,a,b;
int gb(int x,int y){
    int mid=(x+y)/2,j=x,k=mid+1,l=x;
    if(x==y) return 0;
    gb(x,mid);
    gb(k,y);
    while(j<=mid&&k<=y){
        if(o[j]<=o[k]){
            p[l]=o[j];
            j++;
            l++;
        }
        else{
            p[l]=o[k];
            ans+=mid-j+1;
            k++;
            l++;
        }
    }
    while(j<=mid){
        p[l]=o[j];
        j++;
        l++;
    }
    while(k<=y){
        p[l]=o[k];
        k++;
        l++;
    }
    for(i=x;i<=y;i++)
        o[i]=p[i];
    return 0;
}
int main()
{
    int j,k,l;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&h[i]);
    for(i=1;i<=n;i++)
        o[i]=h[i];
    gb(1,n);
    printf("%d\n",ans);
    scanf("%d",&q);
    for(i=1;i<=q;i++){
        scanf("%d%d",&a,&b);
        if(a>b){
            j=a;
            a=b;
            b=j;
        }
        if(h[b]>h[a])
            ans++;
        else if(h[b]<h[a])
            ans--;
        for(j=a+1;j<=b-1;j++){
            if(h[j]>h[a])
                ans++;
            else if(h[j]<h[a])
                ans--;
            if(h[j]<h[b])
                ans++;
            else if(h[j]>h[b])
                ans--;
        }
        j=h[a];
        h[a]=h[b];
        h[b]=j;
        printf("%d\n",ans);
    }
    return 0;
}
