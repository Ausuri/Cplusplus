#include <iostream>	
#include <math.h>
#include <algorithm>
#include <cassert>
#ifndef ASSIGNMENT2_H
#define ASSIGNMENT2_H

using namespace std;

class Quadratic
{
 
 public:
 
 Quadratic();
 /*-----------------------------------------------------
 Preconditions: None, class constructor.
 Postcondition: The values of coefficients A, B, and C are initilized
 to default arguments if none have been passed on the creation of the instance.
 -------------------------------------------------------*/
 
 
 void setCoefficients(float a, float b, float c);
 /*-----------------------------------------------------
 Set the data members of the Quadratic object to specified values
 
 Preconditions: Coefficients A, B, and C are set to zero.
 Postcondition: Data members coefficientA, coefficientB, and coefficientC 
 are set to instructed values.
 -------------------------------------------------------*/


 void setValueX(float x);
  /*-----------------------------------------------------
 Set the data members of the Quadratic object to specified values
 
 Preconditions: The value of x is set to 0.
 Postcondition: Private member variable x is set to instructed value.
 -------------------------------------------------------*/
 
 
 float evaluateX() const;
 /*-----------------------------------------------------
 Preconditions: The values for coefficients A, B, C, and X have
 been initialized.
 Postcondition: The value of x is returned after calculation 
 through the quadratic formula
 -------------------------------------------------------*/
 
 
 int realRoot() const;
  /*-----------------------------------------------------
  Preconditions: The values for coefficients A, B, and C have
  been initialized either as set or default arguments.
  Postcondition: The number of real roots in the quadratic formula
  are returned from the function, either as 0, 1, 2, or infinity (3)
 -------------------------------------------------------*/

 
 float smallerRoot() const;
 /*-----------------------------------------------------
 Preconditions: No argument for the private function evaluateRoots
 has been initialized.
 Postcondition: The bool value has been passed to evaluateRoots
 and the results of the function are returned as the smaller root value
 if there are two.
 -------------------------------------------------------*/
 
 
 float largerRoot() const;
  /*-----------------------------------------------------
 Preconditions: No argument for the private function evaluateRoots
 has been initialized.
 Postcondition: The bool value has been passed to evaluateRoots
 and the results of the function are returned as the larger root value
 if there are two.
 -------------------------------------------------------*/
 
 
 friend ostream &operator<<(ostream &out, const Quadratic &q);                     
  /*-----------------------------------------------------
 Preconditions: The ostream out is open.
 Postcondition: The returned values of functions have been inserted
 to ostream out.
 -------------------------------------------------------*/
 
 
 /*----------------------ACCESSORS----------------------*/
 float getCoefficientA() const
 { return coefficientA; }
 
 float getCoefficientB() const
 { return coefficientB; }
 
 float getCoefficientC() const
 { return coefficientC; }
 
 float getX() const
 { return valueX; }
 /*-----------------END OF ACCESSORS--------------------*/
 
 
 private:
         
 float evaluateRoots(bool) const;
   /*-----------------------------------------------------
 Preconditions: Either function smallerRoot or largerRoot have been
 called and the desired bool argument has been passed as true (larger root)
 or false (smaller root)
 Postcondition: The root(s) have been evaluated and returned from the function.
 --------------------------------------------------------*/
 
 
 /*-----------------MEMBER VALUES------------------------*/
 float coefficientA;
 float coefficientB;
 float coefficientC;
 float valueX;
 /*--------------END OF MEMBER VALUES--------------------*/
 
};

#endif
