#include<iostream>
using namespace std;
#include"LinkedList.h"
LinkedList::LinkedList()
{
	head=0;
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
//void LinkedList::insert(int val)
//{
//	Node *temp=new Node;
//	temp->data=val;
//	temp->next=head;
//	head=temp;
//}
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