#ifndef DEQUE_H
#define DEQUE_H
class Deque
{
private:
	int *dq;
	int maxSize;
	int currSize;
	int front;
	int back;
public:
	Deque (int n); 
	~Deque ();
	bool isEmpty ();
	bool isFull ();
	void display ();
	bool insertAtFront (int val);
	bool insertAtBack (int val);
	bool removeFromFront (int& val);
	bool removeFromBack (int& val);
};
# endif