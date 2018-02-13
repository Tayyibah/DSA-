#ifndef FULLBINARYTREE_H
#define FULLBINARYTREE_H

class FullBinaryTree
{
private:
	int * tree; // Array containing the elements of full binary tree
	int treeSize; // Size of the array ‘tree’
	int * sorted; // Array to store the numbers in sorted order
	int sortSize; // Size of the array ‘sorted’
	int E; // A value larger than all the elements which are to be sorted
public:
	FullBinaryTree(int n);
	FullBinaryTree();
	~FullBinaryTree();
	void loadValues(int * arr, int n);
	void sortValues();
	void display();
};
#endif
