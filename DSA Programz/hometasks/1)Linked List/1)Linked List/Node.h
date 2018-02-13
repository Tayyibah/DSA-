#ifndef NODE_H
#define NODE_H
class Node
{
public:
	int getObject()
	{
		return object;
	}
	Node* getNextNode()
	{
		return nextNode;
	}
	void setNextNode(Node *  next)
	{
		this->nextNode=next;
	}
	void setObject(int obj)
	{
		this->object=obj;
	}
	Node * NextNode;
private:
	Node * nextNode;
	int object;
};
#endif

