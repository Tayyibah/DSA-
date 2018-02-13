#include<iostream>
using namespace std;

int largestIndex (int* arr, int start, int end)
{
	if ( arr[0] >= start && arr[0] <= end )
	{
		int n = 1 + largestIndex( arr + 1,start+1, end );
		return ( n == 0 ? -1 : n ); 
	}
}

int main()
{
	const int SIZE=5;
	int arr[SIZE]={1,2,5,4,3};
	cout<<largestIndex(arr,0,4)<<endl;
	return 0;
}
