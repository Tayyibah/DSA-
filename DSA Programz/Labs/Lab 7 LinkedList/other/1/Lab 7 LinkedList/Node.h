#ifndef NODE_H
#define NODE_H
class LinkedList;
class Node
{
friend class LinkedList;
private:
	int data;
	Node * next;
};
#endif

