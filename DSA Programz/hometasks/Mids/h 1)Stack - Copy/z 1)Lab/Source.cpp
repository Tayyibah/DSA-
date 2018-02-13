#include <iostream>
#include "Stack.h"

void FillStack(Stack &S);
void DisplayStack(Stack &S);

//insert FillStack and DisplayStack here

void main()
//Program read sequence of characters and displays it in
//reverse order.
{
  Stack S(10);         //create empty stack

  FillStack(S);    //fill the stack

  DisplayStack(S); //display characters in reverse order

  //Display status of stack S.
  if (S.isEmpty())
    cout << "Stack is empty, operation succeeds.\n";
  else
   if (S.isFull())
     cout << "Stack is full, reversal failed.\n";
}

//
//Enter a string of one or more characters.
//Press return when done.
//This is a short string.
//.gnirts trohs a si sihT
//Stack is empty, operation succeeds.
//_______________________________________________________________
//
//
//Coding the Procedures
//     The posttest loop in function FillStack (see Fig. 6.7) reads each data character (at least one) into NextCh and pushes it onto the stack.  The if statement displays an error message in the event that the input string is too long.  This would happen if the program user entered more characters than the stack capacity before pressing return.  
//
//Figure 6.7  Function FillStack
//________________________________________________________________

void FillStack(Stack &S)
//Reads data characters and pushes them onto the stack.
//Pre : Stack S is defined.
//Post: Each data character read is pushed onto stack S.
{
  char NextCh;    //next character read

  cout << "Enter a string of one or more characters.\n";
  cout << "Press return when done.\n";

  cin.get(NextCh);              //read first character
  do
  {
    S.push(NextCh);    //push character on stack
    cin.get(NextCh);            //read next character
  }
  while((NextCh != '\n'));

  //Print error message is stack overflows.
}

void DisplayStack(Stack &S)
//Pops each stack character and displays it.
//Pre : Stack S is defined.
//Post: Each character is displayed and stack S is empty.
{
  int NextCh;    //next character to display
  //int Success;    //flag

  S.pop(NextCh);
  cout << NextCh;
  while(!S.isEmpty())
  {
    S.pop(NextCh);
    cout << NextCh;
  }
  cout<<"\n";
}
