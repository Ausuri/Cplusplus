// Programmer: Austin Schoppe
// Project Number: 4
// Project Desc: Linked Lists
// Course: Data Structures COSC 2415
// Date: 14 MAR 2012


#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;
#include "Assignment4.h"
//Function prototypes
void print_menu();
char get_user_command();
int get_number();



int main( )
{
    List test;     // A List to perform tests on
    char choice;   // Command entered by the user
    
    cout << "I have initialized an empty list of integers." << endl;

    do
    {
        print_menu( );
        cout << "Enter choice: ";
        cin >> choice; 
        choice = toupper(choice);
        ElementType value;
        int position;
        int result;
        switch (choice)
        {
            case 'F': // Find a number in the list and return its node position
                      cout << "\n Enter a value to find: ";
                      cin >> value;
                      result = test.find(value);
                      cout << "Value found at " << result;
                      break;
            case 'E': // Print the result from the empty( ) function
                      cout << "Empty? " << boolalpha << test.empty() << endl;
                      break;
            case 'P': // to print the list
                      cout << "Values in linked list: " << test << endl;
                      cout << "Value of length: " << test.getLength() << endl;
                      break;
            case 'I': //input an item and position, and insert item into the list
                      cout << "Input a value and position to insert into the list." << endl;
                      cout << "Value to input? ";
                      cin >> value;
                      cout << "\nPosition? ";
                      cin >> position;
                      test.insert(value, position);
                      break;
            case 'R': // input a position, and erase the item at that position
                      cout << "Input a position to erase." << endl;
                      cin >> position;
                      test.erase(position);
                      break;     
            case 'Q': cout << "Test program ended." << endl;
                      break;
            default:  cout << choice << " is invalid." << endl;
        }
    }
    while ((choice != 'Q'));
    cout << "Testing assignment operator" << endl;
    List copy;
    copy = test; 
    cout << "Copy contents are as follows: " << copy << endl;
    system("PAUSE");
    return 0;
}

void print_menu( )
{
    cout << endl; 
    cout << "The following choices are available: " << endl;
    
    cout << " F   Find a number in the list and return its node position" << endl;
    cout << " E   Print the result from the empty( ) function" << endl;
    cout << " P   Print a copy of the entire list" << endl;    
    cout << " I   Insert a new number with the insert(...) function" << endl;
    cout << " R   Remove a node with the erase( ) function" << endl;
    cout << " Q   Quit this test program. Test the assignment operator on exit." << endl;
}

char get_user_command( )
// Library facilities used: iostream
{
    char command;

    cout << "Enter choice: ";
    cin >> command; // Input of characters skips blanks and newline character

    return command;
}

int get_number( )
// Library facilities used: iostream
{
    int result;
    
    cout << "Please enter an integer number for the list: ";
    cin  >> result;
    cout << result << " has been read." << endl;
    return result;
}
