#include<iostream>
#include<stdio.h>
using namespace std;
int findindex(int arr[] , int n , int k , int arr2[])
{
	if(n<0)
	{
		return -1;
	}
	if(arr[n]==k)
	{
		return n;
	}
	int ans = findindex(arr,n-1,k,arr2);
	if(ans==-1)
	{
		return -1;
	}
}
int main()
{
	int arr[]={5,5,6,5,6};
	int arr2[6];
	int x;
	cin>>x;
	int y= findindex(arr,4,x,arr2);
	cout<<y;
	return 0;
}
