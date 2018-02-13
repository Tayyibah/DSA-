#include<iostream>
using namespace std;
bool BinarySearch(int * a,int start,int end,int key)
{
	if(start>end)
	{
		return false;
	}
	else
	{
		int mid=(start+end)/2;
		if(key==a[mid])
		{
			cout<<mid;
			return true;
		}
		else if(key<a[mid])
		{
			return BinarySearch(a,start,mid-1,key);
		}
		else
		{
			return BinarySearch(a,mid+1,end,key);
		}
	}
	
}
int main()
{
	int arr[]={1,3,5,7};
	BinarySearch(arr,0,3,7);
	cout<<endl;
	return 0;
}