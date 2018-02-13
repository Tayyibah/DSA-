#include<iostream>
using namespace std;
#include"Node.h"
#include"LinkedStack.h"
int main()
{
	LinkedStack list;
	list.display();
	list.push(10);
	list.push(101);
	list.push(102);
	list.display();
	int vl=0;
	list.pop(vl);
	list.display();
	cout<<vl<<endl;
	vl=0;
	list.getTop(vl);
	cout<<vl<<endl;
	return 0;
}