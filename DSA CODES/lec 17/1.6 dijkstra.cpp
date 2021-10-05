#include<iostream>
#include<climits>
using namespace std;

int findmin(bool* visited,int* distance,int n)
{
	int min=-1;
	for(int i=0;i<n;i++)
	{
		if(!visited[i]&&(min==-1||distance[i]<distance[min]))
		min=i;
	}
	return min;
}
void dijkstra(int** edges , int n)
{
	int* distance=new int[n];
	bool* visited=new bool[n];
	for(int i=0;i<n;i++)
	{
		visited[i]=false;
		distance[i]=INT_MAX;
	}
	distance[0]=0;
	for(int i=0;i<n;i++)
	{
		int minvertex=findmin(visited,distance,n);
		visited[minvertex]=true;
		for(int j=0;j<n;j++)
		{
			if(!visited[j]&&edges[minvertex][j]!=0)
			{
				int dist=distance[minvertex]+edges[minvertex][j];
				if(dist<distance[j])
				{
					distance[j]=dist;
				}
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<i<<" "<<distance[i]<<endl;
	}
	delete [] visited;
	delete [] distance;
}
int main()
{
	int n,e;
	cin>>n>>e;
	int** edges=new int*[n];
	for(int i=0;i<n;i++)
	{
		edges[i]=new int[n];
		for(int j=0;j<n;j++)
		{
			edges[i][j]=0;
		}
	}
	
	for(int i=0;i<e;i++)
	{
		int f,s,weight;
		cin>>f>>s>>weight;
		edges[f][s]=weight;
		edges[s][f]=weight;
	}
	cout<<endl;
	dijkstra(edges,n);
	for(int i=0;i<n;i++)
	{
		delete [] edges[i];
	}
	delete [] edges;
}

