#ifndef STUDENTBST_H
#define STUDENTBST_H
#include"StudentNode.h"

class StudentBST
{
private:
	StudentNode *root; // Pointer to the root node of the tree
	void inOrder (StudentNode* s);	//Task # 1.2
	void destroy (StudentNode* s);	//Task # 1.3
public:
	StudentBST(); // Default constructor
	bool insert (int rn, string n, double c);	//Task # 1.1
	bool search (int rn);	//Task # 1.1
	void inOrder ();	//Task # 1.2
	~StudentBST ();	//Task # 1.3
	bool remove (int rn);
};
#endif

