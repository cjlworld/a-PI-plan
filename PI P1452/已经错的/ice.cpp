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

inline void gettb()  //��һ���ֵĴ���ע��������ҵ�͹���������￴�������һ��Ǹ���ճ���˹����� 
{
	p[0].x=p[0].y=0x3f3f3f3f;
	register int i,j;
	for(i=1;i<=n;i++) if(bj(p[0],p[i])) p[0]=p[i],j=i;  //�ҵ���С�ߵĵ㣬���Ұ����ŵ���һλ 
	swap(p[j],p[1]);
	sort(p+2,p+n+1,cmp); //�Ժ���ĵ㼫������ 
	s[++size]=p[1]; s[++size]=p[2];//��ǰ��������ջ������һ������͹���ϣ� 
	for(i=3;i<=n;)
	{
		if(size>=2&&getcj(s[size-1],p[i],s[size])>=0) size--; //��������˵�� (�������ͼ��͹��������) 
		else s[++size]=p[i++];
	}
	s[0]=s[size]; //�ǵ�͹��Ҫ��β���� 
}

inline int getmmx()
{
	int ans=0;
	if(size==2) return getdis(s[0],s[1]);  //ֻ���������ʱ���ܹ��������Σ�����Ҫ���� 
	int j=2;
	for(int i=0;i<size;i++) 
	{
		while(getcj(s[i],s[i+1],s[j])<getcj(s[i],s[i+1],s[j+1])) j=(j+1)%size;  //ʵ������Ҳ������������������ֻ��һ�����㣬������һ��j��С��ʱ����˳� 
		ans=max(ans,max(getdis(s[i],s[j]),getdis(s[i+1],s[j]))); //�ҵ�������Զ��һ���߶Σ������뵱ǰ���ֵ�Ƚ� 
	}
	return ans;  //������ֱ���� 
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
