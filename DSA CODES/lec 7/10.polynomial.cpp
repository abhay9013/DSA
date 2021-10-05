#include<iostream>
using namespace std;
class polynomial{
	int *degcof;
	int cap;
	public:
		polynomial()
		{
			degcof=new int[10];
			for(int i=0;i<cap;i++)
			{
				degcof[i]=0;
			}
			this->cap=10;
		}
		polynomial(int *p,int g)
		{
			cap=g;
			degcof=new int[g];
			degcof=p;
		}
		polynomial(polynomial const &p)
		{
			this->degcof=new int[p.cap];
			for(int i=0;i<p.cap;i++)
			{
				this->degcof[i]=p.degcof[i];
			}
			this->cap=p.cap;
		}
		void operator=(polynomial const &p)
		{
			this->degcof=new int[p.cap];
			for(int i=0;i<p.cap;i++)
			{
				this->degcof[i]=p.degcof[i];
			}
			this->cap=p.cap;
		}
		void setcof(int deg,int cof)
		{
			if(deg>cap)
			{
				int *dc;
				dc=new int[cap*2];
				for(int i=0;i<cap;i++)
				{
					dc[i]=degcof[i];
				}
				delete [] degcof;
				degcof=dc;
				cap=cap*2;
			}
			degcof[deg]=cof;
			
		}
		polynomial operator+(polynomial const &p)
		{
			polynomial p3;
			int *dc2;
			/*max(cap,p.cap)
			cout<<cap*/
			dc2=new int[cap];
			for(int i=0;i<p.cap;i++)
			{
				dc2[i]=degcof[i]+p.degcof[i];
				cout<<dc2[i]<<endl;
			}
			int j=p.cap;
			cout<<j<<endl;
			//p3(dc2,j);
			return p3;
		}
		polynomial operator-(polynomial const &p)
		{
			
		}
		void print()
		{
			cout<<cap<<" / ";
			/*for(int i=0;i<cap;i++)
			{
				if(degcof[i]!=0)
				{
					cout<<degcof[i]<<"x^"<<i<<" + ";
				}
			}*/
		}
int main()
{
	polynomial p1;
	p1.setcof(1,3);
	p1.setcof(2,6);
	p1.print();
	polynomial p2;
	p2.setcof(1,3);
	p2.setcof(2,5);
	p2.print();
	polynomial p4=p1+p2;
	p4.print();
	return 0;
}
