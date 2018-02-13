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
	list.remove(102);
	list.remove(1);
	list.remove(2);
	list.remove(9);
	list.display();
	return 0;
}