#include<iostream>
using namespace std;
#include "queneusingarray.h"
int main()
{
	quene<int> s(5);
	s.enquene(10);
	s.enquene(20);
	s.enquene(30);
	s.enquene(40);
	s.enquene(50);
	cout<<s.front()<<endl;
	cout<<s.dequene()<<endl;
	cout<<s.dequene()<<endl; 
	s.enquene(60);
	s.enquene(70);
	s.enquene(80);
	s.enquene(90);
	cout<<s.dequene()<<endl;
	cout<<s.dequene()<<endl;
	cout<<s.dequene()<<endl;
	cout<<s.dequene()<<endl;
	cout<<s.dequene()<<endl;
	cout<<s.dequene()<<endl;
	cout<<s.dequene()<<endl;
	cout<<s.getsize()<<endl;
	cout<<s.isempty()<<endl;
	return 0;
}
