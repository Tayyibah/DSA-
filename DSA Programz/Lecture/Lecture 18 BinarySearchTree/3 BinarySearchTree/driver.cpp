#include<iostream>
using namespace std;
#include"TreeNode.h"
#include"BinaryTree.h"
#include"BST.h"
int main()
{ 
	BinaryTree BT;
	//BT.preOrder();
	//BT.postOrder();
	//BT.inOrder();
	//BT.levelOrderTraversal();
	BST tree;
	int val=2;
	tree. insert(6) ;
	tree. insert(7) ;
	tree. insert(5) ;
	tree. search(3) ;
	tree. insert(1) ;
	tree. insert(2) ;
	BT. insert(3) ;
	BT. insert(4) ;
	BT. insert(1) ;
	BT. insert(2) ;
	BT. insert(5) ;
	cout<<"levelOrderTraversal of BT is: ";
	tree.levelOrderTraversal();
	/*cout<<"preOrder of BT is: ";
	tree. preOrder();
	cout<<endl<<"postOrder of BT is: ";
	tree. postOrder();
	cout<<endl<<"inOrder of BT is: ";
	tree. inOrder();
	cout<<endl;
	cout<<"preOrder of tree is: ";
	tree. preOrder();
	cout<<endl<<"postOrder of tree is: ";
	tree. postOrder();
	cout<<endl<<"inOrder of tree is: ";
	tree. inOrder();
	cout<<endl;
	val=1;
	tree. remove(val);
	cout<<"Removing value "<<val<<endl;
	cout<<"preOrder of tree is: ";
	tree. preOrder();
	cout<<endl<<"postOrder of tree is: ";
	tree. postOrder();
	cout<<endl<<"inOrder of tree is: ";
	tree. inOrder();
	cout<<endl;
	cout<<"Min value is ";
	cout<<tree. findMin();
	cout<<endl;
	cout<<"Max value is ";
	cout<<tree. findMax();
	cout<<endl;*/
	return 0;
}