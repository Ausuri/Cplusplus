// Programmer: Austin Schoppe
// Project Number: 8
// Project Desc: Heaps
// Course: Data Structures COSC 2415
// Date: 11 MAY 2012


#include <cstdlib>
#include <iostream>

#ifndef ASSIGNMENT8
#define ASSIGNMENT8

class Heap
{
 public:
 void percolateDown(int r, int &n);
 void heapify(int size);
 int myArray[];
};



inline void Heap::percolateDown(int r, int &n)
{
 int temp;
 int c = 2 * r;
 while (c <= n)
 {
   if ( (c < n) && (myArray[c] < myArray[c + 1]))
     c++;
   if ( myArray[r] < myArray[c] )
   {    
     temp = myArray[r];
     myArray[r] = myArray[c];
     myArray[c] = temp;
     r = c;
     c = 2 * c;
   }
   else
     break;
 }
}

inline void Heap::heapify(int size)
{
 for (int r = size/2; r > 0; r--)
     percolateDown(r, size);
} 
#endif
