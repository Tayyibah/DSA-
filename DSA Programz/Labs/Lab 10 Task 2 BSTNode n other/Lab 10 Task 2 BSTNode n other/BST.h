#ifndef BST_H
#define BST_H
#include"BSTNode.h"
class BST
{
private:
	BSTNode  *root;
	void preOrder(BSTNode  *t);//called by destructor
	void postOrder(BSTNode  *t);//called by destructor
	void inOrder(BSTNode  *t);//called by destructor
	void destroy(BSTNode  *t);//called by destructor postorderly
	BSTNode  *copy(BSTNode  * ref);//called by copy constructer preorderly            //WorkHorse
	int  equal(BSTNode  * a,BSTNode  * b);//called by ==operator           //WorkHorse
	bool recSearch (int key); // public (driver function)//2.3
	int countNodes (BSTNode* b); // private (workhorse function)//2.4
	void doubleTree(BSTNode* t);//2.5
	void printPathsRecur(BSTNode * temp, int path[],int pathSize);
	void printArray(int path[],int pathLen);
public:
	BST();
	bool search(int key);
	bool insert(int val);
	bool remove(int val);
	void preOrder();
	void postOrder();
	void inOrder();
	BST(BST&ref);
	//friend int operator==(const BST & s,const BST & t);
	~BST();
	BST operator=(int & val);
	void doubleTree();//2.5
	int countNodes (); // public (driver function)//2.4
	bool recSearch (BSTNode* b, int key); // private (workhorse function)//2.3
	void printAllPaths ();//2.6
};
#endif
