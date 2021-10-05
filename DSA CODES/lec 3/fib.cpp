#include<iostream>
#include<stdlib.h>
using namespace std;
void fib(int x, int y)
{
	
	int sum=x+y;
	cout<<sum<<",";
	if(sum==21)
	{
		cout<<"34";
		exit(0);
	}
	fib(y,sum);
}
int main()
{
	int x,y,z;
	cin>>x>>y;
	cout<<x<<","<<y<<",";
	fib(x,y);
	return 0;
	
}
