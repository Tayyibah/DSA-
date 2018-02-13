#include<iostream>
using namespace std;
#include "heap.h"
StudentMaxHeap :: StudentMaxHeap(int size)
{
	st->cgpa=0.0;
	st->rollNo=0;
	currSize=0;
	maxSize=size;
}
StudentMaxHeap :: ~StudentMaxHeap()
{
	if(st)
	{
		delete st;
		st=0;
		currSize=0;
		maxSize=0;
	}

}
bool StudentMaxHeap :: isEmpty()
{
	if (currSize==maxSize)
	{
		return false;
	}
	return true;
}
bool StudentMaxHeap:: isFull()
{
	if (currSize==maxSize)
	{
		return true;
	}
	return false;
}
bool StudentMaxHeap :: insert (int rollN, double cgp)
{
	if(isFull())
	{
		return false;
	}
	else
	{
		currSize++;
		st[currSize].cgpa=cgp;
		int i=currSize;
		while(i>1 && cgp>=st[i/2].cgpa && rollN<st[i/2].rollNo)
		{
			st[i].cgpa=st[i/2].cgpa;
			st[i].rollNo=st[i/2].rollNo;
			i=i/2;
		}
		st[i].cgpa=cgp;
		st[i].rollNo=rollN;
		return true;
	}
} 
bool StudentMaxHeap:: removeBestStudent (int& rollN, double& cgp)
{
	if(isEmpty())
	{
		return false;
	}
	rollN=st[1].rollNo;
	cgp=st[1].cgpa;
	currSize--;
	int i=1;
	int left;
	int right;
	int largest;
	while(i*2<=currSize)
	{
		largest=i;
		left=2*i;
		right=2*i+1;
		if (st[left].cgpa>st[largest].cgpa)
		{
			largest=left;
		}
		else if (right <=currSize && st[right].cgpa>st[largest].cgpa)
		{
			largest=right;
		}
		if(largest!=i)
		{
			swap (st[i],st[largest]);
		}
		else 
			return true;
	}
	return true;
}
void StudentMaxHeap :: swap(Student & a,Student &b)
{
	Student temp;
	temp=a;
	a=b;
	b=temp;
}
