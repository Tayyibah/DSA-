#include<iostream>
using namespace std;
#include"Node.h"
#include"LinkedList.h"
int main()
{
	LinkedList list;
	list.display();
	list.insertEnd(101);
	list.insertStart(102);
	list.sortedInsert(10);
	list.display();
	list.unSortedInsert(102);
	list.display();
	list.remove(102);
	list.display();
	list.sortedRemove(102);
	list.display();
	return 0;
}