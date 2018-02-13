#include "Stack.h"
bool Stack::push(int val)
{
	if(isFull())
	{
		return false;
	}
	else
	{
		top++;
		arr[top]=val;
		return true;
	}
}
bool Stack::pop(int &val)
{
	if(isEmpty())
	{
		return false;
	}
	else
	{
		val=arr[top];
		top--;
		return true;
	}
}
bool Stack::getTop(int &val)
{
	if(isEmpty())
	{
		return false;
	}
	else
	{
		val=arr[top];
		return true;
	}
}
bool Stack::isEmpty()
{
	if(top==-1)
		return true;
	else
		return false;
}
bool Stack::isFull()
{
	if(top==maxSize-1)
		return true;
	else
		return false;
}
Stack Stack::operator=(Stack& val)
{
	if (val.arr==0)
	{
		arr=0;
		maxSize=0;
		return 0;
	}
	maxSize=val.maxSize;
	arr=new int [maxSize];
	arr=val.arr;
	top=val.top;
	return *this;
}
Stack::Stack(Stack&ref)
{
	maxSize=ref.maxSize;
	arr=new int [maxSize];
	arr=ref.arr;
	top=ref.top;
}

