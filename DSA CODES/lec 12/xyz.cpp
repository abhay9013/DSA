#include<iostream>
using namespace std;
class binarytreenode{
	public:
		int data;
		binarytreenode* left;
		binarytreenode* right;
		
		binarytreenode(int data)
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
binarytreenode* input()
{
	int rdata;
	cout<<"Enter data "<<endl;
	cin>>rdata;
	if(rdata==-1)
	{
		return NULL;
	}
	binarytreenode* root=new binarytreenode(rdata);
	binarytreenode* leftchild= input();
	binarytreenode* rightchild= input();
	root->left=leftchild;
	root->right=rightchild;
	return root;
}
/*template <typename t>
void print(binarytreenode<t>* root)
{
	if(root==NULL)
	{
		return;
	}
	cout<<root->data<<":";
	if(root->left!=NULL)
	{
		cout<<"L"<<root->left->data;
	}
	
	if(root->right)
	{
		cout<<"R"<<root->right->data;
	}
	cout<<endl;
	print(root->left);
	print(root->right);
}*/
int main()
{
	binarytreenode* root=input();
	//print(root);
	delete root;
	return 0;
}
