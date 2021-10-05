#include<iostream>
using namespace std;
template <typename t>
class node{
	public:
		t data;
		node<t> *next;
		node(t data)
		{
			this->data=data;
			next=NULL;
		}
};
template <typename t>
class stack{
	private:
		node<t> *head;
		int size;
	public:
		stack()
		{
			head=NULL;
			size=0;
		}
		int getsize()
		{
			return size;
		}
		bool isempty()
		{
			return size==0;
		}
		void push(t ele)
		{
			node<t> *n=new node<t>(ele);
			if(head==NULL)
			{
				head=n;
				size++;  
			}
			else 
			{
				n->next=head;
				head=n;
				size++;
			}
		}
		t pop()
		{
			if(isempty())
			{
				return 00;
			}
			node<t> *ans=head;
			int ans1=head->data;
			head=head->next;
			delete ans;
			size--;
			return ans1;
		}
		t top()
		{
			if(isempty())
			{
				return 0;
			}
			return head->data;
		}
		
};
