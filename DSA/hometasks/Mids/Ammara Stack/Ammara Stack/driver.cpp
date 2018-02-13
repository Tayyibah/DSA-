//#include<iostream>
//#include"stack.h"
//#include <cstring>
//#include <cstdlib>
//#include <cctype>
//using namespace std;
//void evaluatePostfixExpression ( char* input );
//void main()
//{
//	char *input;
//	input = new char [200];
//	cout<<"Please enter a postfix expression";
//	cin.getline(input,200);
//    evaluatePostfixExpression ( input );
//}
//void evaluatePostfixExpression ( char *input )
//{
//	bool flag=false;
//	double temp1=0;
//	double temp2=0;
//	Stack e(201);
//	char *token=strtok(input, " ");
//	while (token!=NULL)
//	{
//		token=strtok(input, " ");
//		if (*token=='+' || *token=='-' || *token=='*' || *token=='/')
//		{
//			if (!e.pop(temp1))
//				{
//					cout<<"operand are few"<<endl;
//					flag=true;
//					break;
//			}
//			if (!e.pop(temp2))
//			
//			if (*token=='+')
//			{
//				
//				e.push(temp2+temp1);
//			}
//			else if (*token=='-')
//			{
//				e.push(temp2-temp1);
//			}	
//			else if (*token=='*')
//			{
//				e.push(temp2*temp1);
//			}
//			else if (*token=='/')
//			{
//				e.push(temp2/temp1);
//			}
//	}
//			else if (*token=='~')
//			{
//				//e.pop(temp1);
//				if (!e.pop(temp1))
//				{
//					cout<<"operand are few"<<endl;
//					flag=true;
//					break;
//				}
//				e.push((-1)*temp1);
//			}
//			else if (atof(token)) 
//			{
//				e.push(atof(token));
//			}
//			else
//			{
//				cout<<"invalid operator"<<endl;
//				flag=true;
//			}
//			token=strtok(NULL," ");
//	}
//	double temp3;
//	e.pop(temp3);
//		if (!flag)
//		{
//			if (!e.isEmpty())
//			{
//				cout<<"Few operators"<<endl;
//			}
//			else
//			{
//				cout<<temp3<<endl;
//			}
//		}
//		
//
//}