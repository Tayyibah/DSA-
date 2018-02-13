//hr loop mai do values compare hn gi n swap hn gi
#include<iostream>
using namespace std;
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
int main()
{
	const int SIZE=10;
	int arr[SIZE]={23,11,3,5,6,4,9,5,8,0};
	insertionSort(arr,SIZE);
	return 0;
}