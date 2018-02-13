#ifndef BSTNODE_H
#define BSTNODE_H
class BinaryTree;
class BST;
class BSTNode
{
friend class BinaryTree;
friend class BST;
private:
	int data;
	BSTNode *left;
	BSTNode *right;
};
#endif

