#include<iostream>
using namespace std;
//
//int quotient (int num, int den)
//{
//	if(den==0)
//	{
//		cout<<"Infinity "<<endl;
//		return -1;
//	}
//	else if(num==den)
//		return 1;
//	else
//	{
//		int q=0;
//		q=num/quotient(num-1,den)-den;
//		return q;
//	}
//}
//
//int main()
//{
//	cout<<quotient(50,5)<<endl;
//	return 0;
//}

int quotient(int a, int b)
{
	if(a<b)
		return 0;
	else
		return(quotient(a-b,b)+1);
}

void main()

{
	int a=7, b=80, ql;
	ql=quotient(a,b);
	cout<<"Quotient ql is : "<<ql <<"\n";

}