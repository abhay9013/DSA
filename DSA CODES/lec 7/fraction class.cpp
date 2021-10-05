#include<iostream>
using namespace std;
class fraction{
	private:
		int num;
		int den;
	public:
		fraction (int x,int y)
		{
			num=x;
			den=y;
		}
		void simplify()
		{
			int gcd=1;
			int j=min(num,den);
			for(int i=1;i<=j;i++)
			{
				if(num%i==0&&den%i==0)
				{
					gcd=i;
				}
			}
			num=num/gcd;
			den=den/gcd;
		}
		void add(fraction const &f)
		{
			num=(num*f.den)+(f.num*den);
			den=den*f.den;
			simplify();
		}
		void multiply(fraction const &f)
		{
			num=num*f.num;
			den=den*f.den;
		}
		void print()
		{
			cout<<num<<"/"<<den;
		}
};
int main()
{
	fraction s1(15,45);
	fraction s2(10,3);
	s1.add(s2);
	s1.print();
	return 0;
}
