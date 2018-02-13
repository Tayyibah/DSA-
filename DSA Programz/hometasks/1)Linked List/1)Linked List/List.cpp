#include<iostream>
using namespace std;
#include"List.h"
List::List()
{
	headNode=new Node();
	headNode->setNextNode(NULL);
	currentNode=NULL;
	lastCurrentNode=NULL;
	size=0;
}
void List::add(int addObject)
{
	Node * newNode= new Node();
	newNode->setObject(addObject);
	if(currentNode!=NULL)
	{
		newNode->setNextNode(currentNode->getNextNode());
		currentNode->setNextNode(NULL);
		lastCurrentNode=currentNode;
		currentNode=newNode;
	}
	else
	{
		newNode->setNextNode(NULL);
		headNode->setNextNode(newNode);
		lastCurrentNode=headNode;
		currentNode=newNode;
	}
	size++;
}
Node * List::get()
{
	if(currentNode!=NULL)
		return currentNode->getNextNode();
}
bool List::next()
{
	if(currentNode==NULL)
		return false;
	lastCurrentNode=currentNode;
	currentNode=currentNode->getNextNode();
	if(currentNode==NULL || size==0)
		return false;
	else
		return true;
}
void traverse(List list)
{
	Node*savedCurrentNode=list.currentNode;
	list.currentNode=list.headNode;
	for(int i=1;list.next();i++)
	{
		cout<<"\nElement "<<i<<" "<<list.get()<<endl;
	}
	list.currentNode=savedCurrentNode;
}
List addNodes()
{
	List list;
	list.add(2);
	list.add(6);
	list.add(8);
	list.add(7);
	list.add(1);
	cout<<"\n List Size=n"<<list.size<<'\n';
	return list;
}