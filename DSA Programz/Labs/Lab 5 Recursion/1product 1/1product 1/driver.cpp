#include<iostream>
using namespace std;

int product (int a, int b)
{
	if(a==0 || b==0)
		return 0;
	else if(a==1 && b==1)
		return 1;
	else if(a==1 && b!=1)
		return b;
	else if(a!=1 && b==1)
		return a;
	else 
	{
		int sum=0;
		sum=a+product(a,b-1);
		return sum;
	}
}

int main()
{
	cout<<product(3,8)<<endl;
	return 0;
}