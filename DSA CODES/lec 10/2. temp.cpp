#include<iostream>
template <typename t ,typename p>
class pair{
	t x;
	p y;
	public :
		void setx(t x)
		{
			this->x=x;
		}
		t getx() {
			return x;
		}
		void sety(p y)
		{
			this->y=y;
		}
		p gety()
		{
			return y;
		}
};
int main()
{
	pair <pair<int ,int>,int> p;
	pair <int,int> p2;
	p2.setx(10);
	p2.sety(20);
	p.sety(30);
	p.setx(p2);
	std::cout<<p.getx().getx()<<"\n";
	std::cout<<p.gety();
	return 0;
}
