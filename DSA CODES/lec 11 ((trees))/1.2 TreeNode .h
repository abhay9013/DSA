#include<iostream>
#include<vector>
using namespace std;
template <typename t>
class treenode{
	t data;
	vector<treenode*> child; // or vector<treenode<t>*> child
	treenode(int data)
	{
		this->data=data;
	}
	
};
