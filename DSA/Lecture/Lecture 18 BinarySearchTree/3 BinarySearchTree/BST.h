#ifndef BST_H
#define BST_H
#include"TreeNode.h"
#include "Queue.h"
class BST
{
private:
	TreeNode  *root;
	void preOrder(TreeNode  *t);//called by destructor
	void postOrder(TreeNode  *t);//called by destructor
	void inOrder(TreeNode  *t);//called by destructor
	void destroy(TreeNode  *t);//called by destructor postorderly       //makeEmpty()
	TreeNode  *copy(TreeNode  * ref);//called by copy constructer preorderly            //WorkHorse
	int  equal(TreeNode  * a,TreeNode  * b);//called by ==operator           //WorkHorse
	TreeNode * clone(TreeNode *t)const;		//called by operator=
	TreeNode * findMin(TreeNode  *t)const;
	TreeNode * findMax(TreeNode  *t)const;
public:
	BST();
	bool isEmpty()
	{
		return root==NULL;
	}
	bool search(int key);
	bool insert(int val);
	bool remove(int val);
	void preOrder();
	void postOrder();
	void inOrder();
	void levelOrderTraversal();
	BST(BST&ref);
	int findMin();
	int findMax();
	friend int operator==(const BST & s,const BST & t);
	~BST();
	BST operator=(BST & val);
	const int &elementAt(TreeNode  *t)const;

};
#endif
