#include<iostream>
#include "Stack.h"
#include<cstring>
#include<cstdlib>
#include<cctype>
using namespace std;

void parenthesizedExpression(Stack st);
void notparenthesizedExpression(Stack st);
void display(char temp);
int precedence(char ch);

int main()
{
	Stack s(5);
	char arr[]="3+4";
	char str[]="1776ad";
  int year;
  if (isdigit(str[0]))
  {
    year = atoi (str);
  }
	int j=0,k=0;
	for(int i=0;arr[i]!='\0';i++)
	{
		s.push(arr[i]-48);
		j++;
	}
	int val=0;
	display( s.getTop(val));
	cout<<val;
	parenthesizedExpression(s);
	notparenthesizedExpression(s);
	precedence(s.getTop(val));
	return 0;
}

void notparenthesizedExpression(Stack st)
{
	int i=0;
	/*int operand=0;
	char operatr=' ';*/
	char ch=st.getTop(ch)-48;
	int temp=st.getTop(temp)-48;
	if(temp==isdigit(temp))
	{
		display( temp);
	}
	else if(ch=='(')
		st.push(ch);
	else if(ch==')')
	{
		st.getTop(temp);
		while(temp!='(')
		{
			st.pop(temp);
			display(temp);
			st.getTop(temp);
		}
		st.pop(temp);
	}
	else if(ch==isdigit(temp))
	{
		while(!st.isEmpty()&&precedence(ch)<=precedence(st.getTop(temp)))
		{
			st.pop(temp);
			display(temp);
		}
		st.push(ch);
	}
	while(!st.isEmpty())
	{
		st.pop(temp);
		display(temp);
	}
}
void parenthesizedExpression(Stack st)
{
	int i=0;
	int operand=0;
	char operatr=0; 
	char ch=' ';
	while(st.getTop(operand)&&st.getTop(ch))
	{
		if(ch=='('||operand==isdigit(operand)||ch==cin.get())
			st.push(ch);
		else if(ch==')')
		{
			st.pop(operand);
			while(operand!='(')
			{
				st.pop(operand);
			}
		}
	}
	st.getTop(operand);
}

int precedence(char ch)
{
	if(ch=='~')
		return 1;
	else if(ch=='!')
		return 2;
	else if(ch=='*')
		return 3;
	else if(ch=='/')
		return 4;
	else if(ch=='%')
		return 5;
	else if(ch=='+')
		return 6;
	else if(ch=='-')
		return 7;
	else if(ch=='<')
		return 8;
	else if(ch=='<=')
		return 9;
	else if(ch=='>=')
		return 10;
	else if(ch=='>')
		return 11;
	else if(ch=='==')
		return 12;
	else if(ch=='!=')
		return 13;
	else if(ch=='&&')
		return 14;
	else if(ch=='||')
		return 14;
}
void display(char temp)
{
	cout<<temp;
}