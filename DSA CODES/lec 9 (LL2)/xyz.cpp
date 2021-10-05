/*#include<iostream>
using namespace std;
int main()
{
	char a[]="hello";
	char b[]="hello";
	cout<<a<<endl;
	cout<<b<<endl;
	if(a==b)
	{
		cout<<"hii";
	}
	else
	{
		cout<<"bye";
	}
	return 0;
}*/
#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	char a[]="hello";
	char b[]="hello";
	cout<<a<<endl;
	cout<<b<<endl;
	if((strcmp(a,b))==0)
	{
		cout<<"hii";
	}
	else
	{
		cout<<"bye";
	}
	return 0;
}
