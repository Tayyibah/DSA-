#include<iostream>
using namespace std;
int factorial(int n)
{
	if(n==0)
		return 1;
	else
	{
		int temp=factorial(n-1);
		int res=n*temp;
		return res;
	}
}
int powerMethod1(int a,int x)
{
	if(a==1)
		return 1;
	else if(x==0)
		return 1;
	else if(x==1)
		return a;
	else if(x>0)
	{
		int res=a*(powerMethod1(a,x-1));
		return res;
	}
	else if(x<0)
	{
		x=x*-1;
		double res=a*(powerMethod1(a,x-1));
		res=1/res;
		cout<<res<<endl;
		return res;
	}
}
int powerMethod2(int a,int x)
{
	if(a==1)
		return 1;
	else if(x==0)
		return 1;
	else if(x==1)
		return a;
	else if(x>0&&x%2==0)
	{
		int res=powerMethod1(a,x/2)*powerMethod1(a,x/2);
		return res;
	}
	else if(x>0&&x%2!=0)
	{
		int res=a*powerMethod1(a,x/2)*powerMethod1(a,x/2);
		return res;
	}
	else if(x<0&&x%2==0)
	{
		x=x*-1;
		double res=powerMethod1(a,x/2)*powerMethod1(a,x/2);
		res=1/res;
		cout<<res<<endl;
		return res;
	}
	else
	{
		x=x*-1;
		double res=a*powerMethod1(a,x/2)*powerMethod1(a,x/2);
		res=1/res;
		cout<<res<<endl;
		return res;
	}
}
int main()
{
	cout<<factorial(4)<<endl;
	powerMethod1(2,-4);
	powerMethod2(2,-4);
	return 0;
}