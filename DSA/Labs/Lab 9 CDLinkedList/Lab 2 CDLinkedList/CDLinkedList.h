#ifndef CDLINKEDLIST_H
#define CDLINKEDLIST_H
#include"DNode.h"
class CDLinkedList
{
private:
	DNode  head;
	void mergeSort (DNode *t);
	int findMax(DNode * temp);
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
	bool insert1(int val);
	bool remove2(int val);
	bool checkSort ();
	int findMax ();
	bool merge (CDLinkedList& list1, CDLinkedList& list2);
	void splitList (CDLinkedList& leftHalf, CDLinkedList& rightHalf);
	void mergeSort ();
};
#endif
