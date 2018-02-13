#include<iostream>
using namespace std;
#include "deque.h"
void main()
{
	int temp=3;
	Deque d(6);
	int temp2=5;
	if (d.insertAtFront(3))
	{
		cout<<"value is inserted at front"<<endl;
	}
	if (d.insertAtBack(4))
	{
		cout<<"value is inserted at end"<<endl;
	}
	if (d.removeFromFront(temp))
	{
		cout<<"value is removed from front "<<endl;
	}
	if (d.removeFromBack(temp2))
	{
		cout<<"value is removed from back "<<endl;
	}
	d.display();
}