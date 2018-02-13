#ifndef STUDENTBST_H
#define STUDENTBST_H
#include"StudentNode.h"

class StudentBST
{
private:
	StudentNode *root; // Pointer to the root node of the tree
	void inOrder (StudentNode* s);	//Task # 1.2
	void destroy (StudentNode* s);	//Task # 1.3
	void preOrder(StudentNode  *t);
	void postOrder(StudentNode  *t);
	int getHeight (StudentNode* b); // private (workhorse function)
	void inOrder (StudentNode* s,double cgpaStart, double cgpaEnd);	//Task # 1.2
	void displayInRangeinOrder (StudentNode* t1 ,double cgpaStart, double cgpaEnd);
public:
	StudentBST(); // Default constructor
	bool insert (int rn, string n, double c);	//Task # 1.1
	bool search (int rn);	//Task # 1.1
	void inOrder ();	//Task # 1.2
	~StudentBST ();	//Task # 1.3
	bool remove (int rn);
	void displayInRange (double cgpaStart, double cgpaEnd);
	void preOrder();
	int getHeight (); // public (driver function)
	void postOrder();
};
#endif

