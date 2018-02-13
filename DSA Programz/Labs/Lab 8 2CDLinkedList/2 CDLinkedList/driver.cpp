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
	/*list.remove(102);
	list.remove(1);
	list.remove(2);
	list.remove(9);
	list.display();*/
	CDLinkedList list1;
	list1.insert(11);
	list1.insert(21);
	list1.insert(31);
	list1.insert(41);
	list1.display();
	//int val=0;
	//list.removeKthNode (1,val);
	//cout<<val<<endl;
	//list.display();
	//list.removeLastNode (val);
	//cout<<val<<endl;
	//list.display();
	//list.removeSecondLastNode (val);
	//cout<<val<<endl;
	//list.display();
	//
	//list.combine (list,list1);
	//list.display();
	list.shuffleMerge (list,list1);
	list.display();
	return 0;
}