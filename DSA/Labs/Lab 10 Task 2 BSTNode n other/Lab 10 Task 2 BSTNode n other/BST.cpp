#include<iostream>
using namespace std;
#include"BST.h"
BST::BST()
{
	root=0;
}
void BST::preOrder(BSTNode  *t)
{
	if(t!=0)
	{
		cout<<t->data<<" ";
		preOrder(t->left);
		preOrder(t->right);
	}

}
void BST::postOrder(BSTNode  *t)
{
	if(t!=0)
	{
		postOrder(t->left);
		postOrder(t->right);
		cout<<t->data<<" ";
	}

}
void BST::inOrder(BSTNode  *t)
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
	cout<<endl;
}


void BST::postOrder()
{
	postOrder(root);
	cout<<endl;
}

void BST::inOrder()
{
	inOrder(root);
	cout<<endl;
}


bool BST::search(int key)
{
	BSTNode *curr=root;
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
	BSTNode *curr=root;
	BSTNode *parent=0;
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
	curr=new BSTNode;
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
	BSTNode *curr=root;
	BSTNode *parent=0;
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
		BSTNode *pred=curr->left;
		BSTNode *pp=curr;
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
		BSTNode *temp=0;
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

int BST::equal(BSTNode  * a,BSTNode  * b)
{
	if((!a)&&(!b))//both a n b =0
		return 1;
	if((a)&&(b) && (a->data==b->data) && equal(a->left,b->left) && equal(a->right,b->right))
		return 1;
	else
		return 0;
}
//int operator==(const BST & s,const BST & t)
//{
//	return equal(s.root,t.root);
//}
//BST BST::operator=(int &orig)
//{

//}
BST::BST(BST&ref)
{
	root=copy(ref.root);
}
BSTNode *BST::copy(BSTNode  * ref)
{
	if(ref)
	{
		BSTNode *temp=new BSTNode;
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
void BST::destroy(BSTNode  *t)
{
	if(t!=NULL)
	{
		destroy(t->left);
		destroy(t->right);
		delete t;
	}
	t=0;
}


bool BST::recSearch (int key)
{
	return recSearch(root,key);
} // public (driver function)//2.3
bool BST::recSearch (BSTNode* b, int key)
{
	if(!b)
		return 0;
	if(key==b->data)
		return true;
	if(key<b->data)
		return recSearch(b->left,key);
	else 
		return recSearch(b->right,key);

} // private (workhorse function)//2.3
//int BST::countNodes ()
//{
//	return countNodes(root);
//} // public (driver function)//2.4
//int BST::countNodes (BSTNode* b)
//{
//	if(!b)
//		return 0;
//	if(b->left ==0 || b->right ==0)
//		return 1;
//	else
//		return countNodes(b->right)+countNodes(b->left);
//} // private (workhorse function)//2.4

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
/* void BST::doubleTree(BSTNode *t)
{
        if (t == 0) {
            return;
        }
        doubleTree(t->left);
		
        BSTNode *temp=t->left;
        t->left=new BSTNode;
        t->left->left=temp;
        doubleTree(t->right);
    }*/
//void BST::doubleTree()
//{
//	BSTNode *curr=root;
//	BSTNode *parent=0;
//	while (curr!=0)
//	{
//		if(val==curr->data)
//			return false;
//		else if(val<curr->data)
//		{
//			parent=curr;
//			curr=curr->left;
//		}
//		else
//		{
//			parent=curr;
//			curr=curr->right;
//		}
//	}
//	curr=new BSTNode;
//	curr->data=val;
//	curr->left=0;
//	curr->right=0;
//	if(parent!=0)
//	{
//		if(curr->data<parent->data)
//			parent->left=curr;
//		else
//			parent->right=curr;
//	}
//	else
//	{
//		root=curr;
//	//}
//	//BSTNode *curr1=root;
//	//BSTNode *curr2=root->right;
//	//BSTNode *ppLeft=root->left;
//	//BSTNode *ppRight=root->right;
//	//do{
//	//	curr1->left=curr1;
//	//	curr1->left->data=curr1->data;
//	//	curr1=curr1->left;
//	//	curr1->data=curr1->left->data;
//	//	ppLeft=curr1;
//	//	/*ppLeft->data=curr1->data;
//	//	curr2->right->left=curr2->right;
//	//	curr2->right->left->data=curr2->right->data;*/
//	//}
//	//while (curr1->left!=0 /*&& curr2->left!=0*/);
//}//2.5