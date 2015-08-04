// Programmer: Austin Schoppe
// Project Number: 5
// Project Desc: Postfix notation
// Course: Data Structures COSC 2415
// Date: 2 APR 2012


#include <iostream>
#include <string> 

using namespace std;

#include "Assignment5.h"

//function prototypes
StackElement evaluate(Stack &s1, string expression, int length);
  /*------------------------------------------------------------------------
    Evaluates a postfix expression in its entirety.
    Precondition: A stack has been created, a string has been
                  entered and the length has been determined.
    Postcondition: The value of the expression is returned. Stack
                   has also been modified accordingly
   -----------------------------------------------------------------------*/
StackElement evaluateOperator(Stack &s1, int value);
  /*------------------------------------------------------------------------
    Evaluates an operator. Only called from the evaluate function.
    Precondition: An operator has been discovered in the postfix 
                  expression and is passed. Stack will be passed by
                  reference.
    Postcondition: Two operands from the stack have been popped and the
                   operator has been applied accordingly. The result of the
                   operation has been returned.
   -----------------------------------------------------------------------*/
void print(Stack st)
{ st.display(cout); }
//end of function prototypes

int main()
{
   bool menuChoice = false;
   Stack postfix;
   string entry;
   while (menuChoice == false)
   {
         cout << "Enter postfix expression: ";
         getline(cin, entry);
         int stringLength = entry.length();
         cout << "The result is: ";
         cout << evaluate(postfix, entry, stringLength) << endl;
         cout << "Enter 0 to enter another expression, enter 1 to quit: ";
         cin >> menuChoice;
         cin.ignore();
   }
   system("pause");
}

StackElement evaluate(Stack &s1, string expression, int length)
{
   char token;
   int value;
   for (int position = 0; position < length; position++)     // As long as the expression is, evaluate every character
   {
       token = expression[position];
       value = token;
       if (value >= 48 && value <= 57)                       // if the position is on a number...
          s1.push(value - 48);
       else if (value >= 42 && value <= 47)                  // if it is an operator then call evaluateOperator
          s1.push(evaluateOperator(s1, value));
   }
   return s1.top();                                          // Finished. Return the value of the expression.
}

StackElement evaluateOperator(Stack &s1, int value)
{
   StackElement result;          // Since we ran into an operator
   StackElement y = s1.top();    // then pop the first two of the stack
   s1.pop();
   StackElement x = s1.top();
   s1.pop();
   switch(value)                  // If operator is ____ then ...
   {
     case 42: result = x * y;     //    * Multiply
            break;
     case 43: result = x + y;     //    + Add
            break;
     case 45: result = x - y;     //    - Subtract
            break;
     case 47: result = x / y;     //    / Divide
            break;
     default: cout << "Operator input error" << endl;
   }
   return result;
}




