#include<iostream>
#include <string.h>
using namespace std;
#include <stack>
int main()
{
	stack<string> s1;
	string s;
	cin>>s;
	cout<<s<<endl;
	for(int i=0;s[i]!='\0';i++)
	{
		if(s[i]=='{'||s[i]=='('||s[i]=='[')
		{
			string s4=s[i];
			s1.push(s4);
		}
		else if(s[i]=='}'||s[i]==')'||s[i]==']')
		{
			string s2=s1.top();
			string s3=s[i];
			if((strcmp(s2,s3))==0)
			{
				cout<<"hii"<<endl;
				s1.pop();
			}
		}
		
	}
	cout<<s1.size();
}
