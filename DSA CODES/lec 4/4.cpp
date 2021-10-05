#include<iostream>
using namespace std;
int main()
{
	int arr[]={4,7,9,1,2,6,3};
	int si=0;
	int size=sizeof(arr)/sizeof(arr[0]);
	int ei=size-1;cout<<ei<<endl;
	cout<<"hey 1"<<endl;
	qs(arr,si,ei);
	for(int y=0;y<size;y++)
	{
		cout<<arr[y]<<",";
	}
	return 0;
}
int partition(int arr[],int si, int ei)
{
	int count=0;
	int b=si;
	int	s=arr[b];
	while(si<=ei)
	{
		cout<<"check 1"<<endl;
		if(arr[si]<s)
		{
			count++;
			cout<<count<<endl;
		}
		si++;
	}
	arr[b]=arr[b+count];
	arr[b+count]=s;
	int i=b;
	int j=ei;
	int t=b+count;
	int p=arr[b];
	while(i<t&&j>t)
	{
		if(arr[i]<p)
		{
			i++;
		}
		else if(arr[j]>p)
		{
			j--;
		}
		else
		{
			int h=arr[i];
			arr[i]=arr[j];
			arr[j]=h;
		}
	}
	return count;
}
void qs(int arr[],int si,int ei)
{
	cout<<"hey 2"<<endl;
	if(sizeof(arr)==0||sizeof(arr)==1)
	{
		return;
	}
	cout<<"hey 3"<<endl;
	int c=partition(arr,si,ei);
	
	cout<<c<<endl;
	qs(arr,si,c);
	qs(arr,c+1,ei);
}

