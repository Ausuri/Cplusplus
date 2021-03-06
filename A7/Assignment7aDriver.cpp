// Programmer: Austin Schoppe
// Project Number: 7a
// Project Desc: Hash Tables - Linear probing
// Course: Data Structures COSC 2415
// Date: 5 MAY 2012

//****************************************************************
//
//  HASH TABLE PROGRAM

//  The Table class uses linear probing 
//     and allows only insertions (no deletions).
//
//*****************************************************************


#include <iostream>
#include <iomanip>
#include <cassert>

using namespace std;

#include "Assignment7a.h"

void print_menu( );

int main( )
{
    //List test;     // A List to perform tests on
    char choice;   // Command entered by the user
    Table dataTable;
    RecordType rec;
    int key;
    bool found;
    int size;
    
    do
    {
        print_menu( );
        cout << "Enter choice: ";
        cin >> choice;
        cout << endl; 
        choice = toupper(choice);
        
        switch (choice)
        {
            case 'I': // insert
                      cout << "Enter key (int >= 0) for record: ";
                      cin >> rec.key;
                      cout << "Enter data (int) for record: ";
                      cin >> rec.data;
                      dataTable.insert( rec );
                      cout << "Record was inserted in table" << endl << endl;
                      break;
            case 'F': // find
                      cout << "Enter key (int >= 0) to search for: ";
                      cin >> key;
                      dataTable.find( key, found, rec );
                      if ( found )
                      {
                         cout << "Record was found." << endl;
                         cout << "   key            = " << setw(8) 
                              << rec.key << endl;
                         cout << "   data = " << setw(8) 
                              << rec.data << endl << endl;
                      }
                      else
                         cout << "Record with key " << key << " not found." 
                              << endl << endl;
                      break;
            case 'S': // size
                      size = dataTable.size( );
                      cout << "There are " << size << " records in the table." 
                           << endl;
                      cout << "There are " << (CAPACITY - size) 
                           << " empty slots left in the table." << endl << endl;
                      break;
            case 'Q': cout << "Test program ended." << endl;
                      break;
            case 'E': cout << "Insert key to delete" << endl;
                      cin >> key;
                      dataTable.erase(key);
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
    cout << " I   Insert a new record or update existing record" << endl;
    cout << " F   Find a record" << endl;
    cout << " S   Get the number of records" << endl;
    cout << " E   Erase a record" << endl;
    cout << " Q   Quit this test program" << endl << endl;
}
