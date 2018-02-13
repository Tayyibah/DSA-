#include<iostream>
using namespace std;
#include"SortedList.h"
int main()
{
	SortedList l(10);
	l.insert(1);
	l.insert(2);
	l.insert(3);
	l.insert(2);
	l.insert(5);
	l.insert(5);
	l.insert(10);
	l.displayArray();
	l.remove(2);
	l.displayArray();
	l.removeAll(2);
	l.displayArray();
	l.modify(1,6);
	l.displayArray();
	return 0;
}