#include<iostream>
using namespace std;
int fib(int n)
{
	if(n==0)
	{
		return 0;
	}
	if(n==1)
	{
		return 1;
	}
	int sop=fib(n-1);
	int sop2=fib(n-2);
	return sop+sop2;
}
int main()
{
	int n;
	cin>>n;
	cout<<fib(n);
	return 0;
}
