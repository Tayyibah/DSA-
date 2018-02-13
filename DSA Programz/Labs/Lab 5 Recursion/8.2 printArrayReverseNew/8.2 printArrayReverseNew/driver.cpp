#include<iostream>
using namespace std;

void printArrayReverseNew (int* arr, int n)
{
	int start=0;
	if(n-1>=start)
	{
		 if(n-1==start)
			cout<<arr[n-1]<<" ";
		else if(n-1>start)
		{
			cout<<arr[n-1]<<" ";
			printArrayReverseNew(arr,n-1);
		}
	}
}

int main()
{
	const int SIZE=6;
	int arr[SIZE]={1,2,4,6,5,3};
	printArrayReverseNew (arr,6);
	return 0;
}