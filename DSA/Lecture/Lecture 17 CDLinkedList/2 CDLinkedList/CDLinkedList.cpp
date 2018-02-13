#include<iostream>
using namespace std;
#include"CDLinkedList.h"
CDLinkedList::CDLinkedList()
{
	head.next=&head;
	head.prev=&head;
}
bool CDLinkedList::insert(int val)
{
	DNode *temp=new DNode;
	temp->data=val;
	DNode *curr=head.next;
	while (curr!=&head&&curr->data<val)
	{
		curr=curr->next;
	}
	temp->next=curr;
	temp->prev=curr->prev;
	curr->prev->next=temp;
	curr->prev=temp;
	return true;
}
	
bool CDLinkedList::remove(int val)
{
	DNode *curr=head.next;
	while (curr!=&head&&curr->data<val)
	{
		curr=curr->next;
	}
	if (curr!=&head&&curr->data==val)
	{
		curr->prev->next=curr->next;
		curr->next->prev=curr->prev;
		delete curr;
		curr=0;
		return true;
	}
	else
		return false;
}
void CDLinkedList::display()
{
	DNode *temp=head.next;
	while(temp!=&head)
	{
		cout<<temp->data<<endl;
		temp=temp->next;
	}
	cout<<endl;
}
CDLinkedList::CDLinkedList(const CDLinkedList &orig)
{
	if(orig.head.next==&orig.head && &orig.head==&orig.head)
	{
		head.next=&head;
		head.prev=&head;
	}
	else
	{
		DNode* Org=orig.head.next;
		DNode* curr=&head;
		while(Org!=&orig.head)
		{
			curr->next=new DNode;
			curr->next->prev=curr;
			curr=curr->next;
			curr->data=Org->data;
			Org=Org->next;
		}
		curr->next=&head;
		head.prev=curr;
	}
}
CDLinkedList::~CDLinkedList()
{
	DNode *t1=head.next;
	DNode *t2=&head;
	while(t1!=&head)
	{
		t2=t1->next;
		delete t1;
		t1=t2;
	}
		head.next=&head;
}
CDLinkedList CDLinkedList::operator=(CDLinkedList& val)
{
	head=val.head;
	return *this;
}