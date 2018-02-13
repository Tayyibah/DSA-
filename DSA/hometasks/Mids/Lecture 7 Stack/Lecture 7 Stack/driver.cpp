     #include <iostream>
     #include <string>
    // #include <stdio>
     #include "Stack.h"

int Precedence(char Op)
//Returns precedence value of arithmetic operator Op.
{
  const char Sentinel='@';
  int Result;

  switch(Op)
  {
    case '*'      : Result = 2;
		    break;
    case '/'      : Result = 2;
		    break;
    case '-'      : Result = 1;
		    break;
    case '+'      : Result = 1;
		    break;
    case Sentinel : Result = 0;
		    break;
    default       : Result = -1;
  }
  return Result;
}
void GetToken(char Infix[], int &Next, char &Token)
//Locates next non-blank character after position Next
//in string Infix.
//Pre : Infix contains a non-blank character after position
//      Next and 0 < Next < strlen(Infix).
//Post: Token contains non-blank character and next is
//      position of Token within string Infix.
{
  const char Blank = ' ';

  do
  {
    Next++;
    Token = Infix[Next];
  }
  while (Token == Blank);
}


void DoOperator (char Token, Stack &OpStack, char Postfix[])
//
//Pre : Token and OpStack are defined.
//Post: If Precedence(Token) > Precedence(top of OpStack) then
//      Token is pushed onto OpStack and PostFix is unchanged;
//      otherwise operator is popped of OpStack and concatenated
//      onto the end of string Postfix.
{
  char OldOp;          //old operator on top of stack
  int TokenStacked;    //new operator stacked flag
  int Success;         //stack operator flag
  char *Empty = " ";   //blank string
  char *To;            //used to facilitate concatenation

  do
  {
    if (OpStack.IsEmpty())
    {
      OpStack.Push(Token, Success);
      TokenStacked = true;
    }                                    //stack is empty
    else
    {
      OpStack.Retrieve(OldOp, Success);
      if (Precedence(Token) > Precedence(OldOp))
      {
	OpStack.Push(Token, Success);
	TokenStacked = true;
      }                                  //push token
      else
      {
	OpStack.Pop(OldOp, Success);
	To = &OldOp;
	strncat(Postfix, Empty, 1);
	strncat(Postfix, To, 1);
	TokenStacked = false;
      }                                  //pop OpStack
    }                                    //stack not empty
  }
  while(!TokenStacked);
}

void InfixToPostfix
	  (char Infix[], char Postfix[], int &ValidInfix)
//Converts infix expression stored in string Infix to postfix
//expression stored in Postfix.
//Pre : Infix is defined.
//Post: Either Postfix contains valid postfix representation of
//      infix expression and ValidInfix is True; or Postfix is
//      undefined and ValidInfix is False.
{
  const char Sentinel = '@';
  Stack OpStack(8);                //operator stack
  int Next;                     //next Infix character position
  char *To;                     //string version of Token
  char Token;                   //next token to process
  char TopOp;                   //operator for top of stack
  int Success;                  //stack operator flag
  char *Empty = " ";

  strcpy(Postfix, "");          //initialize Postfix
  Next = -1;                    //start at beginning of Infix
  do
  {
    GetToken(Infix, Next, Token);          //get first token
    if((Token >= 'A') && (Token <= 'Z'))
    {
      To = &Token;                         //insert operand
      strncat(Postfix, Empty, 1);
      strncat(Postfix, To, 1);
    }
    else if ((Token == '+') || (Token == '-') ||
	     (Token == '*') || (Token == '/') ||
	     (Token == Sentinel))
      DoOperator(Token, OpStack, Postfix);
    else
    {
      cout << "Illegal character in expression "<< Token;
      cout << "\n";
      Token = Sentinel;            //force loop exit
    }
  }
  while (Token != Sentinel);

  OpStack.Pop(TopOp, Success);
  ValidInfix = (Success && (TopOp == Sentinel) &&
	       (OpStack.IsEmpty()));
}

void main()
//Program tests infix to postfix conversion functions.
{
  const char Sentinel = '@';
  const int MaxStack=10;
  char Infix[MaxStack];       //infix expression
  char Postfix[MaxStack];
  int ValidInfix;
  char St[] = "";

  do
  {
    strcpy(Infix, St);
    strcpy(Postfix, St);

    cout << "Enter infix string ending with '@' > ";

    cin.getline(Infix, MaxStack, '\n');   //read input string

    if (Infix[0] != Sentinel)
    {
      InfixToPostfix(Infix, Postfix, ValidInfix);
      if (ValidInfix)
	cout << "Postfix is " << Postfix;
      else
	cout << "Improperly formed infix expression.";
      cout << "\n";
    }
  }
  while (Infix[0] != Sentinel);
}/*
________________________________________________________________



Handling Parentheses

The ability to handle parentheses would be an important (and necessary) addition to the conversion functions.  Parentheses are used to separate an expression into subexpressions.  We can think of a opening parenthesis on an operator stack as a boundary or fence between operators.  Whenever we encounter an opening parenthesis we want to push it onto the stack.  We can think of a closing parenthesis as the terminator symbol for a subexpression.  Whenever we encounter a closing parenthesis we want to pop all operators on the stack down to the matching opening parenthesis.  Neither opening nor closing parentheses should appear in the postfix expression.
     To accomplish these objectives, we should modify procedure DoOperator in the following way.  DoOperator should push each opening parenthesis onto the stack as soon as it is encountered.  Since operators following the opening parenthesis should be evaluated before the opening parenthesis, the precedence of the opening parenthesis must be smaller than any other operator.  When a closing parenthesis is encountered, we want to pop all operators up to and including the matching closing parenthesis, inserting all operators popped (except for the opening parenthesis) in the postfix string.  Consequently, the precedence of the closing parenthesis must also be smaller than any other operator except for the opening parenthesis.  A closing parenthesis is considered processed when an opening parenthesis is popped from the stack, and the closing parenthesis is not placed on the stack.
     In Fig. 6.22, functions DoOperator and Precedence are modified to handle parenthesized infix expressions.  Both opening and closing parentheses are assigned a precedence of -1.  The modified sections of code are shown in color.  We must also change the set of operators shown in procedure InfixToPost to include parentheses.
     
Figure 6.22  Functions Precedence and DoOperator Modified to
             Handle Parentheses
________________________________________________________________*/

//int Precedence(char Op)
////Returns precedence value of arithmetic operator Op.
//{
//  const char Sentinel='@';
//  int Result;
//
//  switch(Op)
//  {
//    case '*'      : Result = 2;
//                    break;
//    case '/'      : Result = 2;
//                    break;
//    case '-'      : Result = 1;
//                    break;
//    case '+'      : Result = 1;
//                    break;
//    case Sentinel : Result = 0;
//                    break;
//    case '('      : Result = -1;
//                    break;
//    case ')'      : Result = -1;
//                    break;
//    default       : Result = -2;
//  }
//  return Result;
//}
//
//void DoOperator (char Token, Stack &OpStack, char Postfix[])
////
////Pre : Token and OpStack are defined.
////Post: If Precedence(Token) > Precedence(top of OpStack) then
////      Token is pushed onto OpStack and PostFix is unchanged;
////      otherwise operator is popped of OpStack and concatenated
////      onto the end of string Postfix.
//{
//  int OldOp;          //old operator on top of stack
//  int TokenStacked;    //new operator stacked flag
//  int Success;         //stack operator flag
//  char *Empty = " ";   //blank string
//  char *To;            //used to facilitate concatenation
//
//  do
//  {
//    if (OpStack.IsEmpty() || (Token == '('))
//    {
//      OpStack.Push(Token, Success);
//      TokenStacked = true;
//    }                                    //stack is empty
//    else
//    {
//      OpStack.Retrieve(OldOp, Success);
//      if (Precedence(Token) > Precedence(OldOp))
//      {
//        OpStack.Push(Token, Success);
//        TokenStacked = True;
//      }                                  //push token
//      else
//      {
//        OpStack.Pop(OldOp, Success);
//        if (OldOp == '(')
//          TokenStacked = true;    //parentheses processed
//        else
//        {
//          To = &OldOp;
//          strncat(Postfix, Empty, 1);
//          strncat(Postfix, To, 1);
//          TokenStacked = false;
//        }
//      }                                  //pop OpStack
//    }                                    //stack not empty
//  }
//  while(!TokenStacked);
//}
void PrintBack(int X[],int N)
//Prints an array of integers (X) with subscripts 0 to N.
//Pre : Array X and N are defined and N >= 0.
//Post: Displays X[N], X[N - 1], ... , X[1]. X[0].
{
  if (N == 0)
    cout << X[0] << "\n";   //stopping case
  else
  {
   cout << X[N] << "\n";
   PrintBack(X, N - 1);     //recursive step
  }
}
//void PrintBack(int X[], int N)
////Prints an array of integers with subscripts 0..N.
////Pre : Array X is defined and N >= 0.
////Post: Displays X[N], X[N - 1], ... , X[1], X[0].
//{
//  Stack ParamStack(8);    //stack of integer values
//  int Success;         //operator flag
//
//  ParamStack.Push(N, Success);
//  do
//  {
//    ParamStack.Pop(N, Success);
//    if(N == 0)
//      cout << X[0] << "\n";
//    else
//    {
//      cout << X[N] << "\n";
//      ParamStack.Push(N - 1, Success);
//    }
//  }
//  while (!ParamStack.IsEmpty());
//} 