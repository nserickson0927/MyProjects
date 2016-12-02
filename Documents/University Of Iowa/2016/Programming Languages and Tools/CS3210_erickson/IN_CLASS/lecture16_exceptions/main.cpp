//
//  Exception Handling
//  main.cpp
//
//  Created by Jason Alan Fries on 11/6/13.
//  Copyright (c) 2013 Jason Alan Fries. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include "formatter.h"
#include "alerts.h"

double hmean(double a, double b);
double hmean_abort(double a, double b);
bool hmean_ref(double a, double b, double & answer);
double hmean_except(double a, double b);

int alarmist();
bool bureaucrat1();
bool bureaucrat2();
bool bureaucrat3();



int main(int argc, const char * argv[])
{
    using namespace std;
    srand(time(NULL));
    
    //
    // I. Dealing with Unexpected Behavior
    //
    print_section("I. Dealing with Unexpected Behavior");
    
    // Let's consider the harmonic mean
    
    double mean = hmean(100, 90);
    cout << mean << endl;
    
    // This works fine in cases where a + b != 0, otherwise
    // we get division by 0. This can result in different behaviors
    // based on the compiler used.
    mean = hmean(100, -100);    // this returns crazy value (or crashes)
    cout << mean << endl;
    
    // What we really want to do is build in some guarantee that
    // our returned value is correct.
    
    // ----------------------------------------------------------------
    // EXAMPLE 1: Using std::abort()
    // ----------------------------------------------------------------
    
    print_header("EXAMPLE 1: Using std::abort()");
    
    // you might consider using the function std::abort(), which
    // halts the program given a error condition. However this
    // means the whole program halts given an error.
    mean = hmean(100, 90);
    cout << mean << endl;
    
    // hmean_abort(100, -100);  // this halts program
    
    // ----------------------------------------------------------------
    // EXAMPLE 2: Passing by reference
    // ----------------------------------------------------------------
    
    print_header("EXAMPLE 2: Passing by reference");
    
    // Using std::abort() effectively terminates our program. This may
    // be appropriate for fatal, show-stopping errors, but we might
    // want our program to be able to continue despite the error.
    
    if(hmean_ref(100,90,mean))
    {
        cout << mean << endl;
    }
    
    // let's test if our function returns false...
    if(hmean_ref(100,-100,mean))
    {
        cout << mean << endl;
    }
    
    // ----------------------------------------------------------------
    // EXAMPLE 3: Exceptions
    // ----------------------------------------------------------------
    
    print_header("EXAMPLE 3: Exceptions");
    
    // A third approach is what is called Exception handling, which should
    // be familar to student's who have done java or python programming
    try {
        mean = hmean_except(100,-100);
        cout << mean << endl;
        
    } catch (const std::string error) {
        cout << error << endl;
    }

  
    //
    // II. C++ Exception Handling
    //
    print_section("II. C++ Exception Handling");

    print_header("EXAMPLE 1: std::exception object");
    
    try {
        
        alarmist();
        
    } catch(Alert & error) {
        
        //cout << error.what() << endl;
        cout << error.message() << endl;
    }
    
    // ----------------------------------------------------------------
    // Hierarchy of exception classes
    // ----------------------------------------------------------------
    
    print_header("EXAMPLE 2: Hierarchy of exception classes");
    
    // The most derrived class should be first, with the base class last
    // in the set of catch blocks
    
    try {
        
        alarmist();
    
    } catch(RedAlert & error) {
        
        cout << "Red Catch Block" << endl;
        cout << error.what() << endl;
        cout<< error.message() << endl << endl;
        
    } catch(OrangeAlert & error) {
        
        cout << "Orange Catch Block" << endl;
        cout << error.what() << endl;
        cout<< error.message() << endl << endl;
        
    } catch(Alert & error) {
        
        cout << "Base Catch Block" << endl;
        cout << error.what() << endl;
        cout<< error.message() << endl << endl;
        
    }
    
    
    //
    // III. "Unwinding the Call Stack"
    //
    print_section("III. Unwinding the Call Stack");
    
    // ----------------------------------------------------------------
    // Uncaught exceptions
    // ----------------------------------------------------------------
    
    // if we use a method that throws an exception and we fail to
    // provide a try/catch block, we get a "uncaught exception of type" error
    
    // bureaucrat1();
    
    // ----------------------------------------------------------------
    // Stack return pointers
    // ----------------------------------------------------------------
    
    try {
        
        bureaucrat1();
        
    } catch (RedAlert & error) {
        
        cout << "Bureaucrat1 Catch Block" << endl;
        cout << error.what() << endl;
        cout<< error.message() << endl << endl;
    }
    
    
    // ----------------------------------------------------------------
    // There are several pre-defined exception classes that you may
    // find useful
    // ----------------------------------------------------------------
    
    // throw domain_error("x must be >= 0 for sqrt");
    // throw invalid_argument("X is not of the acceptable arg type");
    // throw length_error("not enough space for append()");
    // throw out_of_bounds("index error");
    
    return 0;
}

double hmean(double a, double b)
{
    return 2.0 * a * b /(a + b);
}

// the version aborts is a == =-b
double hmean_abort(double a, double b)
{
    if(a == -b)
    {
        std::cout << "Fatal Error" <<std::endl;
        std::abort();   // this will your program to halt
    }
    
    return 2.0 * a * b /(a + b);
        
}

// this version returns false if a == -b
bool hmean_ref(double a, double b, double & answer)
{
    if(a == -b)
    {
        std::cout << "Fatal Error" <<std::endl;
        return false;
    }
    
    answer =  2.0 * a * b /(a + b);
    return true;
}

// throw an exception if a == -b
double hmean_except(double a, double b)
{
    if(a == -b)
        throw std::string("hmean() ERROR : a == -b not allowed");
    
    return 2.0 * a * b /(a + b);
}

// just throw a random Alert object
int alarmist()
{
    int coin = rand() % 3 + 1;
    
    if ( coin == 1 ) {
    
        throw Alert("This is a plain alert");
        
    } else if ( coin == 2 ) {
     
        throw OrangeAlert();
    }
    
    throw RedAlert();
}

bool bureaucrat1()
{
    std::cout << "bureaucrat1 looks over your files..." << std::endl;
    
    if(bureaucrat2())
    {
        std::cout << "bureaucrat1 signs file!" << std::endl;
        return true;
    }
    return false;
}

bool bureaucrat2()
{
    std::cout << " bureaucrat2 looks over your files..." << std::endl;
    if(bureaucrat3())
    {
        std::cout << " bureaucrat2 signs file!" << std::endl;
        return true;
    }
    return false;
}

bool bureaucrat3()
{
    std::cout << "  bureaucrat3 looks over your files..." << std::endl;
    
    throw RedAlert();
    
    std::cout << "  bureaucrat3 signs file!" << std::endl;
    return true;
}