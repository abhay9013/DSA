#include<iostream>
#include<string.h>
using namespace std;
int sub(string s,string output[])
{
	if(s.empty())
	{
		output[0]=" ";
		return 1;
	}
	string smallstring=s.substr(1);
	int n=sub(smallstring,output);
	for(int i=0;i<n;i++)
	{
		output[i+n]=s[0]+output[i];
	}
	return 2*n;
}
int main()
{
	string s;
	cin>>s;
	string*output=new string[1000];
	int count = sub(s,output);
	for(int i=0;i<count;i++)
	{
		cout<<output[i]<<endl;
	}
	return 0;
}
