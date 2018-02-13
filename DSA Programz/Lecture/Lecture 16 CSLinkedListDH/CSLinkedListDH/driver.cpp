#include<iostream>
using namespace std;
#include"Node.h"
#include"CSLinkedListDH.h"
int main()
{
	CSLinkedListDH list;
	list.insert(90);
	list.insert(102);
	list.display();
	list.remove(102);
	list.display();
	return 0;
}