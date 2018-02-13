#include<iostream>
using namespace std;

int findSum (int* arr, int start, int end)
{
	if(start>end)
		return 0;
	else if(start==end)
		return arr[start];
	else
	{
		return findSum(arr,start+1,end)+arr[start];
	}
}

int main()
{
	const int SIZE=5;
	int arr[SIZE]={1,2,3,4,5};
	cout<<findSum(arr,0,4)<<endl;
	return 0;
}