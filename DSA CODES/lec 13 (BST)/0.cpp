#include<iostream>
using namespace std;
#include<queue>
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
/*binarytree<int>* input()
{
	queue<binarytree<int>*> q;
	int data;
	cout<<"Enter Root Data "<<endl;
	cin>>data;
	binarytree<int>* root=new binarytree<int>(data);
	q.push(root);
	while(q.size()!=0)
	{
		binarytree<int>* front=q.front();
		q.pop();
		cout<<"Enter the left child data "<<front->data<<endl;
		int leftchild;
		cin>>leftchild;
		if(leftchild!=-1)
		{
			binarytree<int>* n=new binarytree<int>(leftchild);
			root->left=n;
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
}*/
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
int main()
{
	// 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
	binarytree<int>* root1=input2();
	print(root1);
}
