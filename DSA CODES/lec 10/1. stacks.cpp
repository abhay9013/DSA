class stack{
	private:
		int *data;
		int next;
		int cap;
	public:
		stack(int x)
		{
			data=new int[x];
			next=0;
			cap=x;
		}
		int size()
		{
			return next;
		}
		bool isempty()
		{
			return next==0;
		}
		void push(int ele)
		{
			if(next==cap)
			{
				cout<<"stack full"<<endl;
			}
			else{
			data[next]=ele;
			next++;}
		}
		int pop()
		{
			if(isempty())
			{
				cout<<"stack is empty"<<endl;
				return INT_MIN;
			}
			next--;
			return data[next];
		}
		int top()
		{
			if(isempty())
			{
				cout<<"stack is empty0"<<endl;
				return INT_MIN;
			}
			return data[next-1];
		}
};

int main()
{
	stack s1(4);
	s1.push(10);
	s1.push(15);
	s1.push(20);
	s1.push(25);
	s1.push(30);
	cout<<s1.top()<<endl;
	cout<<s1.pop()<<endl;
	cout<<s1.pop()<<endl;
	cout<<s1.size()<<endl;
	cout<<s1.isempty();
	return 0;
}
