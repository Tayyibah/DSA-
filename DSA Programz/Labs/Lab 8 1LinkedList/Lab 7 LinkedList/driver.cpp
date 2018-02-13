#include<iostream>
using namespace std;
#include"Node.h"
#include"LinkedList.h"
int main()
{
	LinkedList list1;
	LinkedList list2;
	LinkedList list3;
	list1.insertStart(1);
	list1.insertStart(5);
	list1.insertStart(2);
	list1.insertStart(9);
	list1.insertStart(0);
	list1.insertStart(2);
	list1.insertStart(9);
	list1.insertStart(1);
	list1.display();
	list2.insertStart(11);
	list2.insertStart(31);
	list2.insertStart(21);
	list2.insertStart(31);
	list2.insertStart(41);
	list2.display();
	list1.remove(3);
	int val=0;
	list1.display();
	list1.removeLastNode (val);
	list1.display();
	cout<<val<<endl;
	list1.removeSecondLastNode (val);
	list1.display();
	cout<<val<<endl;
	list1.removeKthNode (1,val);
	list1.display();
	cout<<val<<endl;
	list3.combine(list1,list2);
	list3.display();
	list1.suffleMerge(list1,list2);
	list1.display();
	return 0;
}