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
binarytree<int>* bsearch(binarytree<int>* root,int data1)
{
	if(root==NULL)
	{
		return NULL;
	}
	if(root->data==data1)
	{
		return root;
	}
	else if(data1<root->data)
	{
		bsearch(root->left,data1);
	}
	else
	{
		bsearch(root->right,data1);
	}
}
class isbstreturn{
	public:
		int min;
		int max;
		bool isbst;
};

isbstreturn Isbst(binarytree<int>* root)
{
	if(root==NULL)
	{
		isbstreturn op;
		op.max=INT_MIN;
		op.min=INT_MAX;
		op.isbst=true;
		return op;
	}
	isbstreturn leftans = Isbst(root->left);
	isbstreturn rightans = Isbst(root->right);
	int mini=min(root->data,min(leftans.min,rightans.min));
	int maxi=max(root->data,max(leftans.max,rightans.max));
	bool isbstfinal=(root->data>leftans.max)&&(root->data<=rightans.max)&&leftans.isbst&&rightans.isbst;
	isbstreturn op2;
	op2.min=mini;
	op2.max=maxi;
	op2.isbst=isbstfinal;
	return op2;
}
bool isbst3(binarytree<int>* root,int min=INT_MIN,int max=INT_MAX)
{
	if(root==NULL)
	{
		return true;
	}
	if(root->data<min||root->data>max)
	{
		return false;
	}
	bool left=isbst3(root->left,min,root->data-1);
	bool right=isbst3(root->right,root->data,max);
	return left&&right;
}
binarytree<int>* create(int *arr, int si , int ei)
{
	int mid=(si+ei)/2;
	
	if(ei==-1||si>ei)
	{
		return NULL;
	}
	else if(arr[mid]==-1)
	{
		return NULL;
	}
	binarytree<int>* root=new binarytree<int>(arr[mid]);
	cout<<"!!!!!"<<arr[mid]<<endl;
	//arr[mid]=-1;
	binarytree<int>* left1=create(arr,si,mid-1);
	binarytree<int>* right1=create(arr,mid+1,ei);
	root->left=left1;
	root->right=right1;
	return root;
}
/*int maximum(binarytree<int>* root)
{
	if(root==NULL)
	{
		return INT_MIN;
	}
	return max(root->data,max(maximum(root->left),maximum(root->right)));
}
int minimum(binarytree<int>* root)
{
	if(root==NULL)
	{
		return INT_MAX;
	}
	return min(root->data,min(minimum(root->left),minimum(root->right)));
}
bool isbst(binarytree<int>* root)
{
	if(root==NULL)
	{
		return true;
	}
	int leftmax=maximum(root->left);
	int rightmin=minimum(root->right);
	bool output=(root->data>leftmax)&&(root->data<=rightmin)&&isbst(root->left)&&isbst(root->right);
	return output;
}*/
int main()
{
	int arr[]={1,2,3,4,5,6,7};
	int si=0;
	int ei=6;
	binarytree<int>* root2=create(arr,si,ei);
	cout<<"Created bst is "<<endl;
	print(root2); cout<<endl;
	// 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
	/*binarytree<int>* root1=input2();
	print(root1);
	cout<<isbst3(root1)<<endl;*/
}
