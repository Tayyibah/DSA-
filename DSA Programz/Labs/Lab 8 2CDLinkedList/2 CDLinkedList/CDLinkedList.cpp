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
		cout<<temp->data<<" ";
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


bool CDLinkedList::removeLastNode (int& val)
{
	DNode * temp= &head;
	if (temp->next != &head)
	{
		while (temp->next != &head)
		{
			temp->prev = temp;
			temp = temp->next;
		}
		val = temp->data;
		if (temp != &head)
			temp->prev->next = &head;
		delete temp;
		return true;
	}
	else
		return false;
}
bool CDLinkedList::removeSecondLastNode (int& val)
{
	DNode * curr, *temp;
	curr = &head;
	temp = &head;
	if (temp->next != &head)
	{
		while (curr->next != &head)
		{
			temp = temp->prev;
			temp->prev = curr;
			curr = curr->next;
		}
		if (curr == &head)
			return false;
		else if (temp!=&head)
		{
			val = temp->prev->data;
			delete temp->prev;
			temp->next = curr;
			return true;
		}
		else
		{
			val = temp->prev->data;
			delete temp->prev;
			return true;
		}
	}
	else
		return false;
}
bool CDLinkedList::removeKthNode (int k, int& val)
{
	DNode *temp=head.next;
	while(k!=1 && temp->next!=&head)
	{
			
		temp=temp->next;
		k--;
	
	}
	if (temp->next!=&head)
	{ 
		val=temp->data;
		temp->prev->next=temp->next;
		temp->next->prev=temp->prev;
		delete temp;
		temp=0;
		return true;
	}
	else
		return false;
}
void CDLinkedList::combine (CDLinkedList& node1, CDLinkedList& node2)
{
	if (node1.head.next!=&node1.head && node2.head.next!=&node2.head)
	{
		node1.head.prev->next = node2.head.next ;
		node2.head.next->prev = node1.head.prev ;

		head.next = node1.head.next ;
		head.prev = node2.head.prev ;
		node2.head.prev->next = &head ;

		node1.head.next->prev = &head ;
	}

	else if (node1.head.next==&node1.head || node2.head.next ==&node2.head)
	{
		DNode *temp;
		if (node1.head.next== &node1.head)
		{
			temp=node2.head.next;
		}
		else
		{
			temp=node1.head.next;
		}
		head.next=temp->prev;
		temp->prev =&head;
		temp->prev->next=head.prev;
		head.prev=temp->prev;


	}
}
void CDLinkedList::shuffleMerge (CDLinkedList& node1, CDLinkedList& node2)
{
	DNode *temp1=node1.head.next;
	DNode *temp2=node2.head.next;
	DNode *temp3=&head;
	while(temp1!=&node1.head && temp2!=&node2.head)
	{
		temp3->next=temp1;
		temp1->prev=temp3;
		temp3->next->next=temp2;
		temp2->prev=temp3->next->prev;
	}
}