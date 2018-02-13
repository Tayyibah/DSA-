#include<iostream>
using namespace std;
#include <string.h>
#include"StudentNode.h"
#include"StudentBST.h"
#include"BSTNode.h"
#include"BST.h"


int main()
{
	StudentBST tree;
	BST treeBST;
	//tree.insert(11,"Tayyibah",2.58);
	//tree.insert(06,"Ammara Khalid",2.7);
	///*tree.insert(12,"Zainab Tayyabah",2.4);
	//tree.insert(23,"Zarbab Mushtaq",2.9);
	//tree.insert(43,"Shameen Arshad",3.3);*/
	//tree.displayInRange (2,4);
	//cout<<"Height of tree is: "<<tree.getHeight()<<endl;
	//int val=2;
	/*treeBST.search(3) ;
	treeBST.insert(2) ;
	treeBST.insert(1) ;
	treeBST.insert(4) ;
	treeBST.insert(3) ;
	treeBST.insert(0) ;
	treeBST.insert(3) ;
	treeBST.insert(6) ;
	treeBST.insert(7) ;*/
	int arr[5]={1,2,3,4,5};
	treeBST.createBalancedTree (arr,0,4);
	treeBST.inOrder() ;
	return 0;
}


//void displayMenu()
//{
//	cout<<"1. Insert a new student"<<endl;
//	cout<<"2. Search for a student"<<endl;
//	cout<<"3. See the list of all students"<<endl;
//	cout<<"4. Quit"<<endl;
//	cout<<"Enter your choice:";
//}
//
//int main()
//{
//	BST tree;
//	int val=2;
//	tree. search(3) ;
//	tree. insert(2) ;
//	tree. insert(1) ;
//	tree. insert(4) ;
//	tree. insert(3) ;
//	tree. insert(0) ;
//	tree. insert(3) ;
//	tree. insert(6) ;
//	tree. insert(7) ;
//	cout<<"preOrder of tree is: ";
//	tree. preOrder();
//	cout<<"No. of nodes in tree are :"<<tree.countNodes()<<endl;
//	tree.doubleTree();
//	cout<<"preOrder of double tree is: ";
//	tree. preOrder();
//	tree.printAllPaths();
//	return 0;
//}
