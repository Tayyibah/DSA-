#include<iostream>
using namespace std;
#include"LinkedQueue.h"
LinkedQueue::LinkedQueue()
{
	front=back=0;
}
bool LinkedQueue::isEmpty()
{
	if(front==0)
		return true;
	return false;
}
bool LinkedQueue::enqueue(int val)
{
	Node *temp=new Node;
	temp->data=val;
	temp->next=0;
	if(back==0)
	{
		back=temp;
		front=temp;
	}
	else
	{
		back->next=temp;
		back=temp;
		return true;
	}
}
bool LinkedQueue::dequeue(int &val)
{
	if(isEmpty())
	{
		return false;
	}
	val=front->data;
	Node *temp=front;
	front=front->next;
	if(front==NULL)
	{
		back=0;
	}
	delete temp;
	temp=0;
	return true;
}
void LinkedQueue::display()
{
	Node *temp=front;
	while(temp!=0)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
LinkedQueue::LinkedQueue(const LinkedQueue &orig)
{
	if(orig.front==0)
		front=0;
	else
	{
		front=new Node;
		front->data=orig.front->data;
		Node* Org=orig.front->next;
		Node*temp=front;
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
LinkedQueue::~LinkedQueue()
{
	Node *t1=front;
	Node *t2=0;
	while(t1!=0)
	{
		t2=t1->next;
		delete t1;
		t1=t2;
	}
	front=0;
}
LinkedQueue LinkedQueue::operator=(LinkedQueue& val)
{
	if (val.front==0)
	{
		front=0;
	}
	front=val.front;
	return *this;
}