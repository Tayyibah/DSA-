#include<iostream>
using namespace std;
void displayArray(int * a,int start,int end)
{
	if(start<=end)
	{
		cout<<a[start]<<" ";
		displayArray(a,start+1,end-1);
		cout<<a[end]<<" ";
	}
}
int main()
{
	int arr[]={1,3,5,7};
	displayArray(arr,0,3);
	cout<<endl;
	return 0;
}