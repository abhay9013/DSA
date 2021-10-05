#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> removeduplicate(int* a,int size)
{
	vector<int> op;
	unordered_map<int,bool> n;
	for(int i=0;i<size;i++)
	{
		if(n.count(a[i])>0)
		{
			continue;
		}
		else 
		{
			n[a[i]]=true;
			op.push_back(a[i]);
		}
	}
	return op;
}
int main()
{
	int arr[]={1,2,3,4,1,2,3,7,8,5,4,2};
	vector<int> op=removeduplicate(arr,12);
	for(int i=0;i<op.size();i++)
	{
		cout<<op[i]<<endl;
	}
}
