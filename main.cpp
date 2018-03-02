/*
 * File:   main.cpp
 * Author: Stuart Hansen
 *
 * Date: February 2018
 *
 * Test main for the rational class
 */

#include <cstdlib>
#include "rational.h"
using namespace std;

int main(int argc, char** argv) {

    // Declare a few rational numbers
    rational half(1, 2);
    rational threeFourths(3, 4);
    rational r(4, 12);

    // Test the overloaded operators
    cout << half << endl;
    cout << (half + half) << endl;
    cout << r << endl;   // Note: should output 1/3
    cout << (r * threeFourths) << endl;

    // Do a bit more complex test
    rational r2 = half * half;
    rational r3 = r * threeFourths;
    rational r4 = r2 + r3;
    cout << r4 << endl;

    // Test whether the second constructor works
    double d = 0.875;
    rational r5 (d);
    cout << r5 << endl;

    // Test toDouble();
    cout << r << " is equal to " << r.toDouble() << endl;
    cout << r5 << " is equal to " << r5.toDouble() << endl;
    return 0;
}

