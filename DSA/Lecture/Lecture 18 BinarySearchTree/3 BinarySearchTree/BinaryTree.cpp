#include<iostream>
using namespace std;
#include"BinaryTree.h"
BinaryTree::BinaryTree()
{
	root=0;
}
void BinaryTree::preOrder(TreeNode  *t)
{
	if(t!=0)
	{
		cout<<t->data<<" ";
		preOrder(t->left);
		preOrder(t->right);
	}

}
void BinaryTree::postOrder(TreeNode  *t)
{
	if(t!=0)
	{
		postOrder(t->left);
		postOrder(t->right);
		cout<<t->data<<" ";
	}

}
void BinaryTree::inOrder(TreeNode  *t)
{
	if(t!=0)
	{
		inOrder(t->left);
		cout<<t->data<<" ";
		inOrder(t->right);
	}

}
void BinaryTree::preOrder()
{
	preOrder(root);
}


void BinaryTree::postOrder()
{
	postOrder(root);
}

void BinaryTree::inOrder()
{
	inOrder(root);
}

void  BinaryTree::levelOrderTraversal(TreeNode  *t)
{
	Queue<TreeNode *> q;
	while(t!=0)
	{
		cout<<t->data<<" ";
		if(t->left)
			q.enqueue(t->left);
		else 
		if(t->right)
			q.enqueue(t->right);
		//t=*q;
		delete t;
	}
}

void  BinaryTree::levelOrderTraversal()
{
	levelOrderTraversal(root);
}

bool BinaryTree::insert(int val)
{
	TreeNode *curr=root;
	TreeNode *parent=0;
	while (curr!=0)
	{
		if(val==curr->data)
			return false;
		else if(val<curr->data)
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
	curr=new TreeNode;
	curr->data=val;
	curr->left=0;
	curr->right=0;
	if(parent!=0)
	{
		if(curr->data<parent->data)
			parent->left=curr;
		else
			parent->right=curr;
	}
	else
	{
		root=curr;
	}
	return true;
}
