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
void bubbleSort(int *arr,int SIZE)
{
	for(int i=SIZE-1;i>0;i--)
	{
		for(int j=0;j<i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap(arr[j],arr[j+1]);
			}
		}
	}
	showArray(arr,SIZE);
}
int main()
{
	const int SIZE=10;
	int arr[SIZE]={23,11,3,5,6,4,9,5,8,0};
	bubbleSort(arr,SIZE);
	return 0;
}