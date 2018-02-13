#include<iostream>
using namespace std;
#include"Node.h"
#include"LinkedQueue.h"
int main()
{
	LinkedQueue list;
	list.display();
	list.enqueue(10);
	list.enqueue(101);
	list.enqueue(102);
	list.display();
	int vl=0;
	list.dequeue(vl);
	list.display();
	cout<<vl<<endl;
	return 0;
}