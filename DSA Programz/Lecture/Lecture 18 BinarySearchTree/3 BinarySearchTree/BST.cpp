#include<iostream>
using namespace std;
#include"BST.h"
BST::BST()
{
	root=0;
}
void BST::preOrder(TreeNode  *t)
{
	if(t!=0)
	{
		cout<<t->data<<" ";
		preOrder(t->left);
		preOrder(t->right);
	}

}
void BST::postOrder(TreeNode  *t)
{
	if(t!=0)
	{
		postOrder(t->left);
		postOrder(t->right);
		cout<<t->data<<" ";
	}

}
void BST::inOrder(TreeNode  *t)
{
	if(t!=0)
	{
		inOrder(t->left);
		cout<<t->data<<" ";
		inOrder(t->right);
	}

}
void BST::preOrder()
{
	preOrder(root);
}


void BST::postOrder()
{
	postOrder(root);
}

void BST::inOrder()
{
	inOrder(root);
}


void  BST::levelOrderTraversal()
{/*enQueue (Root)
– while ( Q not empty )
? n = front(); deQueue(); print n
? for each child c of node n
– enQueue(c)
? end for
– end while*/
/*	Queue<TreeNode *> q;
	TreeNode *curr=root;
		cout<<curr->data<<" ";
	while(curr!=0)
	{
		if(curr->left!=0)
		{
			q.enqueue(curr->left);
			cout<<curr->left->data<<" ";
			q.dequeue(curr->left);
			if(curr->right!=0)
				curr=curr->left;
		}
		else if(curr->right!=0)
		{
			q.enqueue(curr->right);
			cout<<curr->right->data<<" ";
			q.dequeue(curr->right);
			curr=curr->right;
			if(curr->left!=0)
				curr=curr->right;
		}*///curr=*q;
		//delete curr;
	}
}


bool BST::search(int key)
{
	TreeNode *curr=root;
	while (curr!=0)
	{
		if(key==curr->data)
			return true;
		else if(key<curr->data)
			curr=curr->left;
		else
			curr=curr->right;
	}
	return true;
}
bool BST::insert(int val)
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
bool BST::remove(int val)
{
	TreeNode *curr=root;
	TreeNode *parent=0;
	while (curr!=0 && curr->data != val)
	{
		if(val<curr->data)
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
	if (curr==0)
	{
		return false;
	}
	else if(curr->left!=0 && curr->right!=0)
	{
		TreeNode *pred=curr->left;
		TreeNode *pp=curr;
		while (pred->right!=0)
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
		TreeNode *temp=0;
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

int BST::equal(TreeNode  * a,TreeNode  * b)
{
	if((!a)&&(!b))//both a n b =0
		return 1;
	if((a)&&(b) && (a->data==b->data) && equal(a->left,b->left) && equal(a->right,b->right))
		return 1;
	else
		return 0;
}/*
int operator==(const BST & s,const BST & t)
{
	return equal(s.root,t.root);
}*/
BST::BST(BST&ref)
{
	root=copy(ref.root);
}
TreeNode *BST::copy(TreeNode  * ref)
{
	if(ref)
	{
		TreeNode *temp=new TreeNode;
		temp->data=ref->data;
		temp->left=copy(ref->left);
		temp->right=copy(ref->right);
		return temp;
	}
	else
		return 0;
}
BST::~BST()
{
	destroy(root);
}
void BST::destroy(TreeNode  *t)
{
	if(t!=NULL)
	{
		destroy(t->left);
		destroy(t->right);
		delete t;
	}
	t=0;
}


TreeNode *  BST::clone(TreeNode *t)const
{
	if(t==NULL)
		return NULL;
	else
		return new TreeNode(t->data,clone(t->left),clone(t->right));
		
}
BST BST::operator=(BST & val)
{
	if(this!= &val)
	{
		destroy(root);
		root=clone(val.root);
	}
	return *this;
}


TreeNode *  BST::findMin(TreeNode  *t)const
{
	if(t==NULL)
		return NULL;
	if(t->left==NULL)
		return t;
	return findMin(t->left);
}
TreeNode * BST::findMax(TreeNode  *t)const
{
	if(t!=NULL)
	{
		while(t->right !=NULL)
			t=t->right;
	}
	return t;
}
int BST::findMin()
{
	return elementAt(findMin(root));
}
int BST::findMax()
{
	return elementAt(findMax(root));
}

const int & BST::elementAt(TreeNode  *t)const
{
	if(t==NULL)
	{
		cout<<"Item nor found "<<endl;
		return 0;
	}
	else
		return t->data;
}