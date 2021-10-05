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
/*void print(treenode<int>* root)
{
	queue<treenode<int>*> q;
	q.push(root);
	while(q.size()!=0)
	{
		treenode<int>* front=q.front();
		q.pop();
		cout<<front->data<<":";
		for(int i=0;front->child.size();i++)
		{
			cout<<front->child[i]->data<<",";
			treenode<int>* child1=front->child[i];
			q.push(child1);
		}
		cout<<endl;
	}
}*/
/*
treenode<int>* input()
{
	int data;
	cout<<"Enter data"<<endl;
	cin>>data;
	treenode<int>* root=new treenode<int>(data);
	int n;
	cout<<"Enter the no. of children of "<<data;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		treenode<int>* n=input();
		root->child.push_back(n);	
	}
	return root; 
}*/
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
	//printtree(root);
	/*
	treenode<int> *root=new treenode<int>(1);
	treenode<int> *node1=new treenode<int>(2);
	treenode<int> *node2=new treenode<int>(3);  
	root->child.push_back(node1);
	root->child.push_back(node2); 
	*/
}
