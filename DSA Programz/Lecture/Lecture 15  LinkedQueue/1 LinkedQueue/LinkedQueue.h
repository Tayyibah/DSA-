#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H
#include"Node.h"
class LinkedQueue
{
private:
	Node * front;
	Node * back;
public:
	LinkedQueue();
	void display();
	bool enqueue(int val);
	bool dequeue(int &val);
	bool isEmpty();
	bool remove(int val);
	bool getTop(int &val);
	LinkedQueue(const LinkedQueue & orig);
	LinkedQueue operator=(LinkedQueue& val);
	~LinkedQueue();
};
#endif

