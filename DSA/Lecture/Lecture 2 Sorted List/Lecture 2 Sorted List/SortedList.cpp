#include<iostream>
using namespace std;
#include"SortedList.h"

SortedList::SortedList()
{
	maxSize=0;
	a=new int [maxSize];
	currSize=0;
}
SortedList::SortedList(int n)
{
	maxSize=n;
	a=new int [maxSize];
	currSize=0;
}
SortedList::~SortedList()
{
	if(a!=0)
	{
		delete[]a;
		a=0;
	}
	maxSize=0;
	currSize=0;
}
void  SortedList::displayArray()
{
	for(int i=0;i<currSize;i++)
	{
		cout<<a[i]<< " ";
	}
	cout<<endl;
}
bool SortedList::isFull()
{
	if(currSize<0 && currSize>maxSize)
		return false;
	else
		return true;
}
bool SortedList::insert(int val)
{
	if(!isFull())
		return false;
	else
	{
		int i=currSize-1;
		while(i>=0&&a[i]>val)
		{
			a[i+1]=a[i];
			i--;
		}
		a[i+1]=val;
		currSize++;
		return true;
	}
}
bool SortedList::remove(int val)
{
	int i=0;
	bool found=false;
	while(i<currSize && !found)
	{
		if(a[i]!=val)
		{
			i++;
		}
		else
		{
			int j=i;
			found=true;
			while(j<currSize-1)
			{
				a[j]=a[j+1];
				j++;
			}
			currSize--;
		}
	}
	return found;
}
int SortedList::removeAll(int val)
{
	int i=0,count=0;
	bool found=false;
	while(i<currSize )
	{
		if(a[i]!=val)
		{
			i++;
		}
		else
		{
			count++;
			int j=i;
			while(j<currSize-1)
			{
				a[j]=a[j+1];
				j++;
			}
			currSize--;
		}
	}
	return count;
}
bool SortedList::modify(int index,int newValue)
{
	int count=0;
	bool found=false;
	int i=currSize-1;
	while(i>=0&&a[i]>newValue)
	{
		a[i+1]=a[i];
		i--;
	}
	a[i+1]=newValue;
	found=true;
	return found;
}
SortedList SortedList::operator=(SortedList& val)
{
	if (val.a==0)
	{
		a=0;
		maxSize=0;
		return 0;
	}
	maxSize=val.maxSize;
	a=new int [maxSize];
	a=val.a;
	currSize=val.currSize;
	return *this;
}
SortedList::SortedList(SortedList&ref)
{
	maxSize=ref.maxSize;
	a=new int [maxSize];
	a=ref.a;
	currSize=ref.currSize;
}







