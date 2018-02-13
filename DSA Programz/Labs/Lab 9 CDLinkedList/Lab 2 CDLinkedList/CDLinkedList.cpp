#include<iostream>
using namespace std;
#include "CDLinkedList.h"

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
CDLinkedList:: ~CDLinkedList()
{
	DNode *t1=head.next;
	DNode *t2=0;
	while(t1!=&head)
	{
		t2=t1->next;
		t2->prev=t1->prev;
		delete t1;
		t1=t2;
	}
	head.next=&head;
	head.prev=&head;

}
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
bool CDLinkedList::removeKthNode(int k,int& val)
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
void CDLinkedList :: shuffleMerge (CDLinkedList &node1, CDLinkedList &node2)
{
	head=node1.head;
	DNode * o1=node1.head.next;
	DNode * o2=node2.head.next;
	DNode *temp=0;
	o1->prev=&head;
	while(o1!=&node1.head && o2!=&node2.head )
	{
		temp=o2->next;
		o2->next=o1->next;
		o2->next->prev=o2;

		o1->next=o2;
		o2->prev=o1;
		o1=o1->next;
		o2=temp;
		o2=o2->next;
	}
	o2->next=&head;
	o2->next->prev=o2;
	o1->next=o2;
	o2->prev=o1;
	
}
bool CDLinkedList ::  insert1(int val)
{
	DNode* t=new DNode;
	t->data=val;
	DNode *curr=head.prev;
	t->next=&head;
	t->prev=curr;
	curr->next=t;
	head.prev=t;
	
	return true;
}
bool CDLinkedList :: remove2(int val)
{
	DNode *curr= head.next;
	while(curr !=& head && curr->data!=val)
	{
		curr=curr->next;
	}
	if (curr !=&head && curr->data==val)
	{
		curr->prev->next=curr->next;
		curr->next->prev=curr->prev;
		return true;
	}
	else
	{
		return false;
	}
}
bool CDLinkedList :: checkSort ()
{
	DNode * curr= head.next;
	while (curr->next != & head)
	{
		if (curr->data > curr->next->data)
		{
			return false;
		}
		curr=curr->next;
	}
	return true;
}
bool CDLinkedList :: merge (CDLinkedList& list1, CDLinkedList& list2)
{
	if (!list1.checkSort () || !list2.checkSort ())
	{
		return false;
	}
	else 
	{
		DNode * temp= & head;
		DNode * curr1= list1.head.next;
		DNode * curr2=list2.head.next;
		while (curr1->next !=&list1.head || curr2->next !=&list2.head)
		{
			if (curr1!=&list1.head && curr2!=&list2.head)
			{
				if (curr1->data <curr2->data)
				{
				 	//temp->next=new DNode;
					temp->next=curr1;
					curr1->prev=temp;
					curr1=curr1->next;
					curr1->prev->next=&head;
					head.prev=curr1;
					temp=temp->next;
				
				}
				else
				{
					//	temp->next=new DNode;
					temp->next=curr2;
					curr2->prev=temp;
					curr2=curr2->next;
					curr2->prev->next=&head;
					head.prev=curr2;
					temp=temp->next;
				
				}
			}
			
		}
		 if (curr1!=&list1. head)
			{
					temp->next=curr1;
					curr1->prev=temp;
					curr1=curr1->next;
					curr1->prev->next=&head;
					head.prev=curr1;
					temp=temp->next;
				
			}
			else if (curr2 !=&list2.head)
			{
					temp->next=curr1;
					curr1->prev=temp;
					curr1=curr1->next;
					curr1->prev->next=&head;
					head.prev=curr1;
					temp=temp->next;
				
			}
			
		return true;
	}
}
int CDLinkedList :: findMax ()
{
	return findMax(head.next);
}
int CDLinkedList :: findMax(DNode * temp)
{
	 int large;
	 if (temp!=&head)
	 {
		 if(temp->next == &head)
		 {
			 large=temp->data;
		 }
		 else
		 {
			 int t=findMax(temp->next);
				 if (temp->data>t)
				 {
					large=temp->data;
				 }
				else
				 {
					 large=t;
				 }
		 }
		 return large;
	 }
	 else 
	 {
		 return -9999;
	 }
}
void CDLinkedList::  splitList (CDLinkedList& leftHalf, CDLinkedList& rightHalf)
{
	DNode * curr=head.next;
	int count=0;
	int j=0;
	while(curr!=&head)
	{
		curr=curr->next;
		count++;
	}
	if (count%2==0)
	{
		 j=count/2;
	}
	else
	{
		j=count/2;
		j=j+1;
	}
	DNode * curr1=&leftHalf.head;
	int i=0;
	curr=&head;
	curr=curr->next;
	while (i<j)
	{
		curr1->next=curr;
		curr->prev=curr1;
		curr=curr->next;
		curr->prev->next=&leftHalf.head;
		leftHalf.head.prev=curr;
		curr1=curr1->next;
		i++;
	}
	DNode * curr2=&rightHalf.head;
	while(i<count)
	{
		curr2->next=curr;
		curr->prev=curr2;
		curr=curr->next;
		curr->prev->next=&rightHalf.head;
		rightHalf.head.prev=curr;
		curr2=curr2->next;
		
		i++;
	}

}
void CDLinkedList :: mergeSort ()
{
	 mergeSort (head.next);
}
void CDLinkedList ::mergeSort (DNode *t)
{
	CDLinkedList l1;
	CDLinkedList l2;
	if (t!=&head)
	{
		splitList(l1,l2);
		mergeSort(l1.head.next);
		mergeSort(l2.head.next);
		merge(l1,l2);
		t=t->next;
	}
}