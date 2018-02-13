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
void LinkedList::insertStart(int val)
{
	Node *temp=new Node;
	temp->data=val;
	temp->next=head;
	head=temp;
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

void LinkedList::combine (LinkedList& list1, LinkedList& list2)
{
	if(list1.head==0)
		head=0;
	else if(list2.head==0)
		head=0;
	
	else
	{
		head=new Node;
		head->data=list1.head->data;
		Node* Org1=list1.head->next;
		Node*temp=head;
		while(Org1!=NULL)
		{
			temp->next=new Node;
			temp=temp->next;
			temp->data=Org1->data;
			Org1=Org1->next;
		}
		temp->data=list2.head->data;
		Node* Org2=list2.head->next;
		while(Org2!=NULL)
		{
			temp->next=new Node;
			temp=temp->next;
			temp->data=Org2->data;
			Org2=Org2->next;
		}
		temp->next=0;
	}
}

bool LinkedList::removeLastNode (int& val)
{
	if(head==0)
		return false;
	else
	{
		Node *curr=head->next;
		Node *prev=head;
		Node *after=0;
		if(curr!=0)
		{
			while(curr!=0)
			{
				after=prev;
				prev=curr;
				curr=curr->next;
			}
		}
		after->next=curr;
		val=prev->data;
		delete prev;
		prev=0;
		return true;
	}
}
bool LinkedList::removeSecondLastNode (int& val)
{
	Node *curr=head->next;
	Node *prev=head;
	Node *after1=0;
	if(curr->next==0)
		return false;
	else
	{
		while(curr->next!=0)
		{
			after1=prev;
			prev=curr;
			curr=curr->next;
		}
		after1->next=curr;
		val=prev->data;
		delete prev;
		prev=0;
		return true;
	}
}
bool LinkedList::removeKthNode (int k, int& val)
{
	Node *curr=head->next;
	Node *prev=head;
	Node *after1=0;
	k=k-1;
	int i=0;
	if(curr==0||k<0)
		return false;
	else
	{
		while(curr!=0&&i<=k)
		{
			after1=prev;
			prev=curr;
			curr=curr->next;
			i++;
		}
		after1->next=curr;
		val=prev->data;
		delete prev;
		prev=0;
		return true;
	}
}