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
node* insert(node *head , int data , int i)
{
	node *temp=head;
	node *newnode=new node(data);
	int count =0;
	if(i==0)
	{
		newnode->next=head;
		head=newnode;
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
		temp->next=newnode;
		newnode->next=a;
		
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
	int data,i;
	cin>>data>>i;
	node *head1=insert(head,data,i);
	print(head1);
	return 0;
}
