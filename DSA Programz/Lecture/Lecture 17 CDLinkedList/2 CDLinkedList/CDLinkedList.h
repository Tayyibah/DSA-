#ifndef CDLINKEDLIST_H
#define CDLINKEDLIST_H
#include"DNode.h"
class CDLinkedList
{
private:
	DNode  head;
public:
	CDLinkedList();
	void display();
	bool remove(int val);
	bool insert(int val);
	CDLinkedList(const CDLinkedList &orig);
	~CDLinkedList();
	CDLinkedList operator=(CDLinkedList & val);
};
#endif

