#include<iostream>
using namespace std;

void printZigZag (int* arr, int start, int end)
{
	if(start == end-1)
	{
		cout<<arr[start]<<" ";
	}
	else if(start < end-1)
	{
		cout<<arr[start]<<" ";
		cout<<arr[end-1]<<" ";
		printZigZag (arr,start+1, end-1);
	}
}

int main()
{
	const int SIZE=6;
	int arr[SIZE]={7,1,2,9,6,8};
	printZigZag (arr,0, SIZE);
	cout<<endl;
	return 0;
}