#include "graph.h"
#include <iostream>
using namespace std;
Graph::  Graph (int maxV, int currV)
{
	if(maxV<=0 || currV <0)
	{
		maxVertices=0;
		n=0;
		adjMatrix=0;
		visited=0;
	}
	else 
	{
		maxVertices=maxV;
		n=currV;
		adjMatrix=new int * [maxVertices];
		for (int i=0;i<maxVertices; i++)
		{
			adjMatrix[i]=new int [maxVertices];
			for (int j=0;j<maxVertices; j++)
			{
				adjMatrix[i][j]=0;
			}
		}
		visited=new bool [maxVertices];
		for (int j=0;j<maxVertices; j++)
		{
			visited[j]=0;
		}
	}
}
Graph::~Graph () // Destructor
{
	for (int i=0;i<maxVertices; i++)
	{
		delete [] adjMatrix[i];
		adjMatrix[i]=0;
	}
	delete [] visited;
	visited=0;
	delete [] adjMatrix;
	adjMatrix=0;
	maxVertices=0;
	n=0;
}
bool  Graph::addVertex (int & v)
{
	if (n== maxVertices)
		return false;
	n++;
	v=n;
	return true;
}
bool Graph:: addEdge (int u, int v) // Adds the edge <u,v> to the graph
{
	if(u>0 && v>0 && u<=maxVertices && v<=maxVertices)
	{
		if(adjMatrix[u-1][v-1]==1)
		{
			cout<<"already existed\n";
			return false;
		}
		else 
		{
			adjMatrix[u-1][v-1]=1;
			return true;
		}
	}
	else
		return false;
}
bool Graph:: removeEdge (int u, int v) // Removes the edge <u,v> from the graph
{
	if(u>0 && v>0 &&u<=maxVertices && v<=maxVertices)
	{
		if(adjMatrix[u-1][v-1]==0)
		{
			cout<<"not existed\n";
			return false;
		}
		else 
		{
			adjMatrix[u-1][v-1]=0;
			return true;
		}
	}
	else
		return false;
}
bool Graph:: isEmpty ()
	//	This function will return true if the graph is empty, it will return false otherwise. A graph is said
	//	to be empty if there are no edges in the graph.
{
	for (int i=0;i<maxVertices; i++)
	{
		for (int j=0;j<maxVertices; j++)
		{
			if (adjMatrix[i][j]!=0)
			{
				return false;
			}
		}
	}
	return true;
}
bool Graph:: isComplete ()
	//	This function will return true if the graph is complete, it will return false otherwise.
{
	for (int i=0;i<n; i++)
	{
		for (int j=0;j<n; j++)
		{
			if(i!=j)
			{
				if(adjMatrix[i][j]==0)
				{
					return false;
				}
			}
		}
	}
	return true;
}
void Graph:: clear ()
	//	This function will remove all edges from the graph. Vertices will NOT be removed.
{
	for (int i=0;i<n; i++)
	{
		for (int j=0;j<n; j++)
		{

			adjMatrix[i][j]=0;
		}
	}
}
void Graph:: display ()
	//	This function will display the adjacency matrix of the graph on the screen in a neat and readable
	//	way. Only data of first n vertices should be displayed (where n is the current number of vertices
	//	present in the graph).
{	
	for (int i=0;i<n; i++)
	{
		for (int j=0;j<n; j++)
		{
			cout<<adjMatrix[i][j]<<"\t";
		}
		cout<< endl;
	}
}
int Graph:: outDegree (int v)
	//	This function will determine and return the in-degree of the vertex v. It will return ‐1 if v is
	//	invalid.
{
	if(v<=0 || v>n)
	{
		return -1;
	}

	else
	{
		int outdegree=0;
		int i=v-1;
		for (int j=0;j<n; j++)
		{
			if(adjMatrix[i][j]==1)
			{
				outdegree++;
			}
		}
		return outdegree;
	}
}
int Graph:: inDegree (int v)
	//This function will determine and return the out-degree of the vertex v. It will return ‐1 if v is invalid.
{
	if(v<=0 || v>n)
	{
		return -1;
	}

	else
	{
		int indegree=0;
		int j=v-1;
		for (int i=0;i<n; i++)
		{

			if(adjMatrix[i][j]==1 )
			{
				indegree++;
			}

		}
		return indegree;
	}
}
void Graph:: findUniversalVertex ()
{
	int count=0;
	for (int i=0;i<n;i++)
	{
		int j=0;
		for ( j=0;j<n; j++)
		{
			if(adjMatrix[i][j]!=1 && i!=j)
			{
				break;
			}
		}
		if(j==n)
		{
			count++;
		}
	}
	if(count==0)
	{
		cout<<"no universal vertex exist\n";
	}
	else
		cout<<"count="<<count<<"\n";
}
void Graph:: findIsolatedVertex ()
{
	int count=0;
	int indicator=0;
	for(int k=0; k<n;k++)
	{
		
		int i=k;
		int j=0;
		for ( j=0;j<n; j++)
		{
			if(adjMatrix[i][j]==1)
			{
				break;
			}
		}
		if(j==n)
		{
			indicator++;
		}

		j=k;
		i=0;
		for ( i=0;i<n; i++)
		{
			if(adjMatrix[i][j]==1)
			{
				break;
			}
		}
		if(i==n)
		{
			indicator++;
		}

		if(indicator==2)
		{
			count++;
		}
		indicator=0;
		
	}
	if(count==0)
	{
		cout<<"no Isolated vertex exist\n";
	}
	else
		cout<<"count="<<count<<"\n";
}