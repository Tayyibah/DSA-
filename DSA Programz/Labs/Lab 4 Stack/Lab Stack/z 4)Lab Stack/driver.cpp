#include<iostream>
#include "Stack.h"
using namespace std;

int main()
{
	Stack operandStack1(50);
	Stack operandStack2(50);
	Stack resultStack(50);

	int i=0,j=0,k=0;
	char arr1[]="123456789123456789123456789";
	char arr2[]="987654321987654321987654321";
	for(int i=0;arr1[i]!='\0';i++)
	{
		operandStack1.push(arr1[i]-48);
		j++;
	}
	int size1=j;
	for(int i=0;arr2[i]!='\0';i++)
	{
		operandStack2.push(arr2[i]-48);
		k++;
	}
	int size2=k;
	int digit=0,num=0,n1=0,n2=0;
	int carry=0;
	for(int i=size1-1, j=size2-1;i>=0 || j>=0;i--,j--)
	{
		int num1=arr1[i]-48;
		int num2=arr2[j]-48;
		int f4c1, f4c2;
		if(!operandStack1.isEmpty()&&!operandStack2.isEmpty())
		{
			operandStack1.pop(num1);
			operandStack2.pop(num2);
			f4c1=num1;
			f4c2=num2;
			num=f4c1+f4c2+carry;
		}
		else if(operandStack2.isEmpty())
		{
			operandStack1.pop(num1);
			f4c1=num1;
			num=f4c1+carry;
		}
		else if(operandStack1.isEmpty())
		{
			operandStack2.pop(num2);
			f4c2=num2;
			num=f4c2+carry;
		}
		if(num>=10)
		{
			digit = num % 10;
			carry = num / 10;
		}
		else
			digit = num;
		resultStack.push(digit);
	}
	n1=0;
	for(int i=0;!resultStack.isEmpty();i++)
	{
		int val;
		resultStack.getTop(val);
		resultStack.pop(val);
		cout<<val;
	}
	cout<<endl;
	return 0;
}