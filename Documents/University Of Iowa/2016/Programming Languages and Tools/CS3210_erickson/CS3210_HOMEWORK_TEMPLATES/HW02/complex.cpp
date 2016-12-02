//  complex.cpp
//  Homework 02
//  Author: 

#include "complex.h"
#include <math.h>

// Constructors
Complex::Complex() : m_Real(0), m_Complex(0) {}

Complex::Complex (double a, double b) : m_Real(a), m_Complex(b) {}

// Destructor
Complex::~Complex() {}

// Magnitude Squared of this number
double Complex::magnitude2() const {
    // TODO: Calculate the magnitude squared
    
}

// Addition of complex numbers is defined as:
// (a + bi) + (c + di) = (a + c) + (b + d)i
Complex Complex::operator+(const Complex & c) const {
    //TODO: Addition of complex numbers
}

// Subtraction of complex numbers is defined as:
// (a + bi) - (c + di) = (a - c) + (b - d)i
Complex Complex::operator-(const Complex & c) const {
    //TODO: Subtraction of complex Numbers
}

// Multiplication of complex numbers is defined as:
// (a + bi)(c + di) = (ac - bd) + (bc - ad)i
Complex Complex::operator*(const Complex & c) const {
    //TODO: Multiplication of Complex numbers
}

// Division
Complex Complex::operator/(const Complex & c) const {
    //TODO: Division of Complex numbers
}

// friend function. Notice the lack of complex scope. Why?
std::ostream & operator << (std::ostream & out, const Complex & c)
{
    std::cout << "(" << c.m_Real << " + " << c.m_Complex << "i)";
    return out;
}
