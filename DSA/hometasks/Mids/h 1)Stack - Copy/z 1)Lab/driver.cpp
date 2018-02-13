//#include<iostream>
//#include "Stack.h"
//using namespace std; 
//#include<cstring>
//#include<cstdlib>
//#include<cctype>
//#include "CString.h"
//void inputArr()
//{
//	char * data=0;
//	int size=10;
//	cout << "Enter string:";
//	cin.getline(data, size,'\n');
//}
//int getLength(char * name)
//{
//	int i=0;
//	while(name[i]!='\0')
//	{
//		i++;
//	}
//	return i;
//}
//void display(int data)
//{
//	cout<<data;
//	cout<<endl;
//}
//int precedence(char ch)
//{
//	if(ch=='~')
//		return 1;
//	else if(ch=='!')
//		return 2;
//	else if(ch=='*')
//		return 3;
//	else if(ch=='/')
//		return 4;
//	else if(ch=='%')
//		return 5;
//	else if(ch=='+')
//		return 6;
//	else if(ch=='-')
//		return 7;
//	else if(ch=='<')
//		return 8;
//	else if(ch=='<=')
//		return 9;
//	else if(ch=='>=')
//		return 10;
//	else if(ch=='>')
//		return 11;
//	else if(ch=='==')
//		return 12;
//	else if(ch=='!=')
//		return 13;
//	else if(ch=='&&')
//		return 14;
//	else if(ch=='||')
//		return 14;
//}
//void display(char * data)
//{
//	for(int i=0;i<getLength(data);i++)
//		cout<<data[i];
//	cout<<endl;
//}
//void evaluatePostfixExpression ( char* input )
//{
//	CString c;
//	Stack s(10);
//	cout<<"Enter the postfix expression: ";
//	char str1[]="12 3 ~ 1 - / 4.6 ~ *";	
//	int len=getLength(str1);
//	display(str1); 
//	char * pch;
//	printf ("Splitting string \"%s\" into tokens:\n",str1);
//	pch = strtok (str1," ");int i=0;
//	/*int operand=0;
//	char operatr=' ';*/
//	while (pch != NULL)
//	{
//		printf ("Token %s\n",pch);
//		int operand=0;
//		char operatr=0;
//	    if (isdigit(str1[i]))
//	    {
//			operatr = atoi (str1);
//	    }
//		//char ch=str1[i];
//		//int temp=s.getTop(temp)-48;
//	if(operatr==isdigit(operatr))
//	{
//		display( operatr);
//	}
//	else if(operatr=='(')
//		s.push(operatr);
//	else if(operatr==')')
//	{
//		s.getTop(temp);
//		while(temp!='(')
//		{
//			s.pop(temp);
//			display(temp);
//			s.getTop(temp);
//		}
//		s.pop(temp);
//	}
//	else if(operatr==isdigit(temp))
//	{
//		while(!s.isEmpty()&&precedence(operatr-48)<=precedence(s.getTop(temp)))
//		{
//			s.pop(temp);
//			display(temp);
//		}
//		s.push(operatr);
//	}
//	while(!s.isEmpty())
//	{
//		s.pop(temp);
//		display(temp);
//	}
//	 i=0;
//	
//		
//		if(operatr=='('||isdigit(operatr)||!isdigit(operatr)&& operatr!=' ')
//		{
//			operatr = atoi (str1);
//			s.push(operatr-48);
//		}
//			else if(str1[i]==')')
//			{
//				s.pop(operand);
//				while(str1[i]!='(')
//				{
//					s.pop(operand);
//				}
//			}
//		s.getTop(operand);
//		i++;
//		pch = strtok (NULL, " "); 
//	}
//	cout<<endl;
//
//	/*char keys[] = "+";
//	int i = strcspn (str1,keys);
//	cout<<i;
//	printf ("The first number in str is at position %d.\n",i+1);*/
//}
////bool doAgain();
////
////int main()
////{
////	while(doAgain());
////	cout << "Valid input.\n";
////	return 0;
////}
////
////bool doAgain()
////{
////	char a[4];
////	cout << "Enter a 4 digit number: " ;
////	for(int i=0;i<4;i++)
////	{
////		cin >> a[i];
////		if(!isdigit(a[i])) // checks if character by character is a digit or not.
////		{
////			cout << "Inputs contains non integer char.\n";
////			cin.ignore(); //ignores the rest of the input.
////			return 1;
////		}
////	}
////	char x = cin.get();
////	if(x!='\n') // if you find 1 more char available for input and that character is not the enter button.
////	{
////		cout << "Input contains more than 4 characters.\n";
////		cin.ignore(); //ignores the rest of the characters in the input stream.
////		return 1;
////	}
////
////
////	return 0;
////}
//int main()
//{
//	Stack operandStack1(50);
//	Stack operandStack2(50);
//	Stack resultStack(50);
//	char *arr2="4+3";
//	evaluatePostfixExpression(arr2);
//	/*char arr2[]="987654321987654321987654321";
//	for(int i=0;arr1[i]!='\0';i++)
//	{
//	operandStack1.push(arr1[i]-48);
//	j++;
//	}
//	int size1=j;
//	for(int i=0;arr2[i]!='\0';i++)
//	{
//	operandStack2.push(arr2[i]-48);
//	k++;
//	}
//	int size2=k;
//	int digit=0,num=0,n1=0,n2=0;
//	int carry=0;
//	for(int i=size1-1, j=size2-1;i>=0 || j>=0;i--,j--)
//	{
//	int num1=arr1[i]-48;
//	int num2=arr2[j]-48;
//	int f4c1, f4c2;
//	if(!operandStack1.isEmpty()&&!operandStack2.isEmpty())
//	{
//	operandStack1.pop(num1);
//	operandStack2.pop(num2);
//	f4c1=num1;
//	f4c2=num2;
//	num=f4c1+f4c2+carry;
//	}
//	else if(operandStack2.isEmpty())
//	{
//	operandStack1.pop(num1);
//	f4c1=num1;
//	num=f4c1+carry;
//	}
//	else if(operandStack1.isEmpty())
//	{
//	operandStack2.pop(num2);
//	f4c2=num2;
//	num=f4c2+carry;
//	}
//	if(num>=10)
//	{
//	digit = num % 10;
//	carry = num / 10;
//	}
//	else
//	digit = num;
//	resultStack.push(digit);
//	}
//	n1=0;
//	for(int i=0;!resultStack.isEmpty();i++)
//	{
//	int val;
//	resultStack.getTop(val);
//	resultStack.pop(val);
//	cout<<val;
//	}*/
//	cout<<endl;
//	return 0;
//}