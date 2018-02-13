#include<iostream>
using namespace std;
#include"List.h"
int main()
{
	List l(10);
	l.insert(1);
	l.insert(2);
	l.insert(3);
	l.insert(2);
	l.insert(5);
	l.insert(4);
	l.insert(5);
	l.insert(6);
	l.insert(6);
	l.insert(2);
	l.insert(7);
	l.insert(5);
	l.insert(8);
	int val;
	l.displayArray();
	l.getValue(2,val);
	l.removeValue1(1,5);
	l.displayArray();
	l.removeValue2(1,3);
	l.displayArray();
	val=5;
	l.removeAllVerson1(val);
	l.displayArray();
	val=6;
	l.removeAllVerson2(val);
	l.displayArray();
	val=2;
	l.removeAllVerson(val);
	l.displayArray();
	return 0;
}