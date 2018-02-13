#include<iostream>
#include "Queue.h"
using namespace std;
int main()
{
	Queue q(5);
	q.enqueue(23);
	q.enqueue(6);
	q.enqueue(11);
	int val;
	q.dequeue(val);
	q.enqueue(8);
	q.enqueue(4);
	q.dequeue(val);
	return 0;
}