#ifndef NODE_H
#define NODE_H
class LinkedQueue;
class Node
{
friend class LinkedQueue;
private:
	int data;
	Node * next;
};
#endif

