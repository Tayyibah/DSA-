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

int partition(int *a,int start,int end)
{
	int pivot=start;
	int i=start;
	int j=end+1;
	while(i<j)
	{
		do{
			i=i+1;
		}while(i<end&&a[i]<a[pivot]);
		do{
			j=j-1;
		}while(j>start&&a[j]>a[pivot]);
		if(i<j)
			swap(a[i],a[j]);
		showArray(a,end);
	}
	swap(a[pivot],a[j]);
		showArray(a,end);
	return j;
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
void insertionSort(int *arr,int SIZE)
{
	for(int i=1;i<SIZE;i++)
	{
		int temp=arr[i];
		int j=i-1;
		while(j>=0&&temp<arr[j])
		{
			arr[j+1]=arr[j];
			j--;
	showArray(arr,SIZE);
		}
		arr[j+1]=temp;
	}
	showArray(arr,SIZE);
}
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