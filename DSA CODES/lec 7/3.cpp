#include<iostream>
using namespace std;
class student{
	public:
		const int age;
		int rollno;
		int &x; //rollno reference variable
		
		//to put value in const we use initialisation list
		//same will be used for reference variable
	student(int age,int rollno) : age(age) , rollno(rollno) , x(this -> rollno)    //don't need to use this here 
	{
	}
	void display()
	{
		cout<<age<<" "<<rollno<<" "<<x<<endl;
	}
};
int main()
{
	int age,rollno;
	cout<<"enter the no."<<endl;
	cin>>age>>rollno;
	student s1(age,rollno);
	s1.display();
	return 0;
}
