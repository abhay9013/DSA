#include<iostream>
#include<stdlib.h>
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
node *mid(node *head)
{
	node *slow=head;
	node *fast=head->next;
	while(fast!=NULL)
	{
		fast=fast->next;
		if(fast==NULL)
		{
			return slow;;
		}
		slow=slow->next;
		fast=fast->next;
	}
	return slow;
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
	print(head);
	node *head2=mid(head);
	cout<<endl<<"The mid element of linked list is "<<head2->data;
	return 0;
}
