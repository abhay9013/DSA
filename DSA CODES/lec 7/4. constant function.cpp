#include<iostream>
using namespace std;
class student{
	private:
		int age;
		int rollno;
	public:
		student (int x,int y)
		{
			age=x;
			rollno=y;
		}
		int getrollno() const 
		{
			return rollno;
		}
		int getage() const 
		{
			return age;
		}
		void print() const  //constant function
		{
			cout<<age<<" "<<rollno;
		}
		void putdata(int x,int y)
		{
			age=x;
			rollno=y;
		}
};
int main()
{
	student const s1(15,12); //constant object decelartion
	s1.print();
}
