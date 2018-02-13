#include<iostream>
using namespace std;
int count=0;
int countDigit(int num)
{
	if(num/10==0)
	{
		return 1;
	}
	else
	{

		int count=1;
		num=num/10;
		count=count+countDigit(num);
		return count;
	}
}
int main()
{
	cout<<countDigit(65465)<<endl;
}
