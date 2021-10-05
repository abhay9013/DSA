#include<iostream>
using namespace std;
int main()
{
	string s;
	s="abc";
	string s2;
	s2="def";
	string s3=s+s2;
	cout<<s+s2;
	cout<<s.size();
	cout<<endl<<s.substr(1,2);
	cout<<s3.find("cd");
	return 0;
}
