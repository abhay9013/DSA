#include<iostream>
using namespace std;
class student{
	private:
		int age;
	public:
		int rollno;
		~student()                         //manually created destructor
		{
			cout<<"destructor called"<<endl;             
		}
		student()            //non parametrised constructor
		{
			cout<<"constructor 1 called"<<endl;
		}
		student(int a)                   //parametrised constructor
		{
			cout<<"constructor 2 called"<<endl;
			age =a;           
		}
		student(int a,int b)
		{
			cout<<"comstructor 3 called "<<endl;
			age = a;
			rollno=b;
		}
		/*student(int age)
		{
			cout<<"the address of this object is "<<this<<endl;         //imp
			this->age=age;
		}*/
		void print()
		{
			cout<<age<<" "<<rollno<<endl;
		}
		void getdata(int x)
		{
			age=x;
		}
};
int main()
{
	student s1; /*statically creating object */ s1.getdata(101);  s1.rollno=101;	s1.print();
	student*s2=new student; /*dynamically creating object for class student*/    (*s2).rollno=25; s2->getdata(85);   s2->print();
	student s4(47,96); s4.print();
	student s5(s4); s5.print();//copy connstructor
	student s3(15); /*calling constructor*/    	s3.rollno=89; s3.print();
	student*s6=new student(49,63); //comstructor 3 called
	student*s7=new student(*s6);//copy constructor
	student*s8=new student(s4);//copy constructor
	
	student s9(77,25);  s9.print();
	student s10(56,45); s10.print();
	student s11=s4 //copy constructor will be called
	s10=s9;  s10.print(); //copy assignment operator
	*s7=s9;//copy assignment operator
	delete s2,s6,s7,s8; // deleting dynamically created object
	return 0;
	
}
