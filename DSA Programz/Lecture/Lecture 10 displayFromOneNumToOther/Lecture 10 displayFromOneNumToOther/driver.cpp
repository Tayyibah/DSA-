#include<iostream>
using namespace std;
void displayArray(int start,int end)
{
	if(start<=end)
	{
		cout<<start<<" ";
		displayArray(start+1,end-1);
		cout<<end<<" ";
	}
}
int main()
{
	displayArray(5,10);
	cout<<endl;
	return 0;
}