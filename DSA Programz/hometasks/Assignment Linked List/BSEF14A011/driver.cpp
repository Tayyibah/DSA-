////Name: TAYYIBAH ALAU-D-DIN,
////Roll Number: BSEF14A011,
////Section:F14
//#include<iostream>
//using namespace std;
//class LinkedList;
//class Node
//{
//friend class LinkedList;
//private:
//	int data;
//	Node * next;
//};
//
//class LinkedList
//{
//private:
//	Node * left;
//	Node * right;
//public:
//	LinkedList();;
//	bool isEmpty() ;
//	void moveRight (int n) ;
//	void moveLeft (int n);
//	void printLeft ();
//	void printRight () ;
//	bool insert (int val);
//	bool del(int val);
//	~LinkedList();
//	LinkedList(const LinkedList &orig);
//	LinkedList operator=(LinkedList& val);
//};
//LinkedList::LinkedList()
//{
//	left=0;
//	right=0;
//}
//bool LinkedList::isEmpty() 
//{
//	if(left==0&&right==0)
//		return true;
//	else
//		return false;
//}
//void LinkedList::moveRight (int n) 
//{
//	Node *temp=right;
//	int i=0;
//	while(temp!=0&&i<=n)//moving Right upto n times
//	{
//		//left=temp;
//		temp=temp->next;
//		i++;
//	}
//	//left=temp;
//}
//void LinkedList::moveLeft (int n)
//{
//	Node *temp=left;
//	int i=0;
//	while(temp!=0&&i<=n)//moving Left upto n times
//	{
//		//right=temp;
//		temp=temp->next;
//		i++;
//	}
//	//left=temp;
//}
//void LinkedList::printLeft ()
//{
//	Node *temp=left;
//	while(temp!=0)//printing all Nodes before left 
//	{
//		cout<<temp->data<<" ";
//		temp=temp->next;
//	}
//	cout<<endl;
//}
//void LinkedList::printRight () 
//{
//	Node *temp=right;
//	while(temp!=0)//printing all Nodes after right 
//	{
//		cout<<temp->data<<" ";
//		temp=temp->next;
//	}
//	cout<<endl;
//}
//bool LinkedList::insert (int val)
//{
//	Node *temp = new Node;
//	temp->data = val;
//	Node * curr1 = left;
//	Node * curr2 = right;
//	Node * prev = 0;
//	if (left == 0)//if first element is inserted ,this if statement would run
//	{
//		temp->next = left;
//		left = temp;
//	}
//	else
//	{
//		if (val<curr1->data )
//		{	
//			while (curr1 != 0 && val<curr1->data )
//			{
//				prev = curr1;
//				curr1 = curr1->next;
//			}
//			prev->next = temp;
//			temp->next = curr1;
//		}
//		else
//		{
//			if (right == 0)
//			{
//				temp->next = right;
//				right = temp;
//			}
//			else
//			{
//				while (curr2 != 0  )
//				{
//					prev = curr2; 
//					curr2 = curr2->next;
//				}
//				prev->next = temp;
//				temp->next = curr2;
//			}
//		}
//	}
//	return true;
//}
//
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
//LinkedList::~LinkedList()
//{
//	Node *t1=left;
//	Node *t2=0;
//	while(t1!=0)
//	{
//		t2=t1->next;
//		t1->next=0;
//		delete t1;
//		t1=t2;
//	}
//	left=0;
//	t1=right;
//	t2=0;
//	while(t1!=0)
//	{
//		t2=t1->next;
//		t1->next=0;
//		delete t1;
//		t1=t2;
//	}
//	right=0;
//}
//
//LinkedList::LinkedList(const LinkedList &	ref)
//{
//	Node * tem1 = new  Node;
//	Node * tem2 = new  Node;
//	Node * temp1 = ref.left;
//	Node * temp2 = ref.right;
//	tem1->data = temp1->data;
//	temp1 = temp1->next;
//	left = tem1;
//	while (temp1 != 0)
//	{
//		Node * temp2 = new Node;
//		temp2->data = temp1->data;
//		tem1->next = temp2;
//		tem1 = tem1->next;
//		temp1 = temp1->next;
//	}
//	tem1->next = 0;
//	left = 0;
//	tem2->data = temp1->data;
//	tem2 = temp1->next;
//	right = tem2;
//	while (temp1 != 0)
//	{
//		Node * temp2 = new Node;
//		temp2->data = temp1->data;
//		tem2->next = temp2;
//		tem2 = tem2->next;
//		temp1 = temp1->next;
//	}
//	tem2->next = 0;
//	right = 0;
//}
//LinkedList LinkedList::operator=(LinkedList& val)
//{
//	if (val.right==0)
//	{
//		right=0;
//	}
//	right=val.right;
//	if (val.left==0)
//	{
//		left=0;
//	}
//	left=val.left;
//	return *this;
//}
//int main()
//{
//	LinkedList list;
//	list.insert (3);
//	list.insert (2);
//	list.insert (2);
//	list.insert (1);
//	list.insert (6);
//	list.insert (2);
//	list.insert (4);
//	list.insert (5);
//	list.printLeft ();
//	list.printRight () ;
//	list.del(1);
//	list.del(11);
//	list.del(2);
//	list.printLeft ();
//	list.printRight () ;
//	list.moveRight (1) ;
//	list.printLeft ();
//	list.printRight () ;
//	list.moveLeft (1);
//	list.printLeft ();
//	list.printRight () ;
//	list.isEmpty();
//	list.del(3);
//	list.del(4);
//	return 0;
//}
//
