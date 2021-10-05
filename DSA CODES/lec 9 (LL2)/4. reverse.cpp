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
node *reverse(node *head)
{
	if(head==NULL)
	{
		return NULL;
	}
	if(head->next==NULL)
	{
		return head;
	}
	node *temp=reverse(head->next);
	node *temp2=temp;
	while(temp2->next!=NULL)
	{
		temp2=temp2->next;
	}
	head->next=NULL;
	temp2->next=head;
	return temp;
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
	node *n1=input();
	print(n1); cout<<endl;
	node *n2=reverse(n1);
	print(n2);
	return 0;
}

