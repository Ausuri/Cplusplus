/*-- DList.cpp-----------------------------------------------------------
 
   This file implements List member functions.
-------------------------------------------------------------------------*/
#include <iostream>     // Provides cout and cin
#include <cstdlib>      // Provides EXIT_SUCCESS
#include <ctime>        // For srand   

using namespace std;

#include "Assignment3.h"

//--- Definition of class constructor
List::List(int maxSize)
: mySize(0), myCapacity(maxSize)
{
   myArray = new ElementType[maxSize];  // program will abort if
                                           // allocation fails
}

//--- Definition of class destructor
List::~List()
{
   delete [] myArray;
}

//--- Definition of copy constructor
List::List(const List & origList)
: mySize(origList.mySize), myCapacity(origList.myCapacity)
{
  //--- Get new array for copy
   myArray = new ElementType[myCapacity];  // program will abort if  
                                           // allocation fails

      //--- Copy origList's elements into this new array
      for(int i = 0; i < mySize; i++)
         myArray[i] = origList.myArray[i];

}

//--- Definition of assignment operator
const List & List::operator=(const List & rightHandSide)
{
   if (this != &rightHandSide)  // check that not self-assignment
   {
      //-- Allocate a new array if necessary
      if (myCapacity != rightHandSide.myCapacity) 
      {
         delete [] myArray;
         myCapacity = rightHandSide.myCapacity;
         myArray = new ElementType[myCapacity];  // program will abort if
                                                 // allocation fails  

      }
      //--- Copy rightHandSide's list elements into this new array
      mySize = rightHandSide.mySize;
      for(int i = 0; i < mySize; i++)
         myArray[i] = rightHandSide.myArray[i];
   }
   return *this;
}

//--- Definition of empty()
bool List::empty() const
{
   return mySize == 0;
}

//--- Definition of display()
void List::display(ostream & out) const
{
   for (int i = 0; i < mySize; i++)
     out << myArray[i] << "  ";
}

//--- Definition of output operator
ostream & operator<< (ostream & out, const List & aList)
{
   aList.display(out);
   return out;
}

//--- Definition of insert()
void List::insert(ElementType item, int pos)
{
   if( mySize == myCapacity )       // if array is full...
       resize(myCapacity * 2);      // double the capacity

   // First shift array elements right to make room for item

   for(int i = mySize; i > pos; i--)
      myArray[i] = myArray[i - 1];

   // Now insert item at position pos and increase list size  
   myArray[pos] = item;
   mySize++;
}

//--- Definition of insertMultiple
void List::insertMultiple(int num)
{
   if (mySize == myCapacity)        // if array is full...
       resize(myCapacity * 2);      // double the capacity
      
   for (int x = 0; x < num; x++)
       {
            myArray[mySize] = rand()%999;
            mySize++;
       }
}

//--- Definition of erase()
void List::erase(int pos)
{
   assert( !empty() ); 
   assert( pos >= 0 && pos < mySize ); // is delete position legal?

   // Shift array elements left to close the gap
   for(ElementType i = pos; i < mySize; i++)
       myArray[i] = myArray[i + 1];

   // Decrease list size
    mySize--;
}


//--- Definition of resize()
void List::resize(int newCapacity)
{
     if (newCapacity < mySize)                                 //if the new capacity is less than the current size
        newCapacity = mySize;                                  //  resize the capacity to match the current size.
     if (newCapacity == myCapacity)                            //if the new capicity is the current size
        return;                                                //  return function.
     ElementType *newArray = new ElementType[newCapacity];     //Dynamically allocate new array of element type.
     for(int index = 0; index < mySize; index ++)              //Copy elements of old array into the new array.
     {
             newArray[index] = myArray[index];
     }
     delete [] myArray;                                        //Free the memory from the old array
     myArray = newArray;                                       //Point to new array.
     myCapacity = newCapacity;                                 //Update capacity.
}
