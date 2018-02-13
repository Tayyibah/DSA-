#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H
#include"Node.h"
class LinkedStack
{
private:
	Node * top;
public:
	LinkedStack();
	void display();
	bool push(int val);
	bool pop(int &val);
	bool isEmpty();
	bool remove(int val);
	bool getTop(int &val);
	LinkedStack(const LinkedStack & orig);
	LinkedStack operator=(LinkedStack& val);
	~LinkedStack();
};
#endif

