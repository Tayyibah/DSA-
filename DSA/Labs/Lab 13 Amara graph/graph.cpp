#include<iostream>
#include"graph.h"
using namespace std;
Graph :: Graph (int maxV, int currV)
{
	maxVertices=maxV;
	n=currV;
	
	adjMatrix =new int*[maxVertices];
	for (int i=0; i<maxVertices; i++)
	{
		adjMatrix[i]=new int[maxVertices];
	}
	for(int i=0; i<maxVertices;i++)
	{
		for(int j=0;j<maxVertices;j++)
		{
			adjMatrix[i][j]=0;
		}
	}
}
Graph::~Graph ()
{
	for (int i=0; i<maxVertices; i++)
	{
		delete [] adjMatrix[i];
		adjMatrix[i]=0;
	}
	delete [] adjMatrix;
	adjMatrix=0;
}
bool Graph :: addVertex (int& v)
{
	if (n==maxVertices)
	{
		return false;
	}
	else
	{
		n++;
		v=n;
		return true;
	}
}
bool Graph:: addEdge (int u, int v)
{
		adjMatrix[u][v]=1;
		return true;
}
bool Graph ::removeEdge (int u, int v)
{
		if(adjMatrix[u][v]!=0)
		{
			adjMatrix[u][v]=0;
			return true;
		}
		return false;
}
bool Graph :: isEmpty ()
{
	for (int i=0; i<n; i++)
	{
		for(int j=0 ;j<n;j++)
		{
			if(adjMatrix[i][j]!=0)
			{
				return false;
			}
		}
	}
	return true;
}
bool Graph :: isComplete ()
{
	int countEdge=0;
	int temp=n;
	temp=n-1;
	temp=temp*n;
	temp=temp/2;
	for(int i=0 ; i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(j==i)
				j++;
			if(adjMatrix[i][j]!=0)
			{
				countEdge++;

			}
		}
	}
	if(temp==countEdge)
		return true;
	else
		return false;
}
void Graph :: clear ()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			adjMatrix[i][j]=0;
		}
	}
}
int Graph:: inDegree (int v)
{
	if(v>n)
	{
		return -1;
	}
	int inDegree=0;
	for(int i=0;i<n;i++)
	{
		if(adjMatrix[i][v]==1)
		{
			inDegree++;
		}
	}
	return inDegree;
}
int Graph:: outDegree (int v)
{
	if(v>n)
	{
		return -1;
	}
	int outDegree=0;
	for(int i=0;i<n;i++)
	{
		if(adjMatrix[v][i]==1)
		{
			outDegree++;
		}
	}
	return outDegree;
}
void Graph ::findUniversalVertex ()
{
	int universal=-1;
	int countU=0;
	
	for (int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(j==i)
				j++;

			if(adjMatrix[i][j]==1)
			{
				universal=i;

			}
			else
				universal=0;
		}
		if(universal!=0)
		{
			cout<<"universal is"<<universal<<endl;
			countU++;
			cout<<"count of universal vertx is:"<<countU++;
		}
		
	}
	if(universal==-1)
		cout<<"nouniversal vrtrx exist"<<endl;
	
}
void Graph :: findIsolatedVertex ()
{
	int indegree=0;
	int outdegree=0;
	int count=0;
	for(int i=0; i<n;i++)
	{
		for(int j=0; j<n ;j++)
		{
			indegree=inDegree(i);
			outdegree=outDegree(j);
			if( indegree==outdegree)
			{
				cout<<i;
				count++;
			}

		}
	}
	cout<<"total isolated vertex are :"<<count;
}
void Graph :: display ()
{
	for (int i=0 ; i<n ; i++)
	{
		for (int j=0 ; j<n; j++)
		{
			cout<<adjMatrix[i][j]<<"  ";
		}
		cout<<endl;
	}
}