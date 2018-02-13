#include<iostream>
using namespace std;
#include"Node.h"
#include"LinkedList.h"
int main()
{
	LinkedList list;
	list.display();
	list.insertStart(101);
	list.display();
	list.remove(102);
	list.display();
	return 0;
}