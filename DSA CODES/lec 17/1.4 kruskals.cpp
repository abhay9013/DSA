#include<iostream>
#include<algorithm>
using namespace std;
class edge{
	public:
		int source;
		int dest;
		int weight;
};
bool compare(edge e1,edge e2)
{
	return e1.weight<e2.weight;
}
int findparent(int x,int* parent)
{
	if(parent[x]==x)
	{
		return x;
	}
	return findparent(parent[x],parent);
}
void kruskals(edge* input,int n,int e)
{
	sort(input,input+e,compare);
	
	edge* output=new edge[n-1];
	int* parent=new int[n];
	for(int i=0;i<n;i++)
	{
		parent[i]=i;
	}
	int count=0;
	int i=0;
	while(count!=n-1)
	{
		edge currentedge=input[i];
		int sp=findparent(currentedge.source,parent);
		int dp=findparent(currentedge.dest,parent);
		if(sp!=dp)
		{
			output[count]=currentedge;
			count++;
			parent[sp]=dp;
		}
		i++;
	}
	for(int i=0;i<n-1;i++)
	{
		if(output[i].source<output[i].dest)
		{
			cout<<output[i].source<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
		}
		else
		{
			cout<<output[i].dest<<" "<<output[i].source<<" "<<output[i].weight<<endl;
		}
	}
}
int main()
{
	int n,e;
	cin>>n>>e;
	edge* input=new edge[e];
	
	for(int i=0;i<e;i++)
	{
		int s,d,w;
		cin>>s>>d>>w;
		input[i].source=s;
		input[i].dest=d;
		input[i].weight=w;	
	}
	kruskals(input,n,e);
}

