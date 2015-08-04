#include <iostream>	
#include <math.h>
#include <algorithm>
#include <cassert>
#include "Assignment2.h"

using namespace std;

//Function prototypes
Quadratic operator+(const Quadratic &quad1, const Quadratic &quad2);
Quadratic operator*(double r, const Quadratic &q);
//End of function prototypes

/*Class function definitions*/
Quadratic::Quadratic()
: coefficientA(0), coefficientB(0), coefficientC(0)
{
}

void Quadratic::setCoefficients(float a, float b, float c)
{
 coefficientA = a;
 coefficientB = b;
 coefficientC = c;
}

void Quadratic::setValueX(float x)
{
 valueX = x;
}

float Quadratic::evaluateX() const
{
 
 return ((coefficientA * (pow(valueX, 2))) + (coefficientB * valueX) + coefficientC);
}

int Quadratic::realRoot() const
{
 int roots = 0;
 float a = coefficientA;
 float b = coefficientB;
 float c = coefficientC;
 if (a == 0 && b == 0 && c == 0)
    roots = 3;
 else if (a == 0 && b == 0 && c != 0)
    roots = 0;
 else if (a == 0 && b != 0)
    roots = 1;
 else if (a != 0 && ( pow(b,2) < (4 * a * c)))
    roots = 0;
 else if (a != 0 && ( pow(b,2) == (4 * a * c)))
    roots = 1;
 else if (a != 0 && ( pow(b,2) > (4 * a * c)))
    roots = 2;
 
 return roots;
}

float Quadratic::evaluateRoots(bool minOrMax) const
{
 int roots = realRoot();
 float rootResult = 0;
 float result1;
 float result2;
 assert (roots > 0);
 {
    if (roots == 3)
       rootResult = 0;
    else if (roots == 2)
       {
        result1 = ((-coefficientB) - sqrt( pow(coefficientB,2) - (4 * coefficientA * coefficientC) ) ) / (2 * coefficientA);
        result2 = ((-coefficientB) + sqrt( pow(coefficientB,2) - (4 * coefficientA * coefficientC) ) ) / (2 * coefficientA);
        if (minOrMax == false)
           rootResult = min(result1, result2);
        if (minOrMax == true)
           rootResult = max(result1, result2);
       }
    else if (roots == 1)
       {
        if (coefficientA == 0 && coefficientB != 0)
           rootResult = -coefficientC / coefficientB;
        else if (pow(coefficientB, 2) > (4 * coefficientA * coefficientB))
           rootResult = -coefficientB / (2 * coefficientA);
       }
  }
  return rootResult;
}

float Quadratic::smallerRoot() const
{
 bool min = false;
 return evaluateRoots(min);
}

float Quadratic::largerRoot() const
{
 bool max = true;
 return evaluateRoots(max);
}
/*End of class function definitions*/

/*Non-member function definitons*/
ostream &operator<<(ostream & out, const Quadratic &q)                         //Used for testing purposes. I would delete this 
{                                                                              //  for a serious program but felt I should leave
 out << "Coefficient A: " << q.coefficientA << endl;                           //  it in to show how I tested the program, even though
 out << "Coefficient B: " << q.coefficientB << endl;                           //  I know the textbook discourages this method I feel like
 out << "Coefficient C: " << q.coefficientC << endl;                           //  it's less clutter than the method suggested.
 out << "Value X: " << q.valueX << endl;
 out << "Real roots: " << q.realRoot() << endl;
 out << "Evaluate X: " << q.evaluateX() << endl; 
 out << "Smaller root: " << q.smallerRoot() << endl;
 out << "Larger root: " << q.largerRoot() << endl;
 return out;
}

Quadratic operator+(const Quadratic &q1, const Quadratic &q2)
{
    Quadratic sum;
    sum.setCoefficients (q1.getCoefficientA() + q2.getCoefficientA(),
                         q1.getCoefficientB() + q2.getCoefficientB(),
                         q1.getCoefficientC() + q2.getCoefficientC());
    return sum;
}

Quadratic operator*(double r, const Quadratic &q)
{ 
    Quadratic product;
    product.setCoefficients (q.getCoefficientA() * r,
                             q.getCoefficientB() * r,
                             q.getCoefficientC() * r);
    return product;
}


/*End of non-member function definitions*/
