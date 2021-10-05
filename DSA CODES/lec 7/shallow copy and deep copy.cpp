#include<iostream>
#include<string.h>
using namespace std;
class student{
	private:
		int age;
		char*name;
	public:
		student(int age, char*name)
		{
			this->age=age;
			//shallow copy
			//this=>namre =name;
			
			//deep copy;
			this->name= new char(strlen(name));
			strcpy(this->name,name);
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
	name[4]='e';
	student s2(87,name);
	s1.display();
	s2.display();
	return 0;
}
