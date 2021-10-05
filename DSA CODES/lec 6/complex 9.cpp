#include<iostream>
using namespace std;
class complex
{
	private:
		int imaginary;
		int real;
	public:
		complex(int real, int imaginary)
		{
			this->real=real;
			this->imaginary=imaginary;
		}
		// void plus(complex c2)        //here we are are passing by variable it interpret as c2 complex=c2.main(); it creates copy of variable from main function object to here
		//to avoid this we will pass by reference
		void plus(complex const &c2)
		{
			real=real+c2.real;
			imaginary=imaginary+c2.imaginary;
		}
		void multiply(complex c2)
		{
			int real1=(real*c2.real)+(-1)*(imaginary*c2.imaginary);
			imaginary=(real*c2.imaginary)+(c2.real*imaginary);
			real=real1;
		}
		void print()
		{
			cout<<real<<" + "<<imaginary<<"i";
		}
};
int main()
{
	int real1,real2,imaginary1,imaginary2;
	cout<<"enter the imaginary and real part pf the ctwo complex no."<<endl;
	cin>>real1>>imaginary1;
	cin>>real2>>imaginary2;
	complex c1(real1,imaginary1);
	complex c2(real2,imaginary2);
	int choice;
	cout<<"enter the choice"<<endl;
	cin>>choice;
	if(choice==1)
	{
		c1.plus(c2);
		c1.print();
	}
	else if(choice==2)
	{
		c1.multiply(c2);
		c1.print();
	}
	else
	{
		return 0;
	}
}
