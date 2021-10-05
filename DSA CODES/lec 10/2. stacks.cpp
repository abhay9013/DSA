#include<iostream>
using namespace std
template <typename t>
class stack{
	private:
		t *data;
		int next;
		int cap;
	public:
		stack()
		{
			data=new t[4];
			next=0;
			cap=4;
		}
		int size()
		{
			return next;
		}
		bool isempty()
		{
			return next==0;
		}
		void push(t ele)
		{
			if(next==cap)
			{
				t *data2=new t[2*cap];
				for(int i=0;i<2*cap;i++)
				{
					data2[i]=data[i];
				}
				cap=2*cap;
				delete [] data;
				data=data2;
			}
			data[next]=ele;
			next++;
		}
		t pop()
		{
			if(isempty())
			{
				cout<<"stack is empty"<<endl;
				return 0;
			}
			next--;
			return data[next];
		}
		t
		 top()
		{
			if(isempty())
			{
				cout<<"stack is empty0"<<endl;
				return INT_MIN;
			}
			return data[next-1];
		}
};
