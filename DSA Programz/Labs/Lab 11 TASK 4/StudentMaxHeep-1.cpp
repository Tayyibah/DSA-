#include <iostream>
#include "StudentMaxHeep.h"
using namespace std;

StudentMaxHeap::StudentMaxHeap(int size)
{
	st = new Student[size+1];
	currSize = 0;
	maxSize = size;
}
StudentMaxHeap::~StudentMaxHeap()
{
	if (st)
		delete[]st;
	st = 0;
}
bool StudentMaxHeap::isEmpty()
{
	return currSize == 0;
}
bool StudentMaxHeap::isFull()
{
	return currSize == maxSize;
}
void StudentMaxHeap::display()
{
	for (int i = 1; i <= currSize; i++)
	{
		cout << st[i].rollNo << "   ";
		cout << st[i].cgpa << "   ";
		cout << endl;
	}
	cout << endl;
}
bool StudentMaxHeap::insert(int rollNo, double cgpa)
{

	if (isFull())
		return false;
	currSize++;
	int i = currSize;
	while (i>1 && (cgpa>=st[i / 2].cgpa && rollNo<st[i/2].rollNo))
	{
		/*st[i].cgpa = st[i / 2].cgpa;
		st[i].rollNo = st[i / 2].rollNo;*/
		st[i] = st[i / 2];
		i = i / 2;
	}
	st[i].cgpa = cgpa;
	st[i].rollNo = rollNo;
	return true;
}
void StudentMaxHeap::heepify(int i)
{
	int left, right, largest;
	while (i * 2 <= currSize)
	{
		left = i * 2;
		right = i * 2 + 1;
		largest = i;
		if (st[left].cgpa > st[largest].cgpa)
			largest = left;
		if (right <= currSize && st[right].cgpa > st[largest].cgpa)
			largest = right;
		if (largest != i)
		{
			swap(st[i], st[largest]);
			i = largest;
		}
		else
			break;
	}
}
bool StudentMaxHeap::removeMax(Student & max)
{
	if (isEmpty())
		return false;
	max = st[1];
	st[1] = st[currSize--];
	heepify(1);
	return true;
}