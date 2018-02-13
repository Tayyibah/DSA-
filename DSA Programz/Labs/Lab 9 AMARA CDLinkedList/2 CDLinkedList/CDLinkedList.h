#ifndef CDLINKEDLIST_H
#define CD LINKEDLIST_H

class CDLinkedList ;

class DNode
{
	friend class CDLinkedList ;
private:
	DNode * next ;
	DNode * prev ;
	int data ;
};

class CDLinkedList
{
private:
	DNode head ;
	bool checkSort ();
	int findMax (DNode *temp);
public:
	CDLinkedList();
	

	void display();
	bool insert(int val);
	bool remove(int val);
	bool insert1(int val);
	bool remove2(int val);

	CDLinkedList(const CDLinkedList & orig);
	//~CDLinkedList();
	bool removeLastNode (int& val);
	bool removeSecondLastNode (int& val);
	bool removeKthNode (int& val,int k);
	void combine (CDLinkedList &node1, CDLinkedList &node2);
	void shuffleMerge (CDLinkedList &node1, CDLinkedList &node2);
	bool  merge (CDLinkedList& list1, CDLinkedList& list2);
	int findMax ();
	void splitList (CDLinkedList& leftHalf, CDLinkedList& rightHalf);
	void mergeSort ();
	void mergeSort (DNode *t);
};
#endif