#include<iostream>
#include<string.h>
using namespace std;
void sub(string s,string output)
{
	if(s.length()==0 )
	{
		cout<<output<<endl;
		return;
	}
	sub(s.substr(1),output);
	sub(s.substr(1),output+s[0]);
}
int main()
{
	string s;
	string output="";
	cin>>s;
	sub(s,output);
	return 0;
}
