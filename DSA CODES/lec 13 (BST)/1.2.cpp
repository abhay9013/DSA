#include<iostream>
using namespace std;
#include<queue>
#include<vector>
template <typename t>
class binarytree{
	public:
		t data;
		binarytree* left;
		binarytree* right;
		binarytree(t data)
		{
			this->data=data;
			left=NULL;
			right=NULL;
		}
		~binarytree()
		{
			delete left;
			delete right;
		}
};
class node{
	public:
		int data;
		node* head;
		node* next;
		node* tail;
		node(int data)
		{
			this->data=data;
			head=NULL;
			next=NULL;
			tail=NULL;
		} 
};
binarytree<int>* input2()
{
	queue<binarytree<int>*> q;
	int rdata;
	cout<<"Enter data"<<endl;
	cin>>rdata;
	binarytree<int>* root=new binarytree<int>(rdata);
	q.push(root);
	while(q.size()!=0)
	{
		binarytree<int>* front=q.front();
		q.pop();
		cout<<"Enter left child of "<<front->data<<endl;
		int leftchild;
		cin>>leftchild;
		if(leftchild!=-1)
		{
			binarytree<int>* n=new binarytree<int>(leftchild);
			front->left=n;
			q.push(n);
		} 
		
		cout<<"Enter right child of "<<front->data<<endl;
		int rightchild;
		cin>>rightchild;
		if(rightchild!=-1)
		{
			binarytree<int>* n=new binarytree<int>(rightchild);
			front->right=n;
			q.push(n);
		}
	}
	return root;
}
void print(binarytree<int>* root)
{
	queue<binarytree<int>*> q;
	q.push(root);
	while(q.size()!=0)
	{
		binarytree<int>* front=q.front();
		q.pop();
		cout<<front->data<<":";
		if(front->left!=NULL)
		{
			cout<<"L"<<front->left->data;
			q.push(front->left);
		}
		
		if(front->right)
		{
			cout<<"R"<<front->right->data;
			q.push(front->right);
		}
		cout<<endl;
	} 
}
vector<int>* path(binarytree<int>* root, int p)
{
	if(p==root->data)
	{
		vector<int>* n1= new vector<int>();
		n1->push_back(root->data);
		return n1;
	}
	cout<<"check"<<endl;
	if(root==NULL)
	{
		return NULL;
	}
	cout<<"check 2";
	vector<int>* left1=path(root->left,p);
	if(left1!=NULL)
	{
		left1->push_back(root->data);
		return left1;
	}
	
	vector<int>* right1=path(root->right,p);
	if(right1!=NULL)
	{
		right1->push_back(root->data);
		return right1;
	}
	else
	{
		return NULL;
	}
}
/*
node* bstll(binarytree<int>* root)
{
	node* n1=new node(root->data)
	if(root==NULL){
		return NULL;
	}
	if(head==NULL)
	{
		head=n1;
		tail=n1;
		return head;
	}
	node* left=bstll(root->left);
	node* right=bstll(root->right);
	head->next=right;
	tail=left;
}*/
int main()
{
	// 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
	binarytree<int>* root1 = input2();
	print(root1);
}
