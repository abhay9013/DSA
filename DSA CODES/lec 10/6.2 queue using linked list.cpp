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
class queue{
	private:
		node<t> *head;
		node<t> *tail;
		int size;
	public:
		queue()
		{
			head=NULL;
			tail=NULL;
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
		void enqueue(t ele)
		{
			node<t> *n=new node<t>(ele);
			if(head==NULL)
			{
				head=n;
				tail=n;
				size++;
			}
			else
			{
				tail->next=n;
				tail=n;
				size++;
			}
		}
		t front()
		{
			if(head==NULL)
			{
				cout<<"Queue is Empty"<<endl;
				return 0;
			}
			return head->data;
		}
		t dequeue()
		{
			if(head==NULL)
			{
				cout<<"Queue is Empty"<<endl;
				return 0;
			}
			t ans=head->data;
			node<t> *temp=head;
			head=head->next;
			delete temp;
			size--;
			return ans;
		}
};
int main()
{
	queue<int> q;
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	q.enqueue(60);
	cout<<q.front()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.getsize()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.isempty()<<endl;
	return 0;
}
