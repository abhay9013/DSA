#include<iostream>
#include<string>
using namespace std;
int length(char str[])
{
	if(str[0]=='\0')
	{
		return 0;
	}
	int anslength=length(str+1);
	return 1+anslength;
}
char remove(char str[])
{
	if(str[0]=='\0')
	{
		return 0;
	}
	else if(str[0]==str[1])
	{
		int i=1;
		for(;str[i]!='\n';i++)
		{
			str[i-1]=str[i];
		}
		str[i-1]=str[i];
		remove(str);
	}
	else
	{
		remove(str+1);
	}
}
int main()
{
	char str[100];
	cin>>str;
	remove(str);
	cout<<str;
}
