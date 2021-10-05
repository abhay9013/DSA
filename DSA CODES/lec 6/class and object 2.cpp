#include<iostream>
using namespace std;
class student{
	private:
		int age;
	public:
		int rollno;
		student()            //non parametrised constructor
		{
			cout<<"constructor 1 called"<<endl;
		}
		student(int a)                   //parametrised constructor
		{
			cout<<"constructor 2 called"<<endl;
			age =a;           
		}
		student(int b)
		{
			cout<<"comstructor 3 called "<<endl;
			rollno=b;
		}
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
	student s9(77);  s9.print();
	student s10(45); s10.print();

	return 0;
	
}
