// Author:                      Austin Schoppe
// Assignment Number:			Assignment #3
// Program status:              Complete
// File Name:					Assignment3Driver.cpp
// Course/Section:				COSC 2415 - Comer - 16 week - Distance Learning

#include <cctype>       // Provides toupper
#include <iostream>     // Provides cout and cin
#include <cstdlib>      // Provides EXIT_SUCCESS
#include <ctime>        // For srand

using namespace std;
#include "Assignment3.h"  

// PROTOTYPES:
void print_menu( );
// Postcondition: A menu of choices has been printed.

int get_number( );
// Postcondition: The user has been prompted to enter an integer number. The
// number has been read, echoed to the screen, and returned by the function.


int main( )
{
    srand ( time(0) );            // initialize random seed
    List test;                    // a List to perform tests on
    char choice;                  // command entered by the user
    int intChoice = 0;            // input to pass to functions
    int position = 0;             // input to pass to functions regarding array element position
    
    cout << "I have initialized an empty list of integers." << endl;

    do
    {
        print_menu( );
        cout << "Enter choice: ";
        cin >> choice; 
        choice = toupper(choice);
        switch (choice)
        {
            case 'A': // add code to input integer n and add n integers to end of list
                      intChoice = get_number();
                      test.insertMultiple(intChoice);
                      break;
            
            case 'C': // add code to change the capacity of the list
                      intChoice = get_number();
                      test.resize(intChoice);
                      break;
                      
            case 'E': // add code to print result of empty( )
                      cout << "List empty?" << endl;
                      cout << boolalpha << test.empty() << endl;
                      break;
                      
            case 'P': // add code to print the list
                      cout << "List is as follows: " << endl;
                      cout << test << endl;
                      cout << "Size: " << test.getMySize() << endl;
                      cout << "Capacity: " << test.getMyCapacity() << endl;
                      break;
                      
            case 'I': // add code to input an item and position, and insert item into the list
                      cout << "Enter a value to be input into the list: " << endl;
                      cin >> intChoice;
                      cout << "Enter a position in the array for input: " << endl;
                      cin >> position;
                      test.insert(intChoice, position);
                      break;
                      
            case 'R': // add code to input a position, and erase the item at that position
                      cout << "At which position would you like to erase a value?" << endl;
                      cin >> position;
                      test.erase(position);                  
                      break;    
                       
            case 'Q': cout << "Test program ended." << endl;
                      break;
           
            default:  cout << choice << " is invalid." << endl;
        }
    }
    while ((choice != 'Q'));
    system("PAUSE");
    return EXIT_SUCCESS;
}

void print_menu( )
{
    cout << endl; 
    cout << "The following choices are available: " << endl;
    cout << " A   Add a specific number of random values to the end of the list" << endl;
    cout << " C   Change the capacity of the list using resize( )" << endl;
    cout << " E   Print the result from the empty( ) function" << endl;
    cout << " P   Print a copy of the entire list" << endl;
    cout << " I   Insert a new number with the insert(...) function" << endl;
    cout << " R   Remove a number with the erase( ) function" << endl;
    cout << " Q   Quit this test program" << endl;
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
