//#include <iostream>
//#include <string>
//#include "Stack.h"
//int Eval(char NextCh, int Op1, int Op2)
////Applies operator NextCh to operands Op1 and Op2.
////Pre : NextCh is an operator; Op1 and Op2 are defined.
////Post: If NextCh is '+', returns Op1 + Op2, and so on.
//{
//  int Result;
//  switch(NextCh)
//  {
//    case '+': Result= Op1 + Op2;
//              break;
//    case '-': Result = Op1 - Op2;
//              break;
//    case '*': Result = Op1 * Op2;
//              break;
//    case '/': Result = Op1/Op2;
//              break;
//    default:  cout<<"invalid expression\n";
//  }
//  return Result;
//}
//
//int IsBalanced(char Expression[])
////Determines where expression is balanced with respect
////to parentheses.
////Pre : Expression is defined.
////Post: Returns True if expression is balanced;
////      otherwise returns False.
//{
//  Stack ParentStack(77);    //stack of open parentheses
//  char NextCh;          //next character in Expression
//  char Close;           //close parenthesis to be matched
//  int Open;            //open parenthesis on top of stack
//  int IsBal;            //program flag
//  int Index;            //index to Expression
//  bool Balanced;         //program flag
//
//  Balanced = true;
//  Index = 0;
//  while(Index < strlen(Expression))
//  {
//    //invariant:
//    //  all closing parentheses so far were matched and
//    //  Index <= strlen(Expression) + 1
//
//    NextCh = Expression[Index];  //get next character
//    if((NextCh == '(') || (NextCh == '[') || (NextCh == '{'))
//      //stack parenthesis
//      ParentStack.push(NextCh);
//    else if
//      ((NextCh == ')') || (NextCh == ']') || (NextCh == '}'))
//    {
//      Close = NextCh;
//      //get nearest unmatched open parenthesis
//      ParentStack.pop(Open);
//      if (Balanced)
//	      switch(Close)    //check for matching parenthesis
//	      {
//	        case ')': Balanced = (Open == '(');
//		             break;
//	        case ']': Balanced = (Open == '[');
//		             break;
//	        case '}': Balanced = (Open == '{');
//		             break;
//	      }
//    }
//    Index = Index + 1;   //access next character
//  }
//  //defne function result
//  if (Balanced)
//   IsBal = ParentStack.isEmpty();
//  else
//   IsBal = false;
//
//  return IsBal;
//}
//
//void main()
////Evaluates postfix expression
//{
//  Stack OpStack(77);               //stack of ntegers
//  const int StrLength = 20;
//  char Expression[StrLength];  //expression to be evaluated
//  char NextCh;                 //next data character
//  int Index;                   //index of next character
//  int Op1;                     //operand values
//  int Op2;
//  int NewOp;                   //new operand for stack
//  int Result=0;                  //result of operator evaluation
//  int Success;                 //flag for stack operation
//  char IntString[StrLength];   //integer string representation
//
//  cout << "Enter your expression > ";
//  cin.getline(Expression, StrLength, '\n');
//
//  Index = 0;
//  Success = true;
//  while (Success && (Index < strlen(Expression)))
//  {
//    //invariant:
//    //  OpStack contains all unprocessed operands and results;
//    //  Index <= strlen(Expression) + 1
//    NextCh = Expression[Index];  //get next character
//    //isdigit() from ctype.h checks if character is digit 0-9
//    if (isdigit(NextCh))
//    {
//      OpStack.getTop( NewOp);  //get value
//      OpStack.push(NewOp);          //push value
//      if (!Success)
//        cout<< "Stack overflow error.\n";
//    }
//    else if ((NextCh == '+') || (NextCh == '-') ||
//	    (NextCh == '*') || (NextCh == '/'))
//    {
//      OpStack.pop(Op2);
//      OpStack.pop(Op1);
//      if (!Success)
//        cout << "Invalid expression.\n";
//      else
//      {
//       Result = Eval(NextCh, Op1, Op2);
//        OpStack.push(Result);
//        if (!Success)
//          cout << "Stack overflow\n";
//      }
//    }
//    Index++;                            //next character
//  }
//
//  if (Success)
//    OpStack.pop(Result);       //get result
//
//  if ((Success) && (OpStack.isEmpty()))
//    cout << "Expression value is " << Result << '\n';
//  else
//    cout << "Invalid expression.\n";
//}
