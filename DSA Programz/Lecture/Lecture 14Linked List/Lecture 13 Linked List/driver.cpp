#include<iostream>
using namespace std;
#include"Node.h"
#include"LinkedList.h"
int main()
{
	LinkedList list;
	list.display();
	list.insertEnd(1);
	list.insertStart(12);
	list.insertStart(2);
	list.insertStart(1);
	list.sortedInsert(10);
	list.display();
	list.unSortedInsert(102);
	list.display();
	list.remove(102);
	list.display();
	list.sortedRemove(102);
	list.display();
	list.displayRecursiveCall();
	cout<<endl;
	cout<<list.findLargest()<<endl;
	cout<<list.findRecursiveCall()<<endl;
	return 0;
}