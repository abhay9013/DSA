#include<iostream>
using namespace std;
class node{
	public:
		int val;
		node *next;
		node(int x)
		{
			val=x;
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
node* merge(node *l1, node *l2)
{
	/*node *head=NULL;
	node *tail=NULL;
	int i=0;
	while(n1!=NULL)
	{
	if(head==NULL)
	{
		if(n1->data<n2->data)
		{
			head=n1;
			tail=n1;
			n1=n1->next;
		}
		else
		{
			head=n2;
			tail=n2;
			n2=n2->next;
		}
	}
	else
	{
		if(n1->data<n2->data)
		{
			tail->next=n1;
			tail=n1;
			n1=n1->next;
		}
		else
		{
			tail->next=n2;
			tail=n2;
			n2=n2->next;
		}
	}
	}
	if(n1==NULL||n2==NULL)
	{
		while(n2!=NULL)
		{
			tail->next=n2;
			tail=n2;
			n2=n2->next;
		}
	}
	return head;*/
	node* head=NULL;
    node* tail=NULL;
        
        while((l1!=NULL)&&(l2!=NULL))
        {
            if(head==NULL)
            {
            if((l1->val)<=(l2->val))
            {
                head=l1;
                tail=l1;
                l1=l1->next;
            }
            else
            {
                head=l2;
                tail=l2;
                l2=l2->next;
            }
            }
            else if(head!=NULL)
            {
            if((l1->val)<=(l2->val))
            {
                tail=l1;
                tail=tail->next;
                l1=l1->next;
            }
            else
            {
                tail=l2;
                tail=tail->next;
                l2=l2->next;
            }
            }
        }
        if((l1==NULL)&&(l2!=NULL))
        {
            while(l2!=NULL)
            {
                tail=l2;
                tail=tail->next;
                l2=l2->next;
            }
        }
        else if((l2==NULL)&&(l1!=NULL))
        {
            while(l1!=NULL)
            {
                tail=l1;
                tail=tail->next;
                l1=l1->next;
            }
        }
        return head;
}
void print(node *head)
{
	while(head!=NULL)
	{
		cout<<head->val<<" ";
		head=head->next;
	}
}
int main()
{
	node *n1=input();
	print(n1);
	cout<<endl;
	node *n2=input();
	print(n2); cout<<endl;
	node *head=merge(n1,n2);
	print(head);
}
