#include<iostream>
using namespace std;
#include"FullBinaryTree.h"

int main()
{
	FullBinaryTree fbt(7);
	int arr[7]={1,5,6,7,5,5,3};
	fbt.loadValues(arr,3);
	fbt.sortValues();
	fbt.display();
	return 0;
}