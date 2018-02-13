#include<iostream>
using namespace std;
void showArray(int arr[],int size)
{
    for (int i = 0; i< size; ++i)
	{
      cout <<" " << arr[i];
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
void reverseArray (int* A, int n)
{
	int temp;
	int size=n;
	int i=0;
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			swap(A[j],A[i]);
		}
	}
	showArray(A,n);
}

int main()
{
	const int SIZE=10;
	int arr[SIZE]={1,2,4,5,6,73,7,8,9 ,8};
	reverseArray(arr,SIZE);
	return 0;
}
