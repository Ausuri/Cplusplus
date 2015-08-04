/*-- DList.h --------------------------------------------------------------
 
  This header file defines the data type List for processing lists.
  Basic operations are:
     Constructor
     Destructor
     Copy constructor
     Assignment operator
     empty:    Check if list is empty
     resize:   resize the list
     insert:   Insert an item
     erase:    Remove an item
     display:  Output the list
     << :      Output operator
-------------------------------------------------------------------------*/

#ifndef ASSIGNMENT3
#define ASSIGNMENT3

typedef int ElementType;
class List
{
 public:
 /******** Function Members ********/
   
   /***** Class constructor *****/
   List(int maxSize = 1024);
   /*----------------------------------------------------------------------
     Construct a List object.

     Precondition:  maxSize is a positive integer with default value 1024.
     Postcondition: An empty List object is constructed; myCapacity ==
         maxSize (default value 1024); myArray points to a dynamic
         array with myCapacity as its capacity; and mySize is 0.
   -----------------------------------------------------------------------*/

   /***** Class destructor *****/
   ~List();
   /*----------------------------------------------------------------------
     Destroys a List object.

     Precondition:  The life of a List object is over.
     Postcondition: The memory dynamically allocated by the constructor
         for the array pointed to by myArray has been returned to the heap.
   -----------------------------------------------------------------------*/

   /***** Copy constructor *****/
   List(const List & origList);
   /*----------------------------------------------------------------------
     Construct a copy of a List object.

     Precondition:  A copy of origList is needed; origList is a const
         reference parameter. 
     Postcondition: A copy of origList has been constructed.
   -----------------------------------------------------------------------*/

   /***** Assignment operator *****/
   const List & operator=(const List & rightHandSide);
   /*----------------------------------------------------------------------
     Assign a copy of a List object to the current object.

     Precondition: none 
     Postcondition: A copy of rightHandSide has been assigned to this
         object. A const reference to this list is returned.
   -----------------------------------------------------------------------*/

   /***** empty operation *****/
   bool empty() const;
   /*----------------------------------------------------------------------
     Check if a list is empty.
     
     Precondition: None
     Postcondition: true is returned if the list is empty, false if not.
   
   /***** resize operation *****/
    void resize(int newCapacity);
   /*----------------------------------------------------------------------
     Change the capacity of a list

     Precondition:  None.
     Postcondition: The list's current capacity is changed to newCapacity
         (but not less than the number of items already in the list).
   -----------------------------------------------------------------------*/
  
   /***** insert and erase *****/
   void insert(ElementType item, int pos);
   /*----------------------------------------------------------------------
      Insert a value into the list at a given position.
      
      Precondition: Item is the value to be inserted; array (mySize) is
                    evaluated as to whether it is full or not.
      Postcondition: If array is full then capacity is doubled; item has been
                     inserted into the list at the position determined by pos; 
                     array is increased by one element.                                                            
   -----------------------------------------------------------------------*/
   
   /***** Insert Multiple *****/
   void insertMultiple(int num);
   /*----------------------------------------------------------------------
      Add a specified number of random values to the end of the list.
      
      Precondition: Num is the number of items to be added; array (mySize) is
                    evaluated as to whether it is full or not.
      Postcondition: Array (mySize) is increased by num. Random values have been
                     inserted into the end of the list. If array is full the
                     capacity has been doubled using resize(newCapicity).
   -----------------------------------------------------------------------*/

   /***** erase *****/
   void erase(int pos);
   /*----------------------------------------------------------------------
     Remove a value fromt he list at a given position.
     
     Precondition: The list is not empty and the position satisfies 0 <= pos < mySize.
     Postcondition: Element at the position determined by pos has been removed
                    provided pos is a legal position. mySize is decreased by one.
   -----------------------------------------------------------------------*/

   /***** output *****/
   void display(ostream & out) const;
   /*----------------------------------------------------------------------
   Display a list.
   
   Precondition: The ostream out is open.
   Postcondition: The list represented by this List object has been inserted into out.
   -----------------------------------------------------------------------*/
   
   /***** Accessors *****/
   
   int getMyCapacity()
   {   return myCapacity;   }
   
   int getMySize()
   {   return mySize;  }                                                
   
   /***** End Accessors *****/
   
 private:
 /******** Data Members ********/
   int mySize;                // current size of list
   int myCapacity;            // capacity of array
   ElementType * myArray;     // pointer to dynamic array

}; //--- end of List class

//------ Prototype of output operator
ostream & operator<< (ostream & out, const List & aList);

#endif
