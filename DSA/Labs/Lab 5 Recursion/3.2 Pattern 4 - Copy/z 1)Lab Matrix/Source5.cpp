
#include<iostream>
using namespace std;

void printChar (char ch, int n)
{
	int space = 0;
	if(space+n==0)
	{
		ch=' ';
		space++;
	}
	else if(n<5)
	{
		space++;
		cout<<ch;
		printChar(ch,n+1);
	}
}

void printPattern (char ch, int n)
{
	if(n>=0)
	{
		printChar(ch,n);
		cout<<endl;
		printPattern(ch,n-1);
	}
}
int main()
{
	printPattern('*',5);
	return 0;
}