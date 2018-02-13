#ifndef SORTEDLIST_H
#define SORTEDLIST_H
class SortedList
{
private:
	int *a;
	int maxSize;
	int currSize;
public:
	SortedList();
	SortedList(int n);
	~SortedList();
	bool isFull();
	bool insert(int val);
	void displayArray();
	bool remove(int val);
	int removeAll(int val);
	bool modify(int index,int newValue);
	SortedList operator=(SortedList& val);
	SortedList(SortedList&ref);
};
#endif

