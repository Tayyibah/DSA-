//#include<iostream>
//using namespace std;
//
//void showArray(int *newArray,int size)
//{
//    for (int i = 0; i< size; ++i)
//	{
//      cout <<" " << newArray[i];
//    }
//	cout<<endl;
//}
//void swap(int &arr1,int &arr2)
//{
//	int temp;
//	temp=arr1;
//	arr1=arr2;
//	arr2=temp;
//}
//void reverseSubArray (int* arr, int start, int end)
//{
//	if(start<=end)
//	{
//		if(start<=end-1)
//		{
//			swap(arr[end-1],arr[start]);
//			reverseSubArray(arr,start+1,end-1);
//		}
//		if(start==end)
//		{
//			swap(arr[start],arr[end]);
//		}
//	}
//}
//int main()
//{
//	const int SIZE=5;
//	int arr[SIZE]={1,2,3,8,4};
//	reverseSubArray (arr,1,5);
//	for(int i=0;i<SIZE;i++)
//	{
//		cout<<arr[i];
//	}
//	return 0;
//}