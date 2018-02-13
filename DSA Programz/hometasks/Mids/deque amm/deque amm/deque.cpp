#include<iostream>
#include "deque.h"
using namespace std;
Deque :: Deque (int n)
{
	maxSize=n;
	dq=new int[maxSize];
	currSize=0;
	back=-1;
	front=0;
}
Deque :: ~Deque ()
{
	if (dq)
	{
		delete [] dq;
		dq=0;
	}
}
bool Deque :: isEmpty ()
{
	if (currSize==0)
		return true;
	else 
		return false;
}
bool Deque :: isFull ()
{
	if (currSize==maxSize)
		return true;
	else
		return false;
}
void Deque :: display ()
{
	cout<<"indisplay"<<endl;
	for (int i=0; i<currSize;i++)
	{
		
		cout<<dq[i]<<" ";
	}
}
bool Deque :: insertAtFront (int val)
{
	if(isFull())
	{
		return false;
	}
	else
	{
		dq[front]=val;
		front++;
		if(front==maxSize)
		{
			front=0;
		}
		currSize++;
		return true;
	}

}
bool Deque :: insertAtBack (int val)
{
	if (isFull())
	{
		return false;
	}
	else
	{
		back++;
		if(back==maxSize)
		{
			back=0;
		}
		dq[back]=val;
		currSize++;
		return true;
	}
}
bool Deque :: removeFromFront (int& val)
{
	if (isEmpty())
	{
		return false;
	}
	else
	{
		val=dq[front];
		front++;
		if(front==maxSize)
		{
			front=0;
		}
		currSize--;
		return true;
	}
}
bool Deque :: removeFromBack (int& val)
{
	if (isEmpty())
	{
		return false;
	}
	else
	{
		val=dq[back];
		back--;
		if(back<0)
		{
			back=maxSize-1;
		}
		currSize--;
		return true;
	}
}