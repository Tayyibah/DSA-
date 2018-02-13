#include <iostream>
using namespace std;
#include "graph.h"
void main()
{
	Graph g(3,0);
	int val;
	g.addVertex(val);
	g.addVertex(val);
	g.addVertex(val);
	g.addEdge(3,2);
	g.addEdge(1,2);
	g.addEdge(1,3);
	g.display();
	g.findIsolatedVertex();
	g.findUniversalVertex();

}