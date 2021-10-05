#include<iostream>
using namespace std;
int print(int arr[] , int n , int  k , int arr2[])
{
	if(n<0)
	{
		return 0;
	}
	int ans = print(arr,n-1,k,arr2);
	if(arr[n]==k)
	{
		arr2[ans]=n;
		ans++;
	}
	return ans;
	
}
int main()
{
	int arr[]={5,5,6,5,6};
	int x;
	cin>>x;
	int arr2[6];
	int size=print(arr,5,x,arr2);
	size=size-1;
	for(int i=0;i<=size;i++)
	{
		cout<<arr2[i]<<" ";
	}
	return 0;
}
