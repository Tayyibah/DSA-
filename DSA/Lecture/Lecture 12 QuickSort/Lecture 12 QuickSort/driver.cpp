#include<iostream>
using namespace std; 

void showArray(int *newArray,int size)
{
    for (int i = 0; i< size; i++)
	{
      cout << newArray[i] <<" ";
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
		showArray(a,end+1);
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
		//showArray(a,end);
	return j;
}
void QuickSort(int *a,int start,int end)
{
	if(start<end)
	{
		int p=partition(a,start,end);
		QuickSort(a,start,p-1);
		QuickSort(a,p+1,end);
		//showArray(a,end);
	}
}
int main()
{
	int a[10]={8,2,6,3,5,8,9,2,3,0};
	QuickSort(a,0,9);
	showArray(a,10);
	return 0;
}