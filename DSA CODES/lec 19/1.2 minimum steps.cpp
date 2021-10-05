#include<iostream>
#include<limits.h>
using namespace std;

int min(int n)
{
	if(n==1)
	{
		return 0;
	}
	int x=min(n-1);
	int y=INT_MAX,z=INT_MAX;
	if(n%2==0)
	{
		y=min(n/2);
	}
	if(n%3==0)
	{
		z=min(n/3);
	}
	return min(x,min(y,z))+1;
}
int min_1(int n,int* ans)
{
	if(n==1)
	{
		ans[n]=0;
		return 0;
	}
	if(ans[n-1]==-1)
	{
		ans[n-1]=min_1(n-1,ans);
	}
	int y=INT_MAX,z=INT_MAX;
	if(n%2==0)
	{
		if(ans[n/2]==-1)
		{
			ans[n/2]=min_1(n/2,ans);
		}
		y=ans[n/2];
	}
	if(n%3==0)
	{
		if(ans[n/3]==-1)
		{
			ans[n/3]=min_1(n/3,ans);
		}
		z=ans[n/3];
		
	}
	ans[n]=1+min(ans[n-1],min(y,z));
	return ans[n];
}
int min_1(int n)
{
	int* ans=new int[n+1];
	for(int i=0;i<=n;i++)
	{
		ans[i]=-1;
	}
	return min_1(n,ans);
}
int main()
{
	int n;
	cin>>n;
	cout<<min_1(n)<<endl;
	cout<<min(n);
	
	return 0;
}
