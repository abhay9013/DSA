#include<iostream>
#include<vector>
using namespace std;

class priorityqueue{
	vector<int> pq;
	
	public:
		priorityqueue()
		{
			
			
		}
		bool isempty()
		{
			return pq.size()==0;
		}
		int getsize()
		{
			return pq.size();
		}
		int getmin(){
			if(isempty())
			{
				return -1;
			}
			return pq[0];
		}
		
		void insert(int ele)
		{
			pq.push_back(ele);
			int childindex=pq.size()-1;
			
			while(childindex>0)
			{
				int parentindex=(childindex-1)/2;
				if(pq[parentindex]>pq[childindex])
				{
					int temp=pq[parentindex];
					pq[parentindex]=pq[childindex];
					pq[childindex]=temp;
				}
				else
				{
					break;
				}
				childindex=parentindex;
			}
		}
		
		int pop()
		{
			if(isempty())
			{
				return -1;
			}
			int ei=pq.size()-1;
			int temp=pq[0];
			pq[0]=pq[ei];
			pq.pop_back();
			
			int pi=0;
			while(((2*pi)+1)<(pq.size()))
			{
				int ci1=(2*pi)+1;
				int ci2=(2*pi)+2;
				int small,k;
				if(pq[ci1]>pq[ci2]&&ci2<pq.size())
				{
					small=pq[ci2];
					k=ci2;
				}
				else
				{
					small=pq[ci1];
					k=ci1;
				}
				if(pq[pi]>small)
				{
					int temp=pq[pi];
					pq[pi]=small;
					pq[k]=temp;
				}
				else{
					break;
					}
				pi=k;

			}		
			return temp;
		}
};

int main()
{
	priorityqueue p1;
	p1.insert(100);
	p1.insert(10);
	p1.insert(15);
	p1.insert(4);
	p1.insert(17);
	p1.insert(21);
	p1.insert(67);
	cout<<p1.getmin()<<endl;
	cout<<p1.getsize()<<endl;
	while(!p1.isempty())
	{
		cout<<p1.pop()<<",";
	}
	return 0;	
}
