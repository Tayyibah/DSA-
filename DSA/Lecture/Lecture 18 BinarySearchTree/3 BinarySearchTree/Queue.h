#ifndef QUEUE_H
#define QUEUE_H
using namespace std;
#include<new>
#include<cstdlib>
template<class T>
class Queue
{
private:
	T *arr;
	int maxSize;
	int currSize;
	int front,back;
public:
	Queue()
	{
		maxSize=0;
		arr=new T[maxSize];
		currSize=0;
		front=0;
		back=-1;
	}
	Queue(T size)
	{
		if(size<0)
			size=0;
		maxSize=size;
		arr=new T[maxSize];
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
	bool enqueue(T val)
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

	bool dequeue(T &val)
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
	bool isEmpty()
	{
		if(currSize==0)
			return true;
		else
			return false;
	}
	bool isFull()
	{
		if(currSize==maxSize)
			return true;
		else
			return false;
	}
	T operator=(T& val)
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
		arr=new T [maxSize];
		arr=val.arr;
		currSize=val.currSize;
		back=val.back;
		front=val.front;
		return *this;
	}
	Queue(T&ref)
	{
		maxSize=ref.maxSize;
		arr=new T [maxSize];
		arr=ref.arr;
		currSize=ref.currSize;
		back=ref.back;
		front=ref.front;
	}
};
#endif
