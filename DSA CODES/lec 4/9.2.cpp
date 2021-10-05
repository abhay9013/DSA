#include<iostream>
#include<string.h>
using namespace std;
string dial(int key){
    string m[100];
    m[0]="";
    m[1]="";
    m[2]="abc";
    m[3]="def";
    m[4]="ghi";
    m[5]="jkl";
    m[6]="mno";
    m[7]="pqrs";
    m[8]="tuv";
    m[9]="wxyz";
    return m[key];
}
void sub(int n,string s,string s2,string output)
{
	if(n==0)
	{
		cout<<output<<endl;
		output="";
		return;
	}
	if(s.empty())
	{
		return;
	}
	if(s2.empty())
	{
		return;
	}
	sub(n/10,s,s2.substr(1),output+s2[0]);
	sub(n%10,s.substr(1),s2,output+s[0]);
}
void sub1(int n,string output)
{
	string s=dial(n%10);
	cout<<s<<endl;
	string s2=dial(n/10);
	cout<<s2<<endl;
	sub(n,s,s2,output);
}
int main()
{
	int n;
	string output;
	cin>>n;
	sub1(n,output);
	return 0;
}
