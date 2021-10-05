#include<iostream>
#include <vector>
using namespace std;
int main()
{
	//vector<int> *v2=new vector<int>(); dynamically allocated
	vector<int>  v;
	v.push_back( 10);
	v.push_back(20);
	v.push_back(30);

	v[1]=100;
	//v[3]=1002; don't do this , only  use to ouput or print
	v.push_back(40);
	v.push_back(50);
	
	//fro deleting
	v.pop_back();
	
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<endl;
	}
	
	/*cout<<v[0]<<endl;
	cout<<v[1]<<endl;
	cout<<v[2]<<endl;
	cout<<v[3]<<endl;
	cout<<v[4]<<endl;
	cout<<v[5]<<endl;
	cout<<v.size()<<endl;
	cout<<v.at(2)<<endl;*/
}
