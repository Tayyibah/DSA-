#include<iostream>
using namespace std; 

bool isEven(int num)
{
	if(num==0)
	{
		return true;
	}
	else if(num==1)
	{
		return false;
	}
	else 
	{
		num=num-2;
		isEven(num);
	}
}
int main()
{
	
	cout<<isEven(14);
	return 0;
}