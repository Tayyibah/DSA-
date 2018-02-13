#include "Stack.h"


void Stack::Push(char X, int &Success)
//Pushes X onto stack.
//Pre : X is defined and Stack s initialized.
//Post: Sets Success to True to indicate successful push;
//      and False to indicate failure.
{
  if (Top >= MaxStack)
    Success = false;     //no room on stack
  else
  {
    Top++;              //increment stack top pointer
    Items[Top] = X;     //copy X to stack
    Success = true;
  }
}

void Stack::Pop(char &X, int &Success)
//Pops top of a stack into X.
//Pre : Stack has been initialized.
//Post: X contains top stack element which has been removed
//      from the stack. Success is set to True if pop is
//      successful and False if not.
{
   if (Top < 0)
     Success = false;    //empty stack
   else
   {
     X = Items[Top];     //pop top of stack into X
     Top--;              //decrement top of stack pointer
     Success = true;
   }
}

void Stack::Retrieve(char &X, int &Success)
//Copies value at top of stack to X.
//Pre : Stack is defined.
//Post: X contains top stack element and the stack is
//      unchanged. Success set to True for successful
//      retrieve and False otherwise.
{
  if (Top < 0)
    Success=0;
  else
  {
    X = Items[Top];      //copy top stack element
    Success = true;
  }
}

int Stack::IsEmpty()
//Returns True if stack is empty and False otherwise.
{
  return(Top < 0);
}

int Stack::IsFull()
//Returns True is stack is Full and False otherwise.
{
  return(Top >= MaxStack);
}
//_______________________________________________________________
//
//
//
//     The constructor Stack() must be used before the stack can be manipulated.  In Stack(), the statement
//        Top = -1;
//initializes a stack by setting its top of stack pointer to -1. 
//     Method Stack::Push increments the top of stack pointer before pushing a new value onto the stack.  Method Stack::Pop copies the value at the top of the stack (denoted by Items[Top]) into X before decrementing the top of stack pointer.  Method Stack::Retrieve copies the value at the top of the stack into X without changing the top of stack pointer.  Methods Stack::IsFull and Stack::IsEmpty test the top of stack pointer to determine the stack status.  When the value of data member Top is greater than or equal to MaxStack there is no more room to store elements in the stack.  When the value of Top is -1 the stack is empty.
//
//------------------------------------------
//Program Style
//Efficiency versus Readability
//     Method Push in Fig. 6.18 uses the condition (Top >= MaxStack) to determine whether the stack is full.  It would be more readable, but less efficient, to use the method Stack::IsFull to test whether a stack is full.  You must use the method Stack::IsFull for this purpose in any client program that manipulates the stack because the stack's internal representation is hidden from a client program.  However, it is perfectly reasonable for another stack method to directly manipulate private data members of a stack.
//------------------------------------------
//
//Exercises for Section 6.4
//Self-check
//1. Declare a stack of 50 student records where each record
//   consists of a student's name (string of 20 characters), an
//   exam score, and a letter grade.  Can you use the methods in
//   our Stack class to manipulate this stack?
//
//Programming
//1. Write a method SizeOfStack that returns the number of
//   elements currently on the stack.  
//
//
//6.5  Additional Stack Applications
//This section discusses additional applications of stacks which relate to their use in computer science.  The first application is a continuation of the expression evaluation case study and shows how to use a stack to convert an expression from infix notation to postfix notation.  Next, we discuss how the stack is used to implement recursion in a block structured language like Pascal.  Finally, we discuss how to use a stack to convert a recursive procedure to an iterative procedure.
//
//Converting from Infix to Postfix
//Since programmers normally write expressions in infix notation, a compiler must convert an infix expression into postfix notation before it can apply the technique of expression evaluation discussed in section 6.3.  To complete our discussion of expression evaluation, we will describe a method of doing this that makes extensive use of an operator stack as its central data structure.
//
//Case Study:  Converting from Infix to Postfix   
//Problem
//To complete the design of an expression evaluator, we need a set of procedures that convert infix expressions to postfix.  For simplicity, we will assume that each operand is a single letter and that the symbol @ appears at the end of the infix expression.
//Design Overview
//Table 5.1 shows the infix and postfix form of four expressions.  For each expression pair, the operands are in the same sequence; however, the placement of the operators changes in going from infix to postfix.  For example, in converting A + B * C to its postfix form (A B C * +), we see that the three letters (operands) retain their relative ordering from the infix expression, but the order of the operators is reversed (* first, + second).  This means that we should insert the letters in the output expression (postfix) as soon as they are reached in the input expression (infix), but the operators should be placed on a stack before being inserted in the output expression.  The use of a stack enables the order of the operators + and * to be reversed as shown in the above example.  The data requirements and initial algorithm for function InfixToPost follow.  
//
//Data Requirements
//Problem Inputs
//The expression to convert (char Infix[])
//
//Problem Outputs
//
//The postfix expression (char Postfix[])
//
//A flag indicating success or failure (int ValidInfix)
//
//Local Variables
//
//The operator stack (Stack OpStack)
//The current token (char Token)
//
//
//Initial Algorithm for Procedure InfixToPost
//
//  1. Initialize Postfix to a blank string
//  2. Initialize the operator stack to an empty stack
//  3. repeat
//       4. Get the next token in Infix
//       5. if the next token is an operand then
//            6. Insert the operand in Postfix
//          else if the next token is an operator then
//            7.  Process the operator
//     until the sentinel operator is processed
//  8.	Infix is valid if the sentinel operator is the only operator on the stack
//
//     
//     The repeat-until loop executes until the sentinel operator has been processed.  The if statement (step 5) differentiates between operands and operators.  Step 6 inserts operands directly in Postfix;  step 7 executes when the next token is an operator.  Step 7 (performed by procedure DoOperator) either pushes the operator onto the stack immediately or inserts in Postfix earlier operators saved on the stack.  After the sentinel operator is processed, step 8 sets ValidInfix to True (1) or False (0) depending on the state of the stack.  ValidInfix should be True if the only operator on the stack is the sentinel.
//
//Coding for InfixToPost
//Fig. 6.19 shows procedure InfixToPost.  The statement
//     strcpy(Postfix, "");          //initialize Postfix
//initializes Postfix to the null string (string of length zero).  Function GetToken stores in Token the next non-blank character in 
//string Infix.  The statements
//      strncat(Postfix, Empty, 1);
//      strncat(Postfix, To, 1);
//
//uses the string concatenation operator (strncat) from library string.h to append a blank character followed by the character in Token to the end of string Postfix (for example, "A B" becomes is the string "A B *" if Token is '*').
//
//Figure 6.19  Procedure Infix to Post with Procedure GetToken
//_____________________________________________________________

Stack Stack::operator=(Stack& val)
{
	if (val.Items==0)
	{
		Items=0;
		MaxStack=0;
		return 0;
	}
	MaxStack=val.MaxStack;
	Items=new int [MaxStack];
	Items=val.Items;
	Top=val.Top;
	return *this;
}
Stack::Stack(Stack&ref)
{
	MaxStack=ref.MaxStack;
	Items=new int [MaxStack];
	Items=ref.Items;
	Top=ref.Top;
}


