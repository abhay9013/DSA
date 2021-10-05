#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;

int main()
{
	unordered_map<string,int> ourmap;
	ourmap["abc"]=1;
	ourmap["abc1"]=2;
	ourmap["abc2"]=3;
	ourmap["abc3"]=4;
	ourmap["abc4"]=5;
	
	unordered_map<string,int>::iterator it=ourmap.begin();
	while(it!=ourmap.end())
	{
		cout<<"key : "<<it->first<<" value : "<<it->second<<endl;
		it++; 
	}
	//fin
	// ourmap.find("abc"); this will give iterator
	unordered_map<string,int> op1=ourmap.find("abc2");
	ourmap.erase(op1,op1+3)
	
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	vector<int>::iterator it1=v.begin();
	while(it1!=v.end())
	{
		cout<<*it1<<" ";
		it1++;
	}
	
	return 0;	
}
