#include<iostream>
using namespace std;
#include "BST.h"
BST :: BST()
{
	root=0;
}
BST:: ~BST()
{
	destroy (root);
}
void BST:: destroy(BSTNode *s)
{
	if(s!=0)
	{
		destroy(s->left);
		destroy(s->right);
		delete s;
		s=0;
	}

}
bool BST :: insert(int val)
{
	BSTNode *curr=root;
	BSTNode *parent =0;
	while (curr!=0)
	{
		if(val==curr->data)
		{
			return false;
		}
		else if (val<curr->data)
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
	curr=new BSTNode;
	curr->data=val;
	curr->left=0;
	curr->right=0;
	if(root==0)
	{
		root=curr;
		return true;
	}
	else if (curr->data<parent->data)
	{
		parent->left=curr;
	}
	else
	{
		parent->right=curr;
	}
	return true;

}
bool BST :: remove (int val)
{
	BSTNode * curr=root;
	BSTNode * parent=0;
	if (curr==0)
	{
		return false;
	}
	
	while(curr->data!=val && curr!=0)
	{
		if (val<curr->data)
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
	
		
		if(curr->left!=0 && curr->right!=0)
		{
			BSTNode *pred=curr->left;
			BSTNode *pp=curr;
			while(pred->right!=0)
			{
				pp=pred;
				pred=pred->right;
			}
			curr->data=pred->data;
			curr=pred;
			parent=pp;
		}
		if (curr==root)
		{
			if(root->left!=0)
			{
				root=root->left;
			}
			else
			{
				root=root->right;
				delete curr;
				curr=0;
				return true;
			}
		}
		else
		{
			BSTNode *temp;
			if (curr->left!=0)
			{
				temp=curr->left;
			}
			else
			{
				temp=curr->right;
			}
			if(curr=parent->left)
			{
				parent->left=temp;

			}
			else
			{
				parent->right=temp;
			}
			delete curr;
			curr=0;
			return true;
		}
		
	
}
bool BST:: search(int key)
{
	BSTNode *curr=root;
	while(curr!=0)
	{
		if (curr->data==key)
		{
			return true;
		}
		else if (key<curr->data)
		{
			curr=curr->left;
		}
		else
		{
			curr=curr->right;
		}
	}
	return false;
}
void BST ::inOrder ()
{
	inOrder(root);
}
void BST :: postOrder()
{
	postOrder(root);
}
void BST ::preOrder()
{
	preOrder(root);

}
void BST :: inOrder (BSTNode * t)
{
	if(t!=0)
	{
		inOrder(t->left);
		cout<<t->data<<endl;
		inOrder(t->right);
	}
}
void BST :: postOrder(BSTNode * t)
{
	if(t!=0)
	{
		postOrder(t->left);
		postOrder(t->right);
		cout<<t->data<<endl;
	}
}
void BST :: preOrder(BSTNode * t)
{
	if(t!=0)
	{
		cout<<t->data<<endl;
		preOrder(t->left);
		preOrder(t->right);
	}
}
int BST :: countNodes (BSTNode* b)
{
	if(b==0)
	{
		return 0;
	}
	else
	{
		return 1+countNodes(b->left)+countNodes(b->right);

	}
}
int BST :: countNodes ()
{
	return countNodes(root);
}
bool BST :: recSearch (BSTNode* b, int key)
{
	if(b!=0)
	{
		if(key==b->data)
		{

			return true;
		}
		else if (key<b->data)
		{
			return recSearch(b->left, key);

		}
		else if (key>b->data)
		{
			return recSearch (b->right,key);
		}
	}
	
		return false;
	

}
bool BST :: recSearch (int key)
{
	return recSearch(root,key);
}
void BST :: doubleTree()
{
	 doubleTree(root);
}
void BST :: doubleTree(BSTNode *t)
{
	if (t!=0)
	{
		BSTNode *temp=new BSTNode;
		temp->right=0;
		temp->left=t->left;
		temp->data=t->data;
		t->left=temp;
		doubleTree(t->left->left);
		doubleTree(t->right);


	}
}
void BST :: printAllPaths()
{
	int pathLen=0;
	int path[100];
	printPathsRecur(root,path,pathLen);

}
void BST :: printPathsRecur(BSTNode * temp, int path[],int pathSize)
{
	if (temp==0)
	{
		return;
	}
	else
	{
		path[pathSize]=temp->data;
		pathSize++;
		if (temp->left== 0 && temp->right==0)
		{
			printArray(path,pathSize);
		}
		else
		{
			printPathsRecur(temp->left,path,pathSize);
			printPathsRecur(temp->right,path,pathSize);
		}
	}
}
void BST :: printArray(int path[],int pathLen)
{
	for(int i=0 ; i<pathLen ;i++)

	{
		cout<<path[i]<< " -> ";
	}
	cout<<endl;

}
