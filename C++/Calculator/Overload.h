#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

using namespace std;

class rational {
 private:
  int numerator, denominator;

 public:
  /**** Constructors ****/
  //sets the numerator and denominator equal to 1
  rational();

  //sets the numerator and denominator equal to num and denom (useful if i asked the user for input but decided to hardcode since it wasn't specified
  //in the instructions if we had to ask the user for input).
  rational(int num, int denom);

  //sets the numerator and denominator equal to rhs.numerator and rhs.denominator
  void equals(rational rhs);

  //adds two fractions together by multiplying the denominators with the numerators and adding them together while multiplying the denominators
  //I did this because it will work on fractions who don't share the same denominator
  rational plus(rational rhs);

  //subtracts two fractions together by multiplying the denominators with the numerators and subtracting them together while multiplying the denominators
  //I did this because it will work on fractions who don't share the same denominator
  rational minus(rational rhs);

  //multiplies fractions by multiplying straight across
  rational multiply(rational rhs);

  //divides fractions by cross multiplying
  rational divide(rational rhs);

  //prints the raction
  void print();



  /**** Utilities ****/

  //finds the greatest common divisor and divides the numerator and denominator with it tor educe the fractions
  void reduce();


  /**** Overloaded Operators ****/

  //overloads the '=' symbol
  void operator=(rational rhs);

  //overloads the '+' symbol to add fractions
  rational operator+(rational rhs);

  //overloads the '-' symbol the subtract fractions
  rational operator-(rational rhs);

  //overloads the '*' symbol to multiply fractions
  rational operator*(rational rhs);

  //overloads the '/' symbol to divide fractions
  rational operator/(rational rhs);




  // Friend functions
  //I figured out how to set them up (to give them an empty shell) but couldn't figure out what to put in the body for them
  friend ostream& operator<<(ostream &stream, rational rhs);

  /**** Overloaded Typecast ****/

  //overloads into an int
  operator int();

  //overloads into a float
  operator float();

  //overloads into a double
  operator double();
};

#endif
