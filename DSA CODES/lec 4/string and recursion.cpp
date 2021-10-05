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
char removeX(char str[])
{
	if(str[0]=='\0')
	{
		return 0;
	}
	else if(str[0]!='x')
	{
		removeX(str+1);
	}
	else
	{
		int j;
		for(int i=0;str[i]!='\n';i++)
		{
			str[i-1]=str[i];
			j=i;
		}
		str[j-1]=str[j];
		removeX(str);
	}
}
int main()
{
	char str[100];
	cin>>str;
	int l=length(str);
	cout<<l<<endl;
	char str2=removeX(str);
	cout<<str;
}
