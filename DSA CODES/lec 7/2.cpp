#include<iostream>
#include<string.h>
using namespace std;
class student{
	private:
		int age;
	public:
		char*name;
		student(int age, char*name)
		{
			this->age=age;
			//shallow copy
			//this=>namre =name;
			
			//deep copy;
			this->name= new char(strlen(name+1));
			strcpy(this->name,name);
		}
		student(student const &s)
		{
			this->age=s.age;
			this->name=new char(strlen(name+1));
			strcpy(this->name,s.name);
		}
		void display()
		{
			cout<<name<<" "<<age<<endl;
		}
};
int main()
{
	char name[]="abcd";
	student s1(20,name);
	
	student s2(s1);
	s1.display();
	s2.name[1]='x';
	/*s2.display();
	s1.display();
	changes will be affected in both because we are using copy constructior due to which both are pointing to same address*/
	s2.display();
	s1.display();
	return 0;
}
