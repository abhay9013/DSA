#include<iostream>
#include<string.h>
using namespace std;
int sub(string s1,string s2,string output[])
{
	if(s1.empty())
	{
		return 1;
	}
	string smallstring=s1.substr(1);
	cout<<s1+s2<<endl;
	int count=sub(smallstring,s2,output);
	cout<<count<<endl;
	for(int i=0;i<s2.size();i++)
	{
		int k=count-1;
		cout<<s2[i]<<endl;
		cout<<s1[0]<<endl;
		output[i+k]=s1[0]+s2[i];
		
	}
	return count*3;
}
int main()
{
	string s1,s2;
	cout<<"enter the 2 strings."<<endl;
	cin>>s1;
	cin>>s2;
	string*output=new string[1000];
	output="";
	int n=sub(s1,s2,output);
	n=n-9;
	for(int i=0;i<n;i++)
	{
		cout<<output[i]<<endl;
	}
	
}
