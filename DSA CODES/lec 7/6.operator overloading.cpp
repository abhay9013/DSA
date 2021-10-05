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
		fraction& operator++()
		{
			num=num+den;
			simplify();
			return *this;
		}
		void print()
		{
			cout<<num<<"/"<<den<<endl;
		}
};
int main()
{
	fraction s1(15,45);
	/*fraction s2(10,3);
	fraction s3=s1.add(s2);
	fraction s4=s1+s2;
	s4.print();
	s3.print()*/;
	/*fraction s5=++s1;
	s1.print();
	s5.print();*/
	/*fraction s6=++(++s1);
	s1.print(); //this value is not recived by any integer and also this will guve 4/3 because only one time value goes to this address
	s6.print();  //this will give 7/3 because it will use temp memory created or buffer memory created after ++s
	// to avoid this we will return value by reference
	*/
	fraction s7=++(++s1);
	s1.print();
	s7.print();
	/*if(s1==s2)
	{
		cout<<"fraction are equal"<<endl;  
	}
	else
	{
		cout<<"fraction are unequal"<<endl;
	}*/
	return 0;
}
