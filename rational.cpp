/**
 * File: rational.cpp
 * Author: Bryce Sulin
 *
 * This file contains the implementation of rational.h
 */
#include <iostream>
#include <cassert>
#include "rational.h"
using namespace std;

// Construct a rational number with the given numerator and denominator
// Make sure to reduce it.
rational::rational(int numer, int denom)
{
    numerator = numer;
    denominator = denom;
    reduce();
}

// Creates a fraction equal to d
// Keep multiplying d by 10 until the decimal part is gone
// Put it over the appropriate denominator, and reduce.
rational::rational(double d)
{
    int i = 1;
    while (d*i-static_cast<int>(d*i) != 0) {
        if (i > INT_MAX/10) {
            cout << "this frational number : " << d << " can not be transfer to rational number, it's too long, now set it 0." << endl;
            numerator = 0;
            denominator = 1;
            return ;
        }
        else {
            i *= 10;
        }
    }
    numerator = d * i;
    denominator = i;
    reduce();
}

// A function to convert our fraction to a double
double rational::toDouble() {
    return (double)numerator / (double)denominator;
}

// Recursive algorithm to compute the greatest common divisor of two integers.
int findGCD(int a, int b)
{
    if (b == 0)
        return a;
    else
        return findGCD(b,a % b);
}

// Find Least Common Multiplier
int findLCM(int m, int n)
{
    return ((m * n) / findGCD(m, n));
}

// A function to reduce the fraction
// This is private because it is called from other methods and operators.
void rational::reduce()
{
    int a1, a2, g;
    assert(denominator != 0);

    a1 = numerator;
    a2 = denominator;
    g = findGCD(a1,a2);
    a1 = a1 / g;
    a2 = a2 / g;
    if (a2 < 0)
    {
        a2 = -a2;
        a1 = -a1;
    }
    numerator = a1;
    denominator = a2;
}

rational rational::operator + (rational & frac2) {
    // Declare a temporary object to hold the result and set it
    // equal to the left operand
    rational result = *this;

    // Convert the rational numbers to a common denominator
    int lcm = findLCM(result.denominator, frac2.denominator);

    result.numerator *= lcm / result.denominator;
    result.denominator = lcm;

    // Perform the addition
    result.numerator += frac2.numerator * lcm / frac2.denominator;

    // Reduce the result to its lowest terms
    int gcd = findGCD(result.numerator, result.denominator);

    result.numerator /= gcd;
    result.denominator /= gcd;

    return result;
}

rational rational::operator * (rational & frac2) {
    // Declare a temporary object to hold the result and set it
    // equal to the left operand
    rational result = *this;

    // Multiply the left operand by the right operand
    result.numerator *= frac2.numerator;
    result.denominator *= frac2.denominator;

    // Reduce the result to its lowest terms
    int gcd = findGCD(result.numerator, result.denominator);

    result.numerator /= gcd;
    result.denominator /= gcd;

    return result;
}

//Outputs fraction
ostream & operator << (ostream& out, const rational & frac)
{
    out<<frac.numerator<<"/"<<frac.denominator;
    return out;
}