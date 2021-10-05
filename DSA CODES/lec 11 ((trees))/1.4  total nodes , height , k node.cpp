#include<iostream>
using namespace std;
#include<vector>
#include <queue>
template <typename t>
class treenode{
	public:
	t data;
	vector<treenode*> child; // or vector<treenode<t>*> child
	treenode(t data)
	{
		this->data=data;
	} 
};
treenode<int>* input2()
{
	int d;
	cout<<"Enter data"<<endl;
	cin>>d;
	treenode<int>* root=new treenode<int>(d);
	queue<treenode<int>*> nodes;
	nodes.push(root);
	
	while(nodes.size()!=0)
	{
		treenode<int>* front= nodes.front();
		nodes.pop();
		cout<<"Enter the no. of children of"<<front->data<<endl;
		int childno;
		cin>>childno;
		for(int i=0;i<childno;i++)
		{
			int n;
			cout<<"Enter "<<i+1<<"child of "<<front->data<<endl;
			cin>>n;
			treenode<int>* child1=new treenode<int>(n);
			front->child.push_back(child1);
			nodes.push(child1);
		}
		
	}
	return root;
}
int count(treenode<int>* root)
{
	int ans=1;
	for(int i=0;i<root->child.size();i++)
	{
		ans+=count(root->child[i]);
	}
	return ans;
}
int leaf(treenode<int>* root)
{
	int ans=1;
	if(root->child.size()==0)
	{
		return 1;
	}
	for(int i=0;i<root->child.size();i++)
	{
		ans+=leaf(root->child[i]);
	}
	return ans-1;
}
int printk(treenode<int>* root,int k)
{
	if(root==NULL)
	{
		return 0;
	}
	if(k==0)
	{
		cout<<root->data<<endl;
	}
	for(int i=0;i<root->child.size();i++)
	{
		printk(root->child[i],k-1);
	}
}
void printtree(treenode<int>* root)
{
	if(root==NULL)
	{
		return;
	}
	cout<<root->data<<":";
	for(int i=0;i<root->child.size();i++)
	{
		cout<<root->child[i]->data<<",";
	}
	cout<<endl;
	for(int i=0;i<root->child.size();i++)
	{
		printtree(root->child[i]);
	}
}
//#include "TreeNode.h"
int main()
{
	treenode<int> *root=input2();
	int ans1=count(root);
	cout<<ans1;
	int f=leaf(root);
	cout<<endl<<f;
}
