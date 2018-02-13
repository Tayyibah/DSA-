#include<iostream>
using namespace std;

void printArrayReverse (int* arr, int start, int end)
{
	if(end>=start)
	{
		 if(end==start)
			cout<<arr[end]<<" ";
		else if(end>start)
		{
			cout<<arr[end]<<" ";
			printArrayReverse(arr,start,end-1);
		}
	}
}

int main()
{
	const int SIZE=5;
	int arr[SIZE]={1,2,3,4,5};
	printArrayReverse (arr,0,4);
	return 0;
}