#ifndef LIST_H
#define LIST_H
#include"Node.h"
class List
{
public:
	List();
	void add(int addObject);
	Node * get();
	bool next();
	friend void traverse(List list);
	friend List addNodes();
private:
	Node * headNode;
	Node * currentNode;
	Node * lastCurrentNode;
	int size;
};
#endif

