#include<iostream>
using namespace std;
#include"CSLINKEDLISTDH.h"
CSLinkedListDH::CSLinkedListDH()
{
	head.next=&head;
}
bool CSLinkedListDH::insert(int val)
{
	Node *temp=new Node;
	temp->data=val;
	Node *curr=head.next;
	Node *prev=&head;
	while (curr!=&head&&curr->data<val)
	{
		prev=curr;
		curr=curr->next;
	}
	temp->next=curr;
	prev->next=curr->next;
	return true;
}
	
bool CSLinkedListDH::remove(int val)
{
	Node *curr=head.next;
	Node *prev=&head;
	while (curr!=&head&&curr->data<val)
	{
		prev=curr;
		curr=curr->next;
	}
	if (curr!=&head&&curr->data==val)
	{
		prev->next=curr->next;
		delete curr;
		curr=0;
		return true;
	}
	else
		return false;
}
void CSLinkedListDH::display()
{
	Node *temp=head.next;
	while(temp!=&head)
	{
		cout<<temp->data<<" "<<endl;
		temp=temp->next;
	}
	cout<<endl;
}
CSLinkedListDH::CSLinkedListDH(const CSLinkedListDH &orig)
{
		head.data=orig.head.data;
		Node* Org=orig.head.next;
		Node temp=head;
		while(Org!=&head)
		{
			temp.next=new Node;
			temp.data=Org->data;
			Org=Org->next;
		}
		temp.next=0;
}
CSLinkedListDH::~CSLinkedListDH()
{
	Node *t1=head.next;
	Node *t2=&head;
	while(t1!=&head)
	{
		t2=t1->next;
		delete t1;
		t1=t2;
	}
		head.next=&head;
}
CSLinkedListDH CSLinkedListDH::operator=(CSLinkedListDH& val)
{
	head=val.head;
	return *this;
}