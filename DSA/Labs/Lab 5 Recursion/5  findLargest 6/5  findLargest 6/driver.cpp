#include<iostream>
using namespace std;

int findLargest (int* arr, int start, int end)
{
	if(start>end)
		return 0;
	else if(start==end)
		return arr[start];
	else
	{
		int largest=arr[start];
		int lar=findLargest(arr,start+1,end);
		if(largest<lar)
			largest=lar;
		return largest;
	}
}

int main()
{
	const int SIZE=6;
	int arr[SIZE]={-1,-2,-4,-6,5,0};
	cout<<findLargest(arr,0,5)<<endl;
	return 0;
}