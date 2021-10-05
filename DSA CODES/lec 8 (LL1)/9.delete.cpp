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
node *input()
{
	int d;
	cin>>d;
	node *head=NULL;
	node *tail=NULL;
	while(d!=-1)
	{
		node *n=new node(d);
		if(head==NULL)
		{
			head=n;
			tail=head;
		}
		else
		{
			tail->next=n;
			tail=tail->next;
		}
		cin>>d;
	}
	return head;
}
node *deletenode(node *head,int i)
{
	if(head==NULL)
	{
		return head;
	}
	if(i==0)
	{
		node*a=head;
		head=head->next;
		delete a;
		return head;
	}
	node *n=deletenode(head->next,i-1);
	head->next=n;
	return head;
}
void print(node *n)
{
	while(n!=NULL)
	{
		cout<<n->data<<" ";
		n=n->next;
	}
}
int main()
{
	node *head=input();
	print(head);
	int i;
	cin>>i;
	node *head2=deletenode(head,i);
	print(head2);
	return 0;
}
