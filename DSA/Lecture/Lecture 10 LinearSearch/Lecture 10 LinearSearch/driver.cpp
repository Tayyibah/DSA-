#include<iostream>
using namespace std;
bool LinearSearch(int * a,int start,int end,int key)
{
	if(start>end)
	{
		return false;
	}

	if(a[start]==key)
	{
		cout<<start;
		return true;
	}
	else
		return LinearSearch(a,start+1,end,key);
}
int main()
{
	int arr[]={1,3,5,7};
	cout<<LinearSearch(arr,0,5,7);
	cout<<endl;
	return 0;
}