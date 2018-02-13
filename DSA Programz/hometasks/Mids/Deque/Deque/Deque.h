#ifndef QUEUE_H
#define QUEUE_H
using namespace std;
class Queue
{
private:
	int *arr;
	int maxSize;
	int currSize;
	int front,back;
public:
	Queue(int size)
	{
		if(size<0)
			size=0;
		maxSize=size;
		arr=new int[maxSize];
		currSize=0;
		front=0;
		back=-1;
	}
	~Queue()
	{
		if(arr)
			delete[]arr;
		arr=0;
	}
	bool enqueue(int val);
	bool dequeue(int &val);
	bool isEmpty();
	bool isFull();
	Queue operator=(Queue& val);
	Queue(Queue&ref);
};
#endif

