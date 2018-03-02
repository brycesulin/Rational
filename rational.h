
#ifndef RATIONAL_RATIONAL_H
#define RATIONAL_RATIONAL_H

/*
 * File:   rational.h
 * This file contains the declaration for a class representing
 * rational numbers
 *
 * Author: Stuart Hansen
 *
 * Date: February 2018
 */

#include <iostream>
using namespace std;

class rational {
public:
    // Three operators for addition, multiplication and printing
    rational operator + (rational & frac2);
    rational operator * (rational & frac2);
    friend ostream  & operator << (ostream & out, const rational & frac);

    // Construct a rational number with the given numerator and denominator
    // Make sure to reduce it.
    rational(int numer=0, int denom=1);

    // Creates a fraction equal to d
    // Keep multiplying d by 10 until the decimal part is gone
    // Put it over the appropriate denominator, and reduce.
    rational(double d);

    // a function to convert our fraction to a double
    double toDouble();


private:
    int numerator;     // the numerator of the fraction
    int denominator;   // the denominator of the fraction

    // a function to reduce the fraction
    // This is private because it is called from other methods and operators.
    void reduce();
};

#endif //RATIONAL_RATIONAL_H