#include<iostream>
using namespace std;
#include"LinkedList.h"
LinkedList::LinkedList()
{
	head=0;
}
void LinkedList::display()
{
	Node *temp=head;
	while(temp!=0)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
void LinkedList::insertEnd(int val)
{
	Node *temp=new Node;
	temp->data=val;
	temp->next=0;
	Node * curr=head;
	if(curr!=0)
	{
		while (curr->next!=0)
		{
			curr=curr->next;
		}
	curr->next=temp;
	}
	else
		head=temp;
}
void LinkedList::insertStart(int val)
{
	Node *temp=new Node;
	temp->data=val;
	temp->next=head;
	head=temp;
}
void LinkedList::sortedInsert(int val)
{
	Node *temp=new Node;
	temp->data=val;
	Node *curr=head,*prev=0;
	while (curr!=0&&curr->data<val)
	{
		prev=curr;
		curr=curr->next;
	}
	if(prev==0)
	{
		temp->next=head;
		head=temp;
	}
	else
	{
		prev->next=temp;
		temp->next=curr;
	}
}
void LinkedList::unSortedInsert(int val)
{
	Node *temp=new Node;
    temp->data=val;
    if (head== NULL)
    {
		head=temp;
		head->next=NULL;
    }
    else
    {
		temp->next=head;
		head=temp;
    }
	
}
LinkedList::LinkedList(const LinkedList &orig)
{
	if(orig.head==0)
		head=0;
	else
	{
		head=new Node;
		head->data=orig.head->data;
		Node* Org=orig.head->next;
		Node*temp=head;
		while(Org!=NULL)
		{
			temp->next=new Node;
			temp=temp->next;
			temp->data=Org->data;
			Org=Org->next;
		}
		temp->next=0;
	}
}
	
bool LinkedList::remove(int val)
{
	Node *curr=head,*prev=0;
	while(curr!=0)
	{
		if(curr->data==val)
		{
			if(curr==head)
			{
				head=curr->next;
			}
			else
			{
				prev->next=curr->next;
			}
			delete curr;
			curr=0;
			return true;
		}
		else
		{
			prev=curr;
			curr=curr->next;
		}
	}
	return false;
}
bool LinkedList::sortedRemove(int val)
{
	Node *curr=head,*prev=0;
	while(curr!=0 && curr->data<=val)
	{
		Node *curr=head,*prev=0;
		while(curr!=0)
		{
			if(curr->data==val)
			{
				if(curr==head)
				{
					head=curr->next;
				}
				else
				{
					prev->next=curr->next;
				}
				delete curr;
				curr=0;
				return true;
			}
			else
			{ 
				prev=curr;
				curr=curr->next;
			}
		}
		return false; 
	}
	return false;
}
LinkedList::~LinkedList()
{
	Node *t1=head;
	Node *t2=0;
	while(t1!=0)
	{
		t2=t1->next;
		delete t1;
		t1=t2;
	}
	head=0;
}
LinkedList LinkedList::operator=(LinkedList& val)
{
	if (val.head==0)
	{
		head=0;
	}
	head=val.head;
	return *this;
}

void LinkedList::displayRecursively(Node * t)
{
	if(t!=0)
	{
		cout<<t->data<<" ";
		displayRecursively(t->next);
	}
}

void LinkedList::displayRecursiveCall()
{
	displayRecursively(head);
}

int LinkedList::findLargest()
{
	int max=head->data;
	Node* temp=head;
	while(temp->next!=0)
	{
		temp=temp->next;
		if(temp->data>max)
		{
			max=temp->data;
		}
	}
	return max;
}
int LinkedList::findRecursively(Node * t)
{
	if(t->next==0)
		return t->data;
	else if(head==0)
		return head->data;
	else
	{
		int largest=t->data;
		int lar=findRecursively(t->next);
		if(largest<lar)
			largest=lar;
		return largest;
	}
}
int LinkedList::findRecursiveCall()
{
	return findRecursively(head);
}