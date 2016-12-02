//
// Created by Nicholas Erickson on 11/10/16.
//

#include <iostream>
#include "Calculator.h"
#include <climits>
#include <stdexcept>

using namespace std;

div_by_zero::div_by_zero() : std::exception(), m_msg() {}
div_by_zero::div_by_zero(std::string msg) : std::exception(), m_msg(msg) {}
div_by_zero::~div_by_zero() throw()
{
    std::cout<<"Divide By Zero Exception"<<std::endl;
}

const char * div_by_zero::what()const throw()
{
    return static_cast<const char *>("Divide By Zero Exception");
}

const std::string div_by_zero::message() throw()
{
    return m_msg;
}

Calculate::~Calculate() {};

Calculate::Calculate(double dblArr[]) {
    for(int i=0; i<ARR_SIZE; i++) {
        if(myarray[i]<=0){
            string msg= string("The integer at ")+to_string(myarray[i])+string(" is negative at ")+to_string(i);
        }
        myarray[i] = dblArr[i];
    }
}

Calculate Calculate::operator*(const Calculate &c) const {
    using namespace std;
    double result[ARR_SIZE];
    for(int i=0; i<ARR_SIZE; i++){
        //c[i]=a[i]*b[i]
        if(myarray[i]>(INT_MAX/c.myarray[i])){
            string msg = string("Multiplication Overflow error at ")+to_string(i)+string(" for values ")+to_string(myarray[i])+string(" ")+to_string(c.myarray[i]);
            throw std::overflow_error(msg);
        }
        if(myarray[i]<(INT_MIN/c.myarray[i])){
            string msg= string("Multiplication Underflow error at ")+to_string(i)+string(" for values ")+to_string(myarray[i])+string(" ")+to_string(c.myarray[1]);
            throw  std::underflow_error(msg);
        }
        result[i]=myarray[i]*c.myarray[i];
    }
    return Calculate(result);
}

//Calculate Calculate::operator-(const Calculate &c) const {
//}

Calculate Calculate::operator+(const Calculate &c) const {
    using namespace std;
    double result[ARR_SIZE];
    for(int i=0; i<ARR_SIZE; i++){
        //c[i]=a[i]+b[i]
        if(myarray[i]>(INT_MAX-c.myarray[i])){
            string msg = string(" Addition Overflow error at ")+to_string(i)+" for values "+to_string(myarray[i])+string(" ")+to_string(c.myarray[i]);
            throw std::overflow_error(msg);
        }
        if(myarray[i]<(INT_MIN-c.myarray[i])){
            string msg= string("Addition Underflow error at ")+to_string(i)+string(" for values ")+to_string(myarray[i])+string(" ")+to_string(c.myarray[1]);
            throw  std::underflow_error(msg);
        }
        result[i]=myarray[i]+c.myarray[i];
    }
    return Calculate(result);
}

Calculate Calculate::operator/(const Calculate &c) const {
    using namespace std;
    double result[ARR_SIZE];
    for(int i=0;i<ARR_SIZE; i++) {
        //c[i]=a[i]/b[i]
        if(c.myarray[i]==0){
            string msg=string("Divide by zero error at ")+to_string(i)+string(" for values ")+to_string(myarray[i])+string(" ")+to_string(c.myarray[i]);
            throw div_by_zero(msg);
        }
        result[i]=myarray[i]/c.myarray[i];
    }
    return Calculate(result);
}

Calculate Calculate::square() {
    using namespace std;
    double result[ARR_SIZE];
}