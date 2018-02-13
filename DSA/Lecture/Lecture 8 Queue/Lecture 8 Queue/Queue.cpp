#include "Queue.h"

bool Queue::enqueue(int val)
{
	if(isFull())
		return false;
	else
	{
		back++;
		if(back==maxSize)
			back=0;
		arr[back]=val;
		currSize++;
		return true;
	}
}
bool Queue::dequeue(int &val)
{
	if(isEmpty())
		return false;
	else
	{
		val=arr[front];
		if(front==maxSize)
			front=0;
		front++;
		arr[back]=val;
		currSize--;
		return true;
	}
}
bool Queue::isEmpty()	
{
	if(currSize==0)
		return true;
	else
		return false;
}
bool Queue::isFull()
{
	if(currSize==maxSize)
		return true;
	else
		return false;
}
Queue Queue::operator=(Queue& val)
{
	if (val.arr==0)
	{
		arr=0;
		maxSize=0;
		currSize=0;
		back=0;
		front=0;
		return 0;
	}
	maxSize=val.maxSize;
	arr=new int [maxSize];
	arr=val.arr;
	currSize=val.currSize;
	back=val.back;
	front=val.front;
	return *this;
}
Queue::Queue(Queue&ref)
{
	maxSize=ref.maxSize;
	arr=new int [maxSize];
	arr=ref.arr;
	currSize=ref.currSize;
	back=ref.back;
	front=ref.front;
}