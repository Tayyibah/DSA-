#include<iostream>
using namespace std;
#include"DNode.h"
#include"CDLinkedList.h"
int main()
{
	CDLinkedList list;
	list.insert(1);
	list.insert(2);
	list.insert(3);
	list.insert(4);
	list.insert(5);
	list.insert(6);
	list.insert(7);
	list.insert(9);
	list.display();
	CDLinkedList list1;
	list1.insert(11);
	list1.insert(21);
	list1.insert(31);
	list1.insert(41);
	list1.display();
	/*int val=0;
	list.removeLastNode (val);
	list.removeSecondLastNode (val);
	list.removeKthNode (2, val);
	list.combine (list,list1);
	list.shuffleMerge (list,list1);
	list.insert1(val);
	list.remove2(val);
	list.findMax ();
	list.splitList (list,list1);
	list.mergeSort ();*/
	return 0;
}