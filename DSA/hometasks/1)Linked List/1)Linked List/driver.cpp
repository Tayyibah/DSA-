#include<iostream>
using namespace std;
#include"Node.h"
#include"List.h"
int main()
{
	List list=addNodes();
	traverse(list);
	return 0;
}