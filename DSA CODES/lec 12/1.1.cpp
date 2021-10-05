#include<iostream>
using namespace std;
#include <queue>
#include "binarytreeclass.h"

binarytreenode<int>* input2()
{
	queue<binarytreenode<int>*> q;
	int rdata;
	cout<<"Enter data"<<endl;
	cin>>rdata;
	binarytreenode<int>* root=new binarytreenode<int>(rdata);
	q.push(root);
	while(q.size()!=0)
	{
		binarytreenode<int>* front=q.front();
		q.pop();
		cout<<"Enter left child of "<<front->data<<endl;
		int leftchild;
		cin>>leftchild;
		if(leftchild!=-1)
		{
			binarytreenode<int>* n=new binarytreenode<int>(leftchild);
			front->left=n;
			q.push(n);
		} 
		
		cout<<"Enter right child of "<<front->data<<endl;
		int rightchild;
		cin>>rightchild;
		if(rightchild!=-1)
		{
			binarytreenode<int>* n=new binarytreenode<int>(rightchild);
			front->right=n;
			q.push(n);
		}
	}
	return root;
}
void print2(binarytreenode<int>* root)
{
	queue<binarytreenode<int>*> q;
	q.push(root);
	while(q.size()!=0)
	{
		binarytreenode<int>* front=q.front();
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
binarytreenode<int>* buildtree(int* in,int* pre,int ins,int ine,int pres,int pree)
{
	if(ins>ine)
	{
		return NULL;
	}
	int rootdata=pre[pres];
	int rootindex=-1;
	for(int i=ins;i<=ine;i++)
	{
		if(in[i]==rootdata)
		{
			rootindex=i;
			break;
		}
	}
	int lpres=pres+1;
	int lins=ins;
	int line=rootindex-1;
	int lpree=line-lins+lpres;;
	int rpres=lpree+1;
	int rpree=pree;
	int rins=rootindex+1;
	int rine=ine;
	binarytreenode<int>* root=new binarytreenode<int>(rootdata);
	root->left=buildtree(in,pre,lins,line,lpres,lpree);
	root->right=buildtree(in,pre,rins,rine,rpres,rpree);
	return root;
}
binarytreenode<int>* maketree(int* in,int* pre,int size)
{
	return buildtree(in,pre,0,size-1,0,size-1);
}
int numnodes(binarytreenode<int>* root)
{
	int ans=1;
	if(root==NULL)
	{
		return 0;
	}
	ans+=numnodes(root->left);
	ans+=numnodes(root->right);
	//return 1+numnodes(root->left)+numnodes(root->right);
	return ans;
}
void inorder(binarytreenode<int>* root)
{
	if(root==NULL)
	{
		return;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
void preorder(binarytreenode<int>* root)
{
	if(root==NULL)
	{
		return;
	}
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
pair<int,int> heightdiameter(binarytreenode<int>* root)
{
	if(root==NULL)
	{
		pair<int,int> p;
		p.first=0;
		p.second=0;
		return p;
	}
	pair<int,int> leftans=heightdiameter(root->left);
	pair<int,int> rightans=heightdiameter(root->right);
	int ld=leftans.second;
	int lh=leftans.first;
	int rd=rightans.second;
	int rh=rightans.first;
	int height=1+max(lh,rh);
	int diameter=max(lh+rh,max(ld,rd));
	pair<int,int> p;
	p.first=height;
	p.second=diameter;
	return p;
}

/*void postorder(binarytreenode<int>* root)
{
//wrong hai ye upar walo se luch sheekh
	if(root==NULL)
	{
		return;
	}
	postorder(root->right);
	postorder(root->left);
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
}*/
/*binarytreenode<int>* input() 
{
	int rdata;
	cout<<"Enter data "<<endl;
	cin>>rdata;
	if(rdata==-1)
	{
		return NULL;
	}
	binarytreenode<int>* root=new binarytreenode<int>(rdata);
	binarytreenode<int>* leftchild = input();
	binarytreenode<int>* rightchild = input();
	root->left=leftchild;
	root->right=rightchild;
	return root;
}*/
 
// 
int main()
{
	int pre[]={1,2,4,5,3,6};
	int in[]={4,2,5,1,6,3};
	/*binarytreenode<int>* root=new binarytreenode<int>(1);
	binarytreenode<int>* node1=new binarytreenode<int>(2);
	binarytreenode<int>* node2=new binarytreenode<int>(3);
	root->left=node1;
	root->right=node2;*/
	binarytreenode<int>* root1=input2();
	cout<<endl;
	print2(root1);
	int x=numnodes(root1);
	
 	preorder(root1);
 	cout<<endl;
 	cout<<"inorder "<<endl;
	inorder(root1);
	cout<<endl<<endl<<endl;
	/*binarytreenode<int>* root2 = maketree(in,pre,6);
	print2(root2);*/
	/*cout<<x<<endl;
	cout<<endl<<"preorder";
	cout<<endl;
	cout<<endl<<"postorder"<<endl;
	postorder(root1);*/
	
	
	pair<int,int> p=heightdiameter(root1);
	cout<<"height" <<p.first<<endl;
	cout<<"diameter "<<p.second<<endl;
	delete root1;
	return 0;
}
