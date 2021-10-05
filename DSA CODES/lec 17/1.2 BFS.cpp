#include<iostream>
#include<queue>
using namespace std;

void print(int** edges,int n,int sv, bool* visited)
{
	cout<<sv<<endl;
	visited[sv]=true;
	for(int i=0;i<n;i++)
	{
		if(i==sv){
			continue;
		}
		if(edges[sv][i]==1)
		{
			if(visited[i])
			{
				continue;
			}
			print(edges,n,i,visited);
		}
	}
}
void printbfs(int** edges,int n,int sv)
{
	queue<int> pvertices;
	bool* visited=new bool[n];
	for(int i=0;i<n;i++)
	{
		visited[i]=false;
	}
	pvertices.push(sv);
	visited[sv]=true;
	while(!pvertices.empty())
	{
		int cvertex=pvertices.front();
		pvertices.pop();
		cout<<cvertex<<endl;
		for(int i=0;i<n;i++)
		{
			if(cvertex==i)
			{
				continue;
			}
			if(edges[cvertex][i]==1&&!visited[i])
			{
				pvertices.push(i);
				visited[i]=true;
			}
		}
	}
	delete [] visited;
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
		int f,s;
		cin>>f>>s;
		edges[f][s]=1;
		edges[s][f]=1;
	}
	
	bool* visited=new bool[n];
	for(int i=0;i<n;i++)
	{
		visited[i]=0;
	}
	cout<<"DFS"<<endl;
	print(edges,n,0,visited);
	cout<<"BFS"<<endl;
	printbfs(edges,n,0);
	
	delete [] visited;
	for(int i=0;i<n;i++)
	{
		delete [] edges[i];
	}
}
