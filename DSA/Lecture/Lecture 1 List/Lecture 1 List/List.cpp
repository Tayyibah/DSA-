#include<iostream>
using namespace std;
#include"List.h"

List::List()
{
	maxSize=0;
	a=new int [maxSize];
	currSize=0;
}
List::List(int n)
{
	maxSize=n;
	a=new int [maxSize];
	currSize=0;
}
List::~List()
{
	if(a!=0)
	{
		delete[]a;
		a=0;
	}
	maxSize=0;
	currSize=0;
}
bool List::insert(int val)
{
	if(currSize==maxSize)
		return false;
	else
	{
		a[currSize]=val;
		currSize++;
		return true;
	}
}
bool List::getValue(int index,int &val)
{
	if(index>=0&&index<=currSize)
	{
		val=a[index];
		return true;
	}
	else
		return false;
}
void  List::displayArray()
{
	for(int i=0;i<currSize;i++)
	{
		cout<<a[i]<< " ";
	}
	cout<<endl;
}
bool List::removeValue1(int index,int val)
{
	if(index<0&&index>currSize)
		return false;
	else
	{
		for(int i=0;i<currSize;i++)
		{
			if(a[i]==val)
			{
				a[i]=a[currSize-1];
				currSize--;
				return true;
			}
		}
	}
}
bool List::removeValue2(int index,int val)
{
	if(index<0&&index>currSize)
		return false;
	else
	{
		for(int i=0;i<currSize;i++)
		{
			if(a[i]==val)
			{
				for(int j=i;j<currSize;j++)
				{
					a[i]=a[j++];
				}
				currSize--;
				return true;
			}
		}
	}
}
bool List::removeAllVerson1(int val)
{
	int i=0 ,j=0 , count=0;
	while(i<currSize)
	{
		if(a[i]==val)
		{
			count++;
			j=i;
			while(j<currSize-1)
			{
				a[j]=a[j++];
				j++;
			}
			currSize--;
		}
		else
			i++;
	}
	return count;
}

bool List::removeAllVerson2(int val)//not right
{
	int i=0 ,j=0 , count=0;
	while(i<currSize)
	{
		if(a[i]==val)
		{
			a[i]=a[currSize-1];
			currSize--;
		}
		else
			i++;
	}
	return count;
}

bool List::removeAllVerson(int val)//not right
{
	int i=0 ,j=0 , count=0;
	while(j<currSize)
	{
		if(a[i]==val)
		{
			a[i]=a[j];
			i++;
			j++;
		}
		else
		{
			j++;
			count++;
		}
		currSize-=count;
	}
	return count;
}
List List::operator=(List& val)
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
List::List(List&ref)
{
	maxSize=ref.maxSize;
	a=new int [maxSize];
	a=ref.a;
	currSize=ref.currSize;
}







