#ifndef NODE_H
#define NODE_H
class CSLinkedListDH;
class Node
{
friend class CSLinkedListDH;
private:
	int data;
	Node *next;
};
#endif

