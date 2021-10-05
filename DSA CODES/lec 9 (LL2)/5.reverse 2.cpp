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
class pair {
	public:
		node *head;
		node *tail;
};

pair reverse(node *head)
{
	if(head==NULL || head->next==NULL)
	{
		pair ans;
		ans.head=head;
		ans.tail=tail;
		return ans;
	}
	pair temp=reverse(head->next);
	temp.tail->next=head;
	head->next=NULL;
	pair ans;
	ans.heaed=temp.head;
	ans.tail=head;
	return ans;
}
node *reverse1(node *head)
{
	return reverse(head).head;
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
	node *n2=reverse1(n1);
	print(n3);
	return 0;
}

