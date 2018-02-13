#ifndef TREENODE_H
#define TREENODE_H
class BinaryTree;
class BST;
class TreeNode
{
friend class BinaryTree;
friend class BST;
private:
	TreeNode()
	{
		data=0;
	}
	TreeNode(const int &val,TreeNode *leftii,TreeNode *rightii):data(val),left(leftii),right(rightii)
	{
	}
	int data;
	TreeNode *left;
	TreeNode *right;
};
#endif

