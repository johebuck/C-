#include <iostream>
#include <ostream>
#include "Overload.h"

using namespace std;

//sets the numerator and denominator equal to 1
rational::rational(){

    numerator=1;
    denominator=1;

}


//sets the numerator and denominator equal to num and denom (useful if i asked the user for input but decided to hardcode since it wasn't specified
//in the instructions if we had to ask the user for input).
rational::rational(int num, int denom){

    numerator=num;
    denominator=denom;

}

//sets the numerator and denominator equal to rhs.numerator and rhs.denominator
void rational::equals(rational rhs){

    numerator=rhs.numerator;
    denominator=rhs.denominator;

}

//adds two fractions together by multiplying the denominators with the numerators and adding them together while multiplying the denominators
//I did this because it will work on fractions who don't share the same denominator
rational rational::plus(rational rhs){

    rational return_val;
    return_val.numerator=((numerator*rhs.denominator)+(rhs.numerator*denominator));
    return_val.denominator=(rhs.denominator*denominator);
    return return_val;

}

//subtracts two fractions together by multiplying the denominators with the numerators and subtracting them together while multiplying the denominators
//I did this because it will work on fractions who don't share the same denominator
rational rational::minus(rational rhs){

    rational return_val;
    return_val.numerator=((numerator*rhs.denominator)-(rhs.numerator*denominator));
    return_val.denominator=(rhs.denominator*denominator);
    return return_val;

}

//multiplies fractions by multiplying straight across
rational rational::multiply(rational rhs){

    rational return_val;
    return_val.numerator=numerator*rhs.numerator;
    return_val.denominator=denominator*rhs.denominator;
    return return_val;

}

//divides fractions by cross multiplying
rational rational::divide(rational rhs){

    rational return_val;
    return_val.numerator=numerator*rhs.denominator;
    return_val.denominator=denominator*rhs.numerator;
    return return_val;

}


//prints the fraction
void rational::print(){

    cout<<numerator<<"/"<<denominator<<endl;

}

//overloads the '=' symbol
void rational::operator=(rational rhs){

    numerator=rhs.numerator;
    denominator=rhs.denominator;

}

//overloads the '+' symbol to add fractions
rational rational::operator+(rational rhs){

    rational return_val;
    return_val.numerator=((numerator*rhs.denominator)+(rhs.numerator*denominator));
    return_val.denominator=(rhs.denominator*denominator);
    return return_val;

}

//overloads the '-' symbol the subtract fractions
rational rational::operator-(rational rhs){

    rational return_val;
    return_val.numerator=((numerator*rhs.denominator)-(rhs.numerator*denominator));
    return_val.denominator=(rhs.denominator*denominator);
    return return_val;

}

//overloads the '*' symbol to multiply fractions
rational rational::operator*(rational rhs){

    rational return_val;
    return_val.numerator=numerator*rhs.numerator;
    return_val.denominator=denominator*rhs.denominator;
    return return_val;

}

//overloads the '/' symbol to divide fractions
rational rational::operator/(rational rhs){

    rational return_val;
    return_val.numerator=numerator*rhs.denominator;
    return_val.denominator=denominator*rhs.numerator;
    return return_val;

}

//overloads double
 rational::operator double () {

    //couldn't figure out how to convert without multiplying by multiples of 100 to get decimals

}

//overloads float
rational::operator float (){

    //couldn't figure out how to convert without multiplying by multiples of 100 to get decimals

}

//overloads int
rational::operator int (){

    //couldn't figure out how to convert without dividing by multiples of 100 to get decimals

}

//finds the greatest common divisor and divides the numerator and denominator with it tor educe the fractions
void reduce(){

    int x; int y;

    while(y!=0){

        int temp=y;
        y=x%y;
        x=temp;

    }

    //x is the greatest common factor, now divide the numerator and denominator by x
    //return_val=return_val/x; doesn't work?

}


ostream &operator<<(ostream &stream, rational rhs){

    return stream<<rhs.numerator<<'/'<<rhs.denominator;

}
