#include<iostream>
#include<queue>
using namespace std;

void printdfs(int** edges,int n,int sv, bool* visited)
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
			printdfs(edges,n,i,visited);
		}
	}
}
void printbfs(int** edges,int n,int sv,bool* visited)
{
	queue<int> pvertices;
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
}
void bfs(int** edges, int n)
{
	bool* visited=new bool[n];
	for(int i =0;i<n;i++)
	{
		visited[i]=false;
	}
	for(int i=0;i<n;i++)
	{
		if(!visited[i])
		{
			printbfs(edges,n,i,visited);
		}
	}
	delete [] visited;
}
void dfs(int** edges, int n)
{
	bool* visited=new bool[n];
	for(int i =0;i<n;i++)
	{
		visited[i]=false;
	}
	for(int i=0;i<n;i++)
	{
		if(!visited[i])
		{
			printdfs(edges,n,i,visited);
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
	
	cout<<"DFS"<<endl;
	dfs(edges,n);
	cout<<"BFS"<<endl;
	bfs(edges,n);
	
	for(int i=0;i<n;i++)
	{
		delete [] edges[i];
	}
}
