#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include"Node.h"
class LinkedList
{
private:
	Node * head;
	void displayRecursively(Node * t);
	int findRecursively(Node * t);
public:
	LinkedList();
	void display();
	void insertEnd(int val);
	void insertStart(int val);
	void sortedInsert(int val);
	void unSortedInsert(int val);
	int findLargest();
	bool remove(int val);
	bool sortedRemove(int val);
	void displayRecursiveCall();
	int findRecursiveCall();
	LinkedList(const LinkedList &orig);
	LinkedList operator=(LinkedList& val);
	~LinkedList();
};
#endif

