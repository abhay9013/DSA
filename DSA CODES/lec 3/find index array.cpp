#include<iostream>
using namespace std;
int findindex(int arr[] , int n , int k)
{
	if(n<0)
	{
		return -1;
	}
	if(arr[0]==k)
	{
		return 0;
	}
	
	int ans = findindex(arr+1,n-1,k);
	if(ans==-1)
	{
		return -1;
	}
	else 
	{
		return ans+1;
	} 
}
int main()
{
	int arr[]={5,9,6,4,3};
	int x;
	cin>>x;
	int y= findindex(arr,4,x);
	cout<<y;
	return 0;
}
