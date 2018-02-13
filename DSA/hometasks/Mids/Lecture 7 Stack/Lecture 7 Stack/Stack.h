#ifndef STACK_H
#define STACK_H
#include<iomanip>
#include<fstream>
#include<iostream>
using namespace std;
class Stack
{
private:
	int *Items;
	int MaxStack;
	int Top;
public:
	Stack(int size)
	{
		if(size<0)
			size=0;
		MaxStack=size;
		Items=new int[MaxStack];
		Top=-1;
	}
	~Stack()
	{
		if(Items)
			delete[]Items;
		Items=0;
		MaxStack=0;
		Top=0;
	}
void Retrieve(char &X, int &Success);
	void Push(char X, int &Success);
	void Pop(char &val, int &Success);
	bool GetTop(int &val);
	bool getTop(char &val);
	int IsEmpty();
	int IsFull();
	Stack operator=(Stack& val);
	Stack(Stack&ref);
};
#endif

