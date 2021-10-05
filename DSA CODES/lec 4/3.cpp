#include<iostream>
using namespace std;
void merge(int arr[],int si,int ei)
{
	if(si>=ei)
	{
		return ;
	}
	int j=si+1;
	while(j<=ei)
	{
		if(arr[si]>arr[j])
		{
			int y=arr[si];
			arr[si]=arr[j];
			arr[j]=y;
		}
		j++;
	}
	merge(arr,si+1,ei);
}
void mergesort(int arr[],int n)
{
	if (n==0||n==1)
	{
		return;
	}
	int arr2[10];
	int ei=n-1;;
	int mid=(0+ei)/2;
	merge(arr,0,mid);
	merge(arr,mid+1,ei);
	int g=0;
	int mid1=mid;
	for(int i=0;i<n;i++)
	{
		if(arr[g]>arr[mid+1]&&g<=mid1)
		{
			arr2[i]=arr[mid+1];
			mid++;
		}
		else if(g<=mid1)
		{
			arr2[i]=arr[g];
			g++;
		}
		else 
		{
			arr2[i]=arr[mid+1];
		}
	}
	for(int r=0;r<n;r++)
	{
		arr[r]=arr2[r];
	}
}
int main()
{
	int arr[]={2,3,5,1,9,7,8,6,4,10};
	int size= sizeof(arr)/sizeof(arr[0]);
	cout<<"array before sorting"<<endl;
	for(int j=0;j<size;j++)
	{
		cout<<arr[j]<<",";
	}
	cout<<endl;
	mergesort(arr,size);
	cout<<"array after sorting"<<endl;
	for(int f=0;f<size;f++)
	{
		cout<<arr[f]<<",";
	}
	return 0;
}
