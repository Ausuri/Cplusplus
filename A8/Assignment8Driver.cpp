// Programmer: Austin Schoppe
// Project Number: 8
// Project Desc: Heaps
// Course: Data Structures COSC 2415
// Date: 11 MAY 2012


#include <cstdlib>
#include <iostream>

using namespace std;

#include "ASSIGNMENT8.h"

int main()
{
    char choice;
    cout << endl; 
    do
    {
          int size = 0;
          int pos = 1;
          cout << "Input the size of the array: " << endl;
          cin >> size;
          Heap h1;
          while (pos <= size)
                {
                     cout << "Input integer in position " << pos << " in the array:" << endl;
                     cin >> h1.myArray[pos];
                     pos++;
                }
          h1.heapify(size);
          pos = 1;
          cout << "Array is as follows: " << endl;
          while (pos <= size)
                {
                     
                     cout << h1.myArray[pos] << ", at position" << pos << endl;
                     pos++;
                }
          cout << endl;
          cout << "Enter Q to quit, otherwise enter any character to restart: ";
          cin >> choice;
    }  while (choice != 'Q');
    system("PAUSE");
    return 0;
}

