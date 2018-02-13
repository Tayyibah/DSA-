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
	void insertStart(int val)
	{
		Node *temp=new Node;
		temp->data=val;
		temp->next=head;
		head=temp;
	}
	/*void insert(int val)
	{
		Node *temp=new Node;
		temp->data=val;
		temp->next=head;
		head=temp;
	}*/
	bool remove(int val);
	LinkedList(const LinkedList &orig);
	LinkedList operator=(LinkedList& val);
	~LinkedList();
};
#endif

