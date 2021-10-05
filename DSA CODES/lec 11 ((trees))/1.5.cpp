#include<iostream>
using namespace std;
#include <queue>
#include<vector>
template <typename t>
class treenode{
	public:
		t data;
		vector<treenode<int>*> child;
		treenode(t data)
		{
			this->data=data;
		}
		~treenode()
		{
			for(int i=0;i<child.size();i++)
			{
				delete(child[i]);
			}
		}
};
treenode<int>* input()
{
	int data2;
	cout<<"enter data"<<endl;
	cin>>data2;
	treenode<int>* root=new treenode<int>(data2);
	queue<treenode<int>*> q;
	q.push(root);
	
	while(q.size()!=0)
	{
		treenode<int>* front=q.front();
		q.pop();
		int x;
		cout<<"Enter total child of "<<front->data<<endl;
		cin>>x;
		for(int i=0;i<x;i++)
		{
			int cd;
			cout<<endl<<"Enter "<<i+1<<" child of "<<front->data<<endl;
			cin>>cd;
			treenode<int>* k=new treenode<int>(cd);
			front->child.push_back(k);
			q.push(k);
		}
	}
	return root;
}
void preorder(treenode<int>* root)
{
	if(root=NULL)
	{
		return;
	}
	cout<<root->data<<" ";
	for(int i=0;i<root->child.size();i++)
	{
		preorder(root->child[i]);
	}
}
void postorder(treenode<int>* root)
{
	if(root==NULL)
	{
		return;
	}
	for(int i=0;i<root->child.size();i++)
	{
		postorder(root->child[i]);
	}
	cout<<root->data;
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
void deletetree(treenode<int>* root)
{
	for(int i=0;i<root->child.size();i++)
	{
		deletetree(root->child[i]);
	}
	delete root;
}
// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 0
int main()
{
	treenode<int>* root1=input();
	postorder(root1);
	return 0;
}
