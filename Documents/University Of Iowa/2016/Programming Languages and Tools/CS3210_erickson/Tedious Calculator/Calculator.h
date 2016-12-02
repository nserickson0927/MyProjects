//
// Created by Nicholas Erickson on 11/10/16.
//

#ifndef TEDIOUS_CALCULATOR_CALCULATOR_H
#define TEDIOUS_CALCULATOR_CALCULATOR_H

#include <iostream>

class div_by_zero: public std::exception {
protected: std::string m_msg;
public:
    div_by_zero();
    div_by_zero(std::string msg);
    virtual ~div_by_zero() throw();
    virtual const char * what()const throw();
    virtual const std::string message() throw();
};

#define ARR_SIZE 2

class Calculate {
public:
    double myarray[ARR_SIZE];
    Calculate(double dblArr[]);
    ~Calculate();

    Calculate operator*(const Calculate & c) const;
    Calculate operator/(const Calculate & c) const;
    Calculate operator+(const Calculate & c) const;
    //Calculate operator-(const Calculate & c) const;

    //Calculate gcd();
    //Calculate factorial();
    Calculate square();
};
#endif //TEDIOUS_CALCULATOR_CALCULATOR_H
