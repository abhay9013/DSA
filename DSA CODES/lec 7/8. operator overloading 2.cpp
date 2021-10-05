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
		/*void add(fraction const &f)
		{
			num=(num*f.den)+(f.num*den);
			den=den*f.den;
			simplify();
		}*/
		fraction add(fraction const &f) //do not changing the original values returning values in other fraction type
		{
			int num1=(num*f.den)+(f.num*den);
			int den1=den*f.den;
			fraction fnew(num1,den1);
			fnew.simplify();
			return fnew;
		}
		fraction operator+(fraction const &f) //operator overlaading
		{
			int num1=(num*f.den)+(f.num*den);
			int den1=den*f.den;
			fraction fnew(num1,den1);
			fnew.simplify();
			return fnew;
		}
		bool operator==(fraction f)
		{
			if(num==f.num&&den==f.den)
			{
				return true;
			}
			else 
			{
				return false;
			}
		}
		void multiply(fraction const &f)
		{
			num=num*f.num;
			den=den*f.den;
		}
		/*void operator++()
		{
			num=num+den;
			simplify();
		}*/
		fraction& operator++()    //pre incremnet format
		{
			num=num+den;
			simplify();
			return *this;
		}
		void print()
		{
			cout<<num<<"/"<<den<<endl;
		}
		fraction operator++(int) //post increment format
		{
			fraction fnew(num,den);
			num=num+den;
			fnew.simplify();
			simplify();
			return fnew;
		}
		fraction& operator+=(fraction const &f)
		{
			int num1=(num*f.den)+(den*f.num);
			den=den*f.den;
			num=num1;
			simplify();
			return *this;
		}
		
};
int main()
{
	fraction s1(15,45);
	fraction s3(5,9);  
	//fraction s2=s1++;
	(s3+=s1)+=s1;
	s3.print();
	s1.print();
	return 0;
}
