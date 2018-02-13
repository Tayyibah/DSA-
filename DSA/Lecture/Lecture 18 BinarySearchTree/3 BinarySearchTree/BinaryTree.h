#ifndef BINARYTREE_H
#define BINARYTREE_H
#include"TreeNode.h"
#include "Queue.h"

class BinaryTree
{
private:
	TreeNode  *root;
	void preOrder(TreeNode  *t);
	void postOrder(TreeNode  *t);
	void inOrder(TreeNode  *t);
	void levelOrderTraversal(TreeNode  *t);
public:
	BinaryTree();
	void preOrder();
	void postOrder();
	void inOrder();
	bool insert(int val);
	void levelOrderTraversal();
};
#endif

