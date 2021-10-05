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
	while(data!=-1)
	{
		node *n=new node(data);
		if(head==NULL)
		{
			head=n;
		}
		else 
		{
			node *temp=head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=n;
		}
		cin>>data;
	}
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
	print(head);
	return 0;
}

