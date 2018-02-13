//Name: TAYYIBAH ALAU-D-DIN,
//Roll Number: BSEF14A011,
//Section:F14
#include<iostream>
using namespace std;
/*Constructor To create an empty linked list.

Destructor To destroy a linked list.

bool isEmpty() To check whether the linked list is empty or not

void moveRight (int n) Explained in Exercise 6(a) (Page 175)

void moveLeft (int n) Explained in Exercise 6(b) (Page 175)

void printLeft () This function will print the data of all nodes which occur to the left of
left pointer including the value pointed to by the left pointer. This
function should NOT move/modify the left and right pointers.

void printRight () This function will print the data of all nodes which occur to the right of
right pointer including the value pointed to by the right pointer. This
function should NOT move/modify the left and right pointers.

bool insert (int val) This function should insert val into the linked list maintaining the sorted
order, and should return true.
After insertion the pointer left should be pointing to the node which has
just been added to the linked list.

bool delete (int val) This function will delete the first node containing the value val from the
linked list and return true. If the specified value is not found in the
linked list, this function should not make any changes to the linked list
and should return false.
After removal the pointer left should be pointing to the node which
occurred just before the node which has been deleted. If the first value
of the linked list has been removed, the pointer left should be pointing
to the new first node of the linked list.*/
class LinkedList;
class Node
{
friend class LinkedList;
private:
	int data;
	Node * next;
};

class LinkedList
{
private:
	Node * left;
	Node * right;
public:
	LinkedList();;
	bool isEmpty() ;
	void moveRight (int n) ;
	void moveLeft (int n);
	void printLeft ();
	void printRight () ;
	bool insert (int val);
	bool del(int val);
	~LinkedList();
	LinkedList(const LinkedList &orig);
	LinkedList operator=(LinkedList& val);
};
LinkedList::LinkedList()
{
	left=0;
	right=0;
}
bool LinkedList::isEmpty() 
{
	if(left==0&&right==0)
		return true;
	else
		return false;
}
void LinkedList::moveRight (int n) 
{
	Node *temp=right;
	int i=0;
	while(temp!=0&&i<=n)
	{
		temp=temp->next;
		i++;
	}
}
void LinkedList::moveLeft (int n)
{
	Node *temp=left;
	int i=0;
	while(temp!=0&&i<=n)
	{
		temp=temp->next;
		i++;
	}
}
void LinkedList::printLeft ()
{
	Node *temp=left;
	while(temp!=0)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
void LinkedList::printRight () 
{
	Node *temp=right;
	while(temp!=0)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
//bool LinkedList::del(int val)
//{
//	Node *curr=left,*prev=0;
//	while(curr!=0)
//	{
//		if(curr->data==val)
//		{
//			if(curr==left)
//			{
//				left=curr->next;
//			}
//			else
//			{
//				prev->next=curr->next;
//			}
//			delete curr;
//			curr=0;
//			return true;
//		}
//		else
//		{
//			prev=curr;
//			curr=curr->next;
//		}
//	}
//	curr=right,prev=0;
//	while(curr!=0)
//	{
//		if(curr->data==val)
//		{
//			if(curr==right)
//			{
//				right=curr->next;
//			}
//			else
//			{
//				prev->next=curr->next;
//			}
//			delete curr;
//			curr=0;
//			return true;
//		}
//		else
//		{
//			prev=curr;
//			curr=curr->next;
//		}
//	}
//	return false;
//}
bool LinkedList::insert (int val)
{
	Node *temp = new Node;
	temp->data = val;
	Node * curr1 = left;
	Node * curr2 = right;
	Node * prev = 0;
	if (left == 0)
	{
		temp->next = left;
		left = temp;
	}
	else
	{
		if (val<curr1->data )
		{	
			while (curr1 != 0 && val<curr1->data )
			{
				prev = curr1;
				curr1 = curr1->next;
			}
			prev->next = temp;
			temp->next = curr1;
		}
		else
		{
			if (right == 0)
			{
				temp->next = right;
				right = temp;
			}
			else
			{
				while (curr2 != 0  )
				{
					prev = curr2;
					curr2 = curr2->next;
				}
				prev->next = temp;
				temp->next = curr2;
			}
		}
		
	}
	return true;
}

bool LinkedList::del(int val)
{
	Node *curr=left,*prev=0;
	while(curr!=0)
	{
		if(curr->data==val)
		{
			if(curr==left)
			{
				left=curr->next;
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
	curr=right,prev=0;
	while(curr!=0)
	{
		if(curr->data==val)
		{
			if(curr==right)
			{
				right=curr->next;
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
	Node *t1=left;
	Node *t2=0;
	while(t1!=0)
	{
		t2=t1->next;
		t1->next=0;
		delete t1;
		t1=t2;
	}
	left=0;
	t1=right;
	t2=0;
	while(t1!=0)
	{
		t2=t1->next;
		t1->next=0;
		delete t1;
		t1=t2;
	}
	right=0;
}
LinkedList::LinkedList(const LinkedList &	ref)
{
	Node * tem1 = new  Node;
	Node * tem2 = new  Node;
	Node * temp1 = ref.left;
	Node * temp2 = ref.right;
	tem1->data = temp1->data;
	temp1 = temp1->next;
	left = tem1;
	while (temp1 != 0)
	{
		Node * temp2 = new Node;
		temp2->data = temp1->data;
		tem1->next = temp2;
		tem1 = tem1->next;
		temp1 = temp1->next;
	}
	tem1->next = 0;
	left = 0;
	tem2->data = temp1->data;
	tem2 = temp1->next;
	right = tem2;
	while (temp1 != 0)
	{
		Node * temp2 = new Node;
		temp2->data = temp1->data;
		tem2->next = temp2;
		tem2 = tem2->next;
		temp1 = temp1->next;
	}
	tem2->next = 0;
	right = 0;
}
LinkedList LinkedList::operator=(LinkedList& val)
{
	if (val.right==0)
	{
		right=0;
	}
	right=val.right;
	if (val.left==0)
	{
		left=0;
	}
	left=val.left;
	return *this;
}
int main()
{
	LinkedList list;
	list.insert (3);
	list.insert (1);
	list.insert (6);
	list.insert (2);
	list.insert (4);
	list.insert (5);
	list.printLeft ();
	list.printRight () ;
	list.del(2);
	list.del(11);
	list.del(2);
	list.moveRight (2) ;
	list.moveLeft (2);
	list.isEmpty();
	list.del(3);
	list.del(4);
	return 0;
}