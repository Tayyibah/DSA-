#ifndef DNODE_H
#define DNODE_H
class CDLinkedList;
class DNode
{
friend class CDLinkedList;
private:
	int data;
	DNode *next;
	DNode *prev;
};
#endif

