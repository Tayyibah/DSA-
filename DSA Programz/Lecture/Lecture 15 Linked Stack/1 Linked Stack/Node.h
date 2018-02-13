#ifndef NODE_H
#define NODE_H
class LinkedStack;
class Node
{
friend class LinkedStack;
private:
	int data;
	Node * next;
};
#endif

