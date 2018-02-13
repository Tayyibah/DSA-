//#include<iostream>
//#include"Stack.h"
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
//	//int i=0;
//	int temp1=0;
//	int temp2=0;
//	Stack e(201);
//	char *token=strtok(input, " ");
//	while (token!=NULL)
//	{
//		if (*token=='+' || *token=='-' || *token=='*' || *token=='/')
//		{
//			e.pop(temp1);
//			e.pop(temp2);
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
//		}
//		else if (*token=='~')
//		{
//			e.pop(temp1);
//			e.push((-1)*temp1);
//		}
//		else 
//		{
//			e.push(atof(token));
//		}
//		token=strtok(NULL," ");
//	}
//	int temp3;
//	e.pop(temp3);
//	cout<<temp3<<endl;
//}