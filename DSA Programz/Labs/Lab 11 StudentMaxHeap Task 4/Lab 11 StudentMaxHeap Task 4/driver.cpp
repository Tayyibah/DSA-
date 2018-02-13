#include<iostream>
using namespace std;
#include"StudentMaxHeap.h"

int main()
{
	Student ss;
	StudentMaxHeap s(2);
	s.insert(12,2.3);
	s.removeMax(ss);
	s.display(); 
	s.heepify(3);
	return 0;
}
