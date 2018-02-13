#include<iostream>
using namespace std;
#include"StudentBST.h"

void StudentBST::inOrder (StudentNode* t)//Task # 1.2
{
	if(t!=0)
	{
		inOrder(t->left);
		cout<<"Student's rollNo is "<<t->rollNo<<" "<<endl;
		cout<<"Student's name is "<<t->name<<" "<<endl;
		cout<<"Student's cgpa is "<<t->cgpa<<" "<<endl;
		inOrder(t->right);
	}
}	
void StudentBST::destroy (StudentNode* s)//Task # 1.3
{
	if(s!=NULL)
	{
		destroy(s->left);
		destroy(s->right);
		delete s;
	}
	s=0;
}
StudentBST::StudentBST()// Default constructor
{
	root=0;
} 
bool StudentBST::insert (int rn, string n, double c)	//Task # 1.1
{
	StudentNode *currRollNum=root;
	StudentNode *currName=root;
	StudentNode *currCGPA=root;
	StudentNode *parent=0;
	while (currRollNum!=0)
	{
		if(rn==currRollNum->rollNo)
			return false;
		else if(rn<currRollNum->rollNo)
		{
			parent=currRollNum;
			currRollNum=currRollNum->left;
		}
		else
		{
			parent=currRollNum;
			currRollNum=currRollNum->right;
		}
	}
	currRollNum=new StudentNode;
	currRollNum->rollNo=rn;
	currRollNum->name=n;
	currRollNum->cgpa=c;
	currRollNum->left=0;
	currRollNum->right=0;
	if(parent!=0)
	{
		if(currRollNum->rollNo<parent->rollNo)
			parent->left=currRollNum;
		else
			parent->right=currRollNum;
	}
	else
	{
		root=currRollNum;
	}
	return true;
}
bool StudentBST::search (int rn)	//Task # 1.1
{
	StudentNode *curr=root;
	while (curr!=0)
	{
		if(rn==curr->rollNo)
			return true;
		else if(rn<curr->rollNo)
			curr=curr->left;
		else
			curr=curr->right;
	}
	return true;
}
void StudentBST::inOrder ()	//Task # 1.2
{
	inOrder(root);
	cout<<endl;
}
StudentBST::~StudentBST ()	//Task # 1.3
{
	destroy(root);
}
bool StudentBST::remove (int rn)
{
	StudentNode *curr=root;
	StudentNode *parent=0;
	while (curr!=0 && curr->rollNo != rn)
	{
		if(rn<curr->rollNo)
			return false;
		else if(rn<curr->rollNo)
		{
			parent=curr;
			curr=curr->left;
		}
		else
		{
			parent=curr;
			curr=curr->right;
		}
	}
	if (curr==0)
	{
		return false;
	}
	else if(curr->left!=0 && curr->right!=0)
	{
		StudentNode *pred=curr->left;
		StudentNode *pp=curr;
		while (pred->right!=0)
		{
			pp=pred;
			pred=pred->right;
		}
		curr->rollNo=pred->rollNo;
		curr->name=pred->name;
		curr->cgpa=pred->cgpa;
		curr=pred;
		parent=pp;
	}
	if (curr==root)
	{
		if (root->left!=0)
			root=root->left;
		else
			root=root->right;
		delete curr;
		curr=0;
		return true;
	}
	else
	{
		StudentNode *temp=0;
		if (curr->left!=0)
			temp=curr->left;
		if (curr->right!=0)
			temp=curr->right;
		if (curr==parent->left)
			parent->left=temp;
		else
			parent->right=temp;
		delete curr;
		curr=0;
		return true;
	}
}