#include<iostream>
using namespace std;
class node{
	public:
		int data;
		node *next;
		node(int x)
		{
			data=x;
			this->next=NULL;
		}
};
node* input()
{
	int x;
	cin>>x;
	node *head=NULL;
	node *tail=NULL;
	while(x!=-1)
	{
		node *n=new node(x);
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
		cin>>x;
	}
	return head;
}
node* deletenode(node *head , int i)
{
	node *temp=head;
	int count =0;
	if(i==0)
	{
		node *c=head;
		head=head->next;
		delete c;
		return head;
	}
	while(temp!=NULL&&count<i-1)
	{
		temp=temp->next;
		count++;
	}
	if(temp!=NULL)
	{
		node *a=temp->next;
		node *b=a->next;
		temp->next=b;
		delete a;
		
		/*
		newmnode->next=temp->next;
		temp->next=newnode;
		*/
	}
	return head;	
}
void print(node *head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
}
int main()
{
	node *head=input();
	print(head);;
	cout<<endl;
	int i;
	cin>>i;
	node *head1=deletenode(head,i);
	print(head1);
	return 0;
}
