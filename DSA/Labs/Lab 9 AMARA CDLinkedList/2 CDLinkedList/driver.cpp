#include<iostream>
using namespace std;
#include "CDLinkedList.h"
void main()
{
	CDLinkedList cd1;
	cd1.insert(4);
	cd1.insert(7);
	cd1.insert(10);
	cd1.insert(12);
	cd1.display();
	////cd.remove2(1);
	////cout<<"After removing :"<<endl;
	////cd.display();
	CDLinkedList cd2;
	cd2.insert(1);
	cd2.insert(3);
	cd2.insert(6);
	cd2.insert(8);
	cd2.insert(9);
	cd2.insert(15);
	cd2.display();
	/*CDLinkedList cd;*/
	/*cd.merge(cd1,cd2);
	cout<<"after merge" <<endl;
	cd.display();*/
	cd2.mergeSort();
	cd2.display();
	//cout<<"after sorting 2nd node:"<<endl;
	cd1.splitList(cd1,cd2);
	cd2.display();
	cd1.display();
	//cout<<"largest is :"<<cd1.findMax();
	/*CDLinkedList leftHalf;
	CDLinkedList rightHalf;
	CDLinkedList list;
	list.insert1(8);
	list.insert1(4);
	list.insert1(2);
	list.insert1(9);
	list.insert1(1);
	list.insert1(5);
	list.insert1(3);
	cout<<"List is:"<<endl;
	list.display();
	list.splitList(leftHalf,rightHalf);
	cout<<"left half is :"<<endl;
	leftHalf.display();
	cout<<"right half is :"<<endl;
	rightHalf.display();*/
}