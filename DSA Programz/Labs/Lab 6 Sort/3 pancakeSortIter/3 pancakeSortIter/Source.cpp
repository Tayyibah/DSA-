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
void showArray(int *newArray,int size)
{
    for (int i = 0; i< size; ++i)
	{
      cout <<" " << newArray[i];
    }
	cout<<endl;
}
void swap(int &arr1,int &arr2)
{
	int temp;
	temp=arr1;
	arr1=arr2;
	arr2=temp;
}
void reverseSubArray (int* arr, int start, int end)
{
	if(start<=end)
	{
		if(start<end)
		{
			swap(arr[end],arr[start]);
			reverseSubArray(arr,start+1,end-1);
		}
		if(start==end)
		{
			swap(arr[start],arr[end]);
		}
	}
}
void pancakeSortIter (int* arr, int start, int end)
{
	int n=end;
	for (int i = 0; i< end; i++)
	{
		int ind=largestIndex( arr ,start, n );
		cout<<ind<<endl;
		reverseSubArray (arr, 0, ind);
		showArray( arr,start+n);
		reverseSubArray (arr, start,n-1);
		showArray( arr,start+n);
		n=n-1;
    }
}
int main()
{
	const int SIZE=5;
	int arr[SIZE]={4, 8, 7, 2};
	pancakeSortIter (arr,0,4);
	showArray( arr,4);
	return 0;
}