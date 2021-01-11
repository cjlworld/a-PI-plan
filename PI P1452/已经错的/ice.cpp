#include<bits/stdc++.h>

#define int long long

using namespace std;

struct node{
	int x,y;
}p[200200],s[200200];

int n,size;

inline int cmp(node a,node b)
{
	double k1,k2;
	k1=atan2((a.y-p[1].y),(a.x-p[1].x));
	k2=atan2((b.y-p[1].y),(b.x-p[1].x));
	if(k1==k2) return a.x<b.x;
	return k1<k2;
}

inline int getdis(node a,node b)
{
	return 1ll*(a.x-b.x)*(a.x-b.x)+1ll*(a.y-b.y)*(a.y-b.y);
}

inline int getcj(node a,node b,node c)
{
	return 1ll*(b.x-a.x)*(c.y-a.y)-1ll*(b.y-a.y)*(c.x-a.x);
}

inline int bj(node a,node b)
{
	return (a.y>b.y||(a.y==b.y)&&(a.x>b.x));
}

inline void gettb()  //这一部分的代码注释最好在我的凸包讲解那里看（不过我还是复制粘贴了过来） 
{
	p[0].x=p[0].y=0x3f3f3f3f;
	register int i,j;
	for(i=1;i<=n;i++) if(bj(p[0],p[i])) p[0]=p[i],j=i;  //找到最小边的点，并且把他放到第一位 
	swap(p[j],p[1]);
	sort(p+2,p+n+1,cmp); //对后面的点极点排序 
	s[++size]=p[1]; s[++size]=p[2];//让前两个点入栈（他们一定是在凸包上） 
	for(i=3;i<=n;)
	{
		if(size>=2&&getcj(s[size-1],p[i],s[size])>=0) size--; //就是上面说的 (这里的上图在凸包的那里) 
		else s[++size]=p[i++];
	}
	s[0]=s[size]; //记得凸包要首尾相连 
}

inline int getmmx()
{
	int ans=0;
	if(size==2) return getdis(s[0],s[1]);  //只有两个点的时候不能构成三角形，所以要特判 
	int j=2;
	for(int i=0;i<size;i++) 
	{
		while(getcj(s[i],s[i+1],s[j])<getcj(s[i],s[i+1],s[j+1])) j=(j+1)%size;  //实际上这也是在找面积，由于面积只有一个顶点，所以下一个j变小的时候就退出 
		ans=max(ans,max(getdis(s[i],s[j]),getdis(s[i+1],s[j]))); //找到距离最远的一条线段，并且与当前最大值比较 
	}
	return ans;  //最后就是直径了 
}

signed main()
{
	ios::sync_with_stdio(false);
	register int i,j;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>p[i].x>>p[i].y;
	}
	gettb();
	cout<<getmmx()<<endl;
	return 0;
}
