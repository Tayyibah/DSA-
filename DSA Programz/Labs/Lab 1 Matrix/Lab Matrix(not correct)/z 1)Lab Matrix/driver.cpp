#include<iostream>
#include"TwoDMatrix.h"
using namespace std;
int main()
{
	TwoDMatrix m();
	TwoDMatrix m1(3,3);
	TwoDMatrix m2(3,3);
	int val=10;
	m1.get(1,2,val);
	m1.set(0,0,5);
	m1.set(0,1,5);
	m1.set(0,2,5);
	m1.set(1,0,5);
	m1.set(1,1,5);
	m1.set(1,2,5);
	m1.set(2,0,5);
	m1.set(2,1,5);
	m1.set(2,2,5);
	m1.display();
	m1.add (m1,m2);
	m1.display();
	m1.displaySubMatrix (0,2,0,2);
	m1.transpose();
	m1.display();
	m1.multiply (m1,m2);
	m1.display();
	char a;
	cin>>a;
	return 0;
}