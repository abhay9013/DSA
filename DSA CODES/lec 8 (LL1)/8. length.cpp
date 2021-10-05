#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node *next;
		node(int n)
		{
			data=n;
			this->next=NULL;
		}
};
node* input()
{
	int data;
	cin>>data;
	node *head=NULL;
	node *tail=NULL;
	while(data!=-1)
	{
		node *n=new node(data);
		if(head==NULL)
		{
			head=n;
			tail=head;
		}
		else 
		{
			tail->next=n;
			tail=tail->next;
			//or tail=n;
		}
		cin>>data;
	}
	return head;
}
/*int length(node *head)
{
	if(head==NULL)
	{
		return 0;
	}
	int ans=length(head->next);
	ans++;
	return ans;	
}*/
node* insert(node *head,int i,int data)
{
	node *newnode=new node(data);
	if(head==NULL)
	{
		return head;
	}
	if(i==0)
	{
		newnode->next=head;
		head=newnode;
		return head;
	}
	node *n=insert(head->next,i-1,data);
	head->next=n;
	return head;
}
void print(node *head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next ;
	}
}
int main()
{
	node*head=input();
	//int len=length(head);
	//cout<<endl<<len;
	int i,data;
	cin>>i>>data;
	node *head2=insert(head,i,data);
	print(head2);
	return 0;
}

