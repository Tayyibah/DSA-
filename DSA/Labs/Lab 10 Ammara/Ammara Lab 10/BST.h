#ifndef BST_H
#define BST_H
class BSTNode
{
	friend class BST;
 private:
		int data;
		BSTNode *left, *right;
		
};
class BST 
{
private:
	BSTNode *root;
	void destroy(BSTNode * s);
	void inOrder (BSTNode * t);
	void postOrder(BSTNode * t);
	void preOrder(BSTNode * t);
	int countNodes (BSTNode* b);
	bool recSearch (BSTNode* b, int key);
	void doubleTree(BSTNode * t);
	void printPathsRecur(BSTNode * temp, int path[],int pathSize);
	void printArray(int path[],int pathLen);
public:
	BST();
	~BST();
	bool insert(int val);
	bool remove (int val);
	bool search(int key);
	void inOrder ();
	void postOrder();
	void preOrder();
	int countNodes (); // public (driver function)
	bool recSearch (int key); // public (driver function)
	void doubleTree();
	void printAllPaths();

};

#endif