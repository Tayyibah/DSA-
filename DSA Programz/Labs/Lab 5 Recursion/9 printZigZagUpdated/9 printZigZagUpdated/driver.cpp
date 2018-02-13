#include<iostream>
using namespace std;
void printZigZagUpdated (int* pStart, int* pEnd)
{
	int start=0;
	int end=5;
	if(start == end-1)
	{
		cout<<pStart[start]<<" ";
		cout<<pEnd[start+1]<<" ";
	}
	else if(start < end-1)
	{
		cout<<pStart[start+1]<<" ";
		cout<<pEnd[start+1]<<" ";
		printZigZagUpdated (pStart,pEnd);
	}
}

int main()
{
	const int SIZE=5;
	int pStart[SIZE]={1,2,3,4,5};
	int pEnd[SIZE]={6,7,8,9,10};
	printZigZagUpdated(pStart,pEnd);
	return 0;
}