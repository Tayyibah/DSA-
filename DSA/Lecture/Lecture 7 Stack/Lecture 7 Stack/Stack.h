#ifndef STACK_H
#define STACK_H
#include<iomanip>
#include<fstream>
#include<iostream>
using namespace std;
class Stack
{
private:
	int *arr;
	int maxSize;
	int top;
public:
	Stack(int size)
	{
		if(size<0)
			size=0;
		maxSize=size;
		arr=new int[maxSize];
		top=-1;
	}
	~Stack()
	{
		if(arr)
			delete[]arr;
		arr=0;
		maxSize=0;
		top=0;
	}
	bool push(int val);
	bool pop(int &val);
	bool getTop(int &val);
	bool getTop(char &val);
	bool isEmpty();
	bool isFull();
	Stack operator=(Stack& val);
	Stack(Stack&ref);
};
#endif

