#include<iostream>
using namespace std;
	
int findKthLargest (int* A, int n, int k)
{
	int swap;
	int temp;
	do
	{
		swap=false;
		for(int i=0;i<n-1;i++)
		{
			if(A[i]>A[i+1])
			{
				temp=A[i];
				A[i]=A[i+1];
				A[i+1]=temp;
				swap=true;
			}
		}
	}while(swap);
	int * arr=new int[n];
	int j=0;
	for(int i=n-1;i>=0;i-- )
	{
		arr[i]=A[j];
		j++;
	}
	return arr[k-1];
}

int main()
{
	const int SIZE=10;
	int arr[SIZE]={1,2,3,4,5,6,7,8,9 };
	int k=2;
	cout<<findKthLargest(arr,SIZE,k)<<endl;
	return 0;
}
