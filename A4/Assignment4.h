// List.h

#ifndef ASSIGNMENT4
#define ASSIGNMENT4

#include <iostream>
#include <cstdlib>
#include <string>

typedef string ElementType;

class List
{
private:
   class Node
   {
   public:
      ElementType data;
      Node * next;
      
      Node( )
      : data( ElementType( ) ), next( NULL )
      { }
              
      Node( ElementType initData )
      : data( initData ), next( NULL )
      { }
   }; // end of Node class
           
   typedef Node * NodePointer;
           
public:
   List( );
   /* Construct a List object

      Precondition: none.
      Postcondition: An empty List object has been constructed.
   */
              
   List( const List &source );
   /* Construct a copy of a List object.

      Precondition: None. 
      Postcondition: A copy of origList has been constructed.
   */
              
   ~List( );
   /* Destroys a List object.

     Precondition:  None.
     Postcondition: Any memory allocated to the List object has been freed.
   */
              
   const List & operator=( const List &rightSide );
   /* Assign a copy of a List object to the current object.

      Precondition: none 
      Postcondition: A copy of rightside has been assigned to this
         object. A constant reference to this list is returned.
              
   int List::length( ) const;
   /* Returns the number of items in the list

      Precondition: none 
      Postcondition: The return value is the number of items in the list.
   */

   bool empty( ) const;
   /* Check if this List is empty

      Precondition: none 
      Postcondition: The return value is true if this List object is empty;
         otherwise the return value is false.
   */
               
   void insert( ElementType dataVal, int index );
   /* Insert a value into this List at a given index

      Precondition:  there is room in the array (the current size is less than
         the capacity); and the index is valid (the first position is index 0, 
         the second position is index 1, etc. 
      Postcondition: dataval has been inserted into the list at the position
         determined by index (provided there is room and index is a legal
         position).
   */         

   void erase( int index );
   /* Remove the value from this List at a given index.

      Precondition:  The list is not empty and index is valid 
         (index greater than or equal to 0 and less than the size.
      Postcondition: the element at position index has been
         removed (provided index is a legal position).
   */
         
   void display( ostream &out ) const;
   /* Display the contents of this List

      Precondition:  ostream out is open
      Postcondition: the items in this List have been output to stream out
   */ 


   int find( ElementType value) const;
   /* Find the first occurrence of a value in this List

      Preconditions:  None
      Postconditions: The return value is the index of the first List item 
         that matches value. The first list item has index 0, the second has 
         index 1, etc. The return value is -1 if value is not found in the list. 
   */
   
   /*----------ACCESSORS----------A*/
   
   int getLength()
   {   return length;   }

              
private:
   NodePointer first;
   int length;
}; // end of List class
      
//------ Prototype of output operator
ostream & operator<< (ostream & out, const List & aList);

#endif          
