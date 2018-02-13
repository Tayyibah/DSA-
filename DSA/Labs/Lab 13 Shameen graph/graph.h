﻿#ifndef GRAPH_H
#define GRAPH_H
class Graph 
{
private:
	int ** adjMatrix; // Adjacency matrix of the graph
	int maxVertices; // Max number of vertices which can be present in the graph
	int n; // Current number of vertices present in the graph
	bool* visited; // Array to keep track of visited/unvisited vertices
public:
	Graph (int maxV, int currV);
	~Graph (); 
	bool addVertex (int& v);
	bool addEdge (int u, int v); 
	bool removeEdge (int u, int v); 
	bool isEmpty ();
	bool isComplete ();
	void clear ();
	void display ();
	int inDegree (int v);
	int outDegree (int v);
	void findUniversalVertex ();
	void findIsolatedVertex ();
};
#endif