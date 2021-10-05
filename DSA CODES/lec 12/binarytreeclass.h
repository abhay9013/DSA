#include<iostream>
using namespace std;
template <typename t>
class binarytreenode{
	public:
		t data;
		binarytreenode* left;
		binarytreenode* right;
		
		binarytreenode(t data)
		{
			this->data=data;
			left=NULL;
			right=NULL;
		}
		~binarytreenode()
		{
			delete left;
			delete right;
		}
};

