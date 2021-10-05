#include <iostream>
#include <string.h>
#include <unordered_map>
using namespace std;

int main()
{
	unordered_map<string,int> ourmap;
	
	//insert
	pair<string,int> p("abc",1);
	ourmap.insert(p);
	ourmap["def"]=2;
	
	//find
	cout<<ourmap["abc"]<<endl;
	cout<<ourmap.at("abc")<<endl;
	
	//cout<<ourmap.at("ghi");
	cout<<"size : "<<ourmap.size()<<endl;
	cout<<ourmap["ghi"]<<endl; 
	cout<<"size : "<<ourmap.size()<<endl;
	//we doesnt have inserted that key but
	//when we try to output this it will create itself and assign 0
	
	//check presence
	
	if(ourmap.count("ghi")>0)
	{
		cout<<"Present"<<endl;
	}
	cout<<"size : "<<ourmap.size()<<endl;
	ourmap.erase("ghi");
	if(ourmap.count("ghi")>0)
	{
		cout<<"Present"<<endl;
	}
	cout<<"size : "<<ourmap.size()<<endl;
	
	return 0;
}
