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
	bool removeLastNode (int& val);
	bool removeSecondLastNode (int& val);
	bool removeKthNode (int k, int& val);
	void combine (CDLinkedList& list1, CDLinkedList& list2);
	void shuffleMerge (CDLinkedList& list1, CDLinkedList& list2);
};
#endif
