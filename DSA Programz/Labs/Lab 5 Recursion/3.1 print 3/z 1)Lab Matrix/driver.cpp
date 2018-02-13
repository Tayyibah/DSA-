#include<iostream>
using namespace std;

void printChar (char ch, int n)
{
	if(n>0)
	{
		cout<<ch;
		printChar(ch,n-1);
	}
}

int main()
{
	printChar('Z',5);
	cout<<endl;
	return 0;
}