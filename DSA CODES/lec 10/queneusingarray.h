#include<iostream>
using namespace std;
template <typename t>
class quene{
	private:
		t* data;
		int size;
		int fi;
		int ni;
		int cap;
	public:
		quene(int s)
		{
			data=new t[s-1];
			fi=-1;
			ni=0;
			size=0;
			cap=s;
		}
		int getsize()
		{
			return size;
		}
		bool isempty()
		{
			return size==0;
		}
		void enquene(t ele)
		{
			if(size==cap)
			{
				t *data2=new t[2*cap];
				for(int i=0;i<size;i++)
				{
					data2[i]=data[fi];
					fi=(fi+1)%cap;
				}
				delete [] data;
				data=data2;
				cap=cap*2;
				fi=0;
				ni=size;
			}
			data[ni]=ele;
			ni=(ni+1)%cap ;
			if(fi==-1)
			{
				fi=0;
			}
			size++; 
		}
		t front()
		{
			if(fi==-1)
			{
				cout<<"quene is empty"<<endl;
				return 0;
			}
			return data[fi];
		}
		t dequene()
		{
			if(isempty())
			{
				cout<<"Quene is Empty !"<<endl;
				return 0;
			}
			int k=data[fi];
			fi=(fi+1)%cap;
			size--;
			if(size==0)
			{
				fi=-1;
				ni=0;
			}
			return k;
		}
};
