#include<iostream>
#include<string.h>
using namespace std;
void sub(string s,string s2,string output)
{
	if(s2.length()==0)
	{
		return;
	}
	if(s.length()==0)
	{
		return;
	}
	sub(s,s2.substr(1),output);
	sub(s.substr(1),s2,output);
		output=output+s[0]+s2[0];
		cout<<output<<endl;
		output="";
}
int main()
{
	string s,s2;
	string output="";
	cin>>s>>s2;
	sub(s,s2,output);
	return 0;
}
