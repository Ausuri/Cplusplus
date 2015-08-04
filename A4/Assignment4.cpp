
#include <iostream>
#include <cassert>
#include <new>
using namespace std;

#include "Assignment4.h"

// Definition of constructor
List::List()
{
 first = NULL;
 length = 0;
}

List::List(const List &source)
{  
 if (!source.empty())
 {
    first = source.first;
    NodePointer lastPtr, origPtr;
    lastPtr = first;
    origPtr = source.first->next;
    while (origPtr != 0)
    {
          lastPtr->next = new Node(origPtr->data);
          lastPtr = lastPtr->next;
          origPtr = origPtr->next;
    }
 }
}
List::~List()
{
 NodePointer currPtr = first;
 NodePointer nextPtr;
 while (currPtr != 0)
 {
    nextPtr = currPtr->next;
    delete currPtr;
    currPtr = nextPtr;
 }
}

const List & List::operator=(const List &rightSide)
{
 if (this != &rightSide)
 {
    this->~List();
    if (rightSide.empty())
        first = 0;
    else
    {
        first = new Node(rightSide.first->data);
        NodePointer lastPtr, rhsPtr;
        rhsPtr = rightSide.first->next;
        lastPtr = first;
        while(rhsPtr != 0)
        {
            lastPtr->next = new Node(rhsPtr->data);
            lastPtr = lastPtr->next;
            rhsPtr = rhsPtr->next;
        }
    }
  }
  return *this;
}

bool List::empty() const
{
 return (length == 0);
}

void List::insert(ElementType dataVal, int index)
{
 assert(index >= 0 && index <= length);                
 NodePointer newptr = new(nothrow) Node(dataVal);
 NodePointer predptr = first;
 if(predptr == 0)
 {
     newptr->next = first;
     first = newptr;
 } 
 else
 {
     for (int x = 1; x <= index - 1; x++)
      {
        predptr = predptr->next;
      }
     newptr->next = predptr->next;
     predptr->next = newptr;
 }

 length++;
}
 
void List::erase(int index)
{
 assert(!empty());                        //The list is not empty and index is valid 
 assert(index >= 0 && index < length);    //(index greater than or equal to 0 and less than the size.
 NodePointer predptr = first;
 NodePointer ptr = NULL;
 if (predptr != 0)
 {
     for (int x = 1; x <= index - 1; x++)
     {
         predptr = predptr->next;
     }
     ptr = predptr->next;
     predptr->next = ptr->next;
 }
 else if (predptr == 0)
 {
     ptr = first;
     first = ptr->next;
 }
 delete ptr;
 length--;
}

void List::display(ostream &out) const
{
 NodePointer ptr;
 for (ptr = first; ptr != 0; ptr = ptr->next)
     out << ptr->data << "  ";
}

int List::find(ElementType value) const
{
 NodePointer current = first;
 int index = 0;
 while (current != 0)
 {
    if (value == current->data)
       return index;
    current = current->next;
    index++;
 }
 return -1;
}

ostream & operator << (ostream & out, const List & aList)
{
   aList.display(out);
   return out;
}

