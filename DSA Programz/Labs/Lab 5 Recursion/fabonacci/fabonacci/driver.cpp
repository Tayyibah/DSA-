#include <iostream>
using namespace std;

int fib(int n)    // 1, 1, 2, 3, 5, 8, 13, 21, ...  
{
	if (n == 0 )
		return 0;
	else if( n == 1) 
		return 1;  
	return fib(n-1) + fib(n-2);
}

int  main()
{
	int n;
	cout << "Enter a non-negative integer: ";
	cin >> n;
	cout << "Fib(" << n << ") = " << fib(n) << "." << endl;  
	return 0;
}