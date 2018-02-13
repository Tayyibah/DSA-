#include "Cd LinkedList.h"

#include<iostream>
using namespace std;

CDLinkedList::CDLinkedList()
{
	head.next = & head ;
	head.prev = & head ;
}


void CDLinkedList::display()
{
	DNode * temp = head.next ;
	while (temp != &head)
	{
		cout<<temp->data <<endl;
		temp = temp->next ;
	}
}


bool CDLinkedList::insert(int val)
{
	DNode * t = new DNode ;
	t->data = val ;
	DNode * curr = head.next ;
	while (curr!=&head && curr->data<val)
	{
		curr = curr->next ;
	}

	t->next = curr ;
	t->prev = curr->prev ;
	curr->prev->next = t ;
	curr->prev = t ;
	return true ;
}


bool CDLinkedList::remove(int val)
{
	DNode * curr = head.next ;
	while (curr!= &head && curr->data < val)
	{
		curr = curr->next ;
	}

	if (curr!= &head && curr->data == val)
	{
		curr->prev->next = curr->next ;
		curr->next->prev = curr->prev ;
		delete curr;
		curr = 0 ;
		return true ;
	}
	else
	{
		return false ;
	}
}


CDLinkedList::CDLinkedList(const CDLinkedList & orig)
{
	if(orig.head.next == &orig.head)
	{
		head.next = &head ;
		head.prev = &head ;
	}
	else
	{
		DNode * o = orig.head.next ;
		DNode * curr = &head ;
		while (o != &orig.head)
		{
			curr->next = new DNode ;
			curr->next->prev = curr ;
			curr = curr->next;
			curr->data = o->data ;
			o=o->next ;
		}
		curr->next = &head ;
		head.prev = curr ;

	}
}
//CDLinkedList:: ~CDLinkedList()
//{
//	DNode *t1=head.next;
//	DNode *t2=0;
//	while(t1!=&head)
//	{
//		t2=t1->next;
//		t2->prev=t1->prev;
//		delete t1;
//		t1=t2;
//
//	}
//	head.next=&head;
//	head.prev=&head;
//
//}
bool CDLinkedList :: removeLastNode (int& val)
{
	DNode*temp=head.prev;
	if(head.next==&head)
	{
		return false;
	}
		
		val=temp->data;
		head.prev=temp->prev;
		temp->prev->next=&head;
		delete temp;
		temp=0;
		return true;
	

}
bool CDLinkedList :: removeSecondLastNode (int& val)
{
	if (head.prev==&head || head.prev->prev==&head)
	{
		val=0;
		return false;
	}
	else
	{
		DNode *temp=head.prev;
		temp=temp->prev;
		val=temp->data;
		temp->prev->next=temp->next;
		temp->next->prev=temp->prev;
		delete temp;
		temp=0;
		return true;
	}
	

	
	
}
bool CDLinkedList :: removeKthNode (int& val,int k)
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
void CDLinkedList :: combine (CDLinkedList & node1, CDLinkedList &node2)
{
	if (node1.head.next!=&node1.head && node2.head.next!=&node2.head)
	{
		/*head.next=node1.head.next;
		node1.head.next->prev=head.next;
		node1.head.prev->next=node2.head.next;
		node2.head.next->prev=head.prev;
		head.prev=node2.head.prev;*/

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
void CDLinkedList :: merge (CDLinkedList &node1, CDLinkedList &node2)
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