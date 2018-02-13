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
	void insertStart(int val);
	bool remove(int val);
	bool removeLastNode (int& val);
	bool removeSecondLastNode (int& val);
	bool removeKthNode (int k, int& val);
	void combine (LinkedList& list1, LinkedList& list2);
	LinkedList(const LinkedList &orig);
	LinkedList operator=(LinkedList& val);
	bool search(int val);
	~LinkedList();
	void suffleMerge(LinkedList & list1, LinkedList & list2);
};
#endif
