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
int intersection1 (int* A, int* B, int* C, int n)
{
	int size=0;
	int k=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(A[i]==B[j])
			{
				C[k]=A[i];
				size++;
				k++;
			}
		}
	}
	showArray(C,size);
	return size;
}
int intersection2 (int* A, int* B, int* C, int n)
{
	bool found=false;
	int start=0;
	int end=n-1;
	int mid,key;
	int i=0,k=0,size=0;
	for(int i=0;i<n;i++)
	{
		found=false;
		start=0;
		end=n-1;
		key=B[i];
		while(!found&&start<=end)
		{
			mid=(start+end)/2;
			if(A[mid]==key)
			{
				C[k]=A[mid];
				found=true;
				k++;
				size++;
			}
			else if(A[mid]>key)
			{
				end=mid-1;
			}
			else 
			{
				start=mid+1;
			}
		}
	}
	showArray(C, size);
	return size;
}
int intersection3 (int* A, int* B, int* C, int n)
{
	int size=0,k=0,j=0;
	int i=0;
	while(i<n)
	{
		if(j==n)
		{
			j=0;
			i++;
		}
		if(A[i]==B[j])
		{
			C[k++]=A[i];
			size++;
			i++;
			j++;
		}
		else
		{
			j++;
		}
	}
	showArray(C, size);
	return size;
}
int main()
{
	const int SIZE=10;
	int arr1[SIZE]={1,2,3,4,5,6,7,8,9,16 };
	int arr2[SIZE]={7,8,9,10 ,11,12,13,14,15};
	int arr3[SIZE];
	cout<<intersection1(arr1,arr2,arr3,SIZE)<<endl;
	cout<<intersection2(arr1,arr2,arr3,SIZE)<<endl;
	cout<<intersection3(arr1,arr2,arr3,SIZE)<<endl;
	return 0;
}
