#include<iostream>
using namespace std;
#include"LinkedStack.h"
LinkedStack::LinkedStack()
{
	top=0;
}
bool LinkedStack::isEmpty()
{
	if(top==0)
		return true;
	return false;
}
bool LinkedStack::push(int val)
{
	Node *temp=new Node;
	temp->data=val;
	temp->next=top;
	top=temp;
	return true;
}

bool LinkedStack::getTop(int &val)
{
	if(isEmpty())
	{
		return false;
	}
	else
	{
	val=top->data;
		return true;
	}
}

bool LinkedStack::pop(int &val)
{
	if(isEmpty())
	{
		return false;
	}
	val=top->data;
	Node *temp=top;
	top=top->next;
	delete temp;
	temp=0;
	return true;
}
void LinkedStack::display()
{
	Node *temp=top;
	while(temp!=0)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
LinkedStack::LinkedStack(const LinkedStack &orig)
{
	if(orig.top==0)
		top=0;
	else
	{
		top=new Node;
		top->data=orig.top->data;
		Node* Org=orig.top->next;
		Node*temp=top;
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
LinkedStack::~LinkedStack()
{
	Node *t1=top;
	Node *t2=0;
	while(t1!=0)
	{
		t2=t1->next;
		delete t1;
		t1=t2;
	}
	top=0;
}
LinkedStack LinkedStack::operator=(LinkedStack& val)
{
	if (val.top==0)
	{
		top=0;
	}
	top=val.top;
	return *this;
}