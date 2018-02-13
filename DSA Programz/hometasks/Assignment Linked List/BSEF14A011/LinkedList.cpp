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

bool LinkedList::search(int val)
{
	Node * curr = head;
	while (curr!= 0)
	{
		if (curr->data == val)
			return true;
		curr = curr->next;
	}
	return false;
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
LinkedList::LinkedList(const LinkedList &	ref)
{
	Node * temp = new  Node;
	Node * temp1 = ref.head;
	temp->data = temp1->data;
	temp1 = temp1->next;
	head = temp;
	while (temp1 != 0)
	{
		Node * temp2 = new Node;
		temp2->data = temp1->data;
		temp->next = temp2;
		temp = temp->next;
		temp1 = temp1->next;
	}
	temp->next = 0;
	head = 0;
	/*Node * temp = ref.head;
	while (temp != 0)
	{
		insertAtEnd(temp->data);
		temp = temp->next;
	}*/
	//OR upar wala h aro
	/*if(orig.head==0)
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
	}*/
}
	
LinkedList::~LinkedList()
{
	Node *temp;
	while (head!=0)
	{
		temp = head->next;
		head->next = 0;
		delete head;
		head = temp;
	}
	head = 0;
	//OR
	/*Node *t1=head;
	Node *t2=0;
	while(t1!=0)
	{
		t2=t1->next;
		t1->next=0;
		delete t1;
		t1=t2;
	}
	head=0;*/
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

bool LinkedList::removeLastNode (int& val)
{
	Node * temp;
	Node * prev = 0;
	temp = head;
	if (head != 0)
	{
		while (temp->next != 0)
		{
			prev = temp;
			temp = temp->next;
		}
		val = temp->data;
		if (temp != head)
			prev->next = 0;
		else
			head = 0;
		delete temp;
		return true;
	}
	else
		return false;
	//or
	/*if(head==0)
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
	}*/
}
bool LinkedList::removeSecondLastNode (int& val)
{
	Node * curr, *temp, *prev;
	curr = head;
	prev = 0;
	temp = 0;
	if (head != 0)
	{

		while (curr->next != 0)
		{
			temp = prev;
			prev = curr;
			curr = curr->next;
		}
		if (curr == head)
			return false;
		else if (temp!=0)
		{
			val = prev->data;
			delete prev;
			temp->next = curr;
			return true;
		}
		else
		{
			val = prev->data;
			delete prev;
			head = curr;
			return true;

		}

	}
	else
		return false;
	//or
	/*Node *curr=head->next;
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
	}*/
}
bool LinkedList::removeKthNode (int k, int& val)
{
	Node * curr, *prev;
	curr = head;
	prev = 0;
	for (int i = 1; i <= k && curr != 0; i++)
	{
		if (i == k)
		{
			val = curr->data;
			if (i != 1)
				prev->next = curr->next;
			else
				head = curr->next;
			delete curr;
			return true;
		}
		prev = curr;
		curr = curr->next;
	}
	return false;
	//or
	/*Node *curr=head->next;
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
	}*/
}
void LinkedList::suffleMerge(LinkedList & list1, LinkedList & list2)
{
	Node * temp=0;
	head = list1.head;
	temp = list1.head;
	while (list1.head != 0 && list2.head != 0)
	{
		list1.head = list1.head->next;
		temp->next = list2.head;
		temp = temp->next;
		list2.head = list2.head->next;
		temp->next = list1.head;
		temp = temp->next;
	}
	/*while (list1.head != 0)
	{
		temp->next = list1.head;
		list1.head = list1.head->next;
		temp = temp->next;
	}
	while (list2.head != 0)
	{
		temp->next = list2.head;
		list2.head = list2.head->next;
		temp = temp->next;
	}*/

}
void LinkedList::combine (LinkedList& list1, LinkedList& list2)
{
	head = list1.head;
	list1.head = 0;
	Node* temp = head;
	while (temp->next != 0)
		temp = temp->next;
	temp->next = list2.head;
	list2.head = 0;
	//or
	/*if(list1.head==0)
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
	}*/
}