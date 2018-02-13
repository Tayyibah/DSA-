#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include"Node.h"
class LinkedList
{
private:
	Node * head;
public:
	LinkedList();
	void display();
	void insertEnd(int val);
	void insertStart(int val);
	void sortedInsert(int val);
	void unSortedInsert(int val);
	LinkedList(const LinkedList &orig);
	bool remove(int val);
	bool sortedRemove(int val);
	LinkedList operator=(LinkedList& val);
	~LinkedList();
};
#endif
