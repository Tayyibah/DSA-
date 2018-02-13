#ifndef LIST_H
#define LIST_H
class List
{
private:
	int *a;
	int maxSize;
	int currSize;
public:
	List();
	List(int n);
	~List();
	bool insert(int val);
	bool getValue(int index,int &val);
	void displayArray();
	bool removeAllVerson(int val);
	bool removeValue1(int index,int val);
	bool removeValue2(int index,int val);
	bool removeAllVerson1(int val);
	bool removeAllVerson2(int val);
	List operator=(List& val);
	List(List&ref);
};
#endif

