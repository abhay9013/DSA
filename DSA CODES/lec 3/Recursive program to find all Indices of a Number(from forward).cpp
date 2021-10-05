#include<bits/stdc++.h>
using namespace std;
int print(int arr[] , int n , int k , int output[])
{
	if(n==0)
	{
		return 0;
	}
	int ans=print(arr+1,n-1,k,output);
	cout<<ans<<endl;
	if(arr[0]==k)
	{
		for(int i=ans-1;i>=0;i--)
		{
			output[i+1]=output[i]+1;
		}
		output[0]=0;
		ans++;
	}
	else 
	{
		for(int i=ans-1;i>=0;i--)
		{
			output[i]=output[i]+1;
		}
	}
	return ans;
}
void print1(int arr[],int n,int k)
{
	int output[n];
	int size=print(arr,n,k,output);
	for(int i=0; i<size;i++)
	{
		cout<<output[i]<<" ";
	}
}
int main()
{
	int arr1[]={5,5,6,5,6};
	int y;
	int n=sizeof(arr1)/sizeof(arr1[0]);
	cin>>y;
	print1(arr1,n,y);
	return 0;
}
