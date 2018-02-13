#include<iostream>
using namespace std;
#include <string.h>
#include"BSTNode.h"
#include"BST.h"

void displayMenu()
{
	cout<<"1. Insert a new student"<<endl;
	cout<<"2. Search for a student"<<endl;
	cout<<"3. See the list of all students"<<endl;
	cout<<"4. Quit"<<endl;
	cout<<"Enter your choice:";
}

int main()
{
	BST tree;
	int val=2;
	tree. search(3) ;
	tree. insert(2) ;
	tree. insert(1) ;
	tree. insert(4) ;
	tree. insert(3) ;
	tree. insert(0) ;
	tree. insert(3) ;
	tree. insert(6) ;
	tree. insert(7) ;
	cout<<"preOrder of tree is: ";
	tree. preOrder();
	cout<<"No. of nodes in tree are :"<<tree.countNodes()<<endl;
	tree.doubleTree();
	cout<<"preOrder of double tree is: ";
	tree. preOrder();
	tree.printAllPaths();
	return 0;
}