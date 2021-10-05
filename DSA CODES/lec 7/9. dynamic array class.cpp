#include<iostream>
using namespace std;
class dynamicArray{
	int *data;
	int next;
	int cap; //total size
	public:
		dynamicArray()
		{
			data =new int[5];
			next=0;
			cap=5;
		}
		dynamicArray(dynamicArray &d)
		{
			this->data=new int[d.cap];       //deep copy
			for(int i=0;i<d.next;i++)
			{
				this->data[i]=d.data[i];
			}
			this->cap=d.cap;
			this->next=d.next;
		}
		void operator=(dynamicArray &d)
		{
			this->data=new int[d.cap];
			for(int i=0;i<d.next;i++)
			{
				this->data[i]=d.data[i];
			}
			this->cap=d.cap;
			this->next=d.next;
		}
		void add(int ele)
		{
			if(next==cap)
			{
				int*data2;
				data2=new int[2*cap];
				for(int i=0;i<cap;i++)
				{
					data2[i]=data[i];
				}
				delete [] data;
				data=data2;
				cap=cap*2;
			}
		data[next]=ele;
		next++;
		}
		int get(int i)
		{
			if(i<next)
			{
				return data[i];
			}
			else 
			{
				return -1;
			}
		}
		void add(int i,int ele)
		{
			if(i<next)
			{
				data[i]=ele;
			}
			else if(i==next)
			{
				add(ele);
			}
			else 
			{
				return;
			}
		}
		void print()
		{
			for(int i=0;i<next;i++)
			{
				cout<<data[i]<<" ";
			}
		}
};
int main()
{
	dynamicArray d1;
	d1.add(10);
	d1.add(20);
	d1.add(30);
	d1.add(40);
	d1.add(50);
	d1.print();
	dynamicArray d2(d1);
	d1.add(3,80);
	d1.print();
	cout<<endl;
	d2.print();
	return 0;
}
