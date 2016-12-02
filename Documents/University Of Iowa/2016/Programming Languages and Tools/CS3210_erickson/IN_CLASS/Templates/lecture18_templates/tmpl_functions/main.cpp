//
//  main.cpp
//  C++ Template Functions
//
//  Created by Jason Alan Fries on 11/4/13.
//  Copyright (c) 2013 Jason Alan Fries. All rights reserved.
//

#include <iostream>
#include "formatter.h"

struct Point {
    double x, y;
    friend std::ostream & operator<<(std::ostream & os, const Point & p) {
        
        os << "(" << p.x << "," << p.y << ")";
        return os;
    }
};

void print( double v );
void print( std::string s );

template <typename T>
void print( T item );

int main(int argc, const char * argv[])
{
    using namespace std;
    
    //
    // I. Template Functions
    //
    print_header("I. Template Classes");
    
    // C++ is a strongly typed language. This means that when we've
    // created functions thus far in this semester, we've had to
    // create sepearate instances for functions that take different
    // typed parameters. This approach relys on polymorphism to pick
    // the right function implementation.
    
    // Consider the differentce between a fucntion that prints a number
    
    // ----------------------------------------------------------------
    // EXAMPLE 1: Print a Number
    // ----------------------------------------------------------------
    
    print_section("EXAMPLE 1: Polymorphism  - Print a Number");
    
    double num = 10.0;
    print( num );
    
    // ----------------------------------------------------------------
    // EXAMPLE 2: Print a String
    // ----------------------------------------------------------------
    print_section("EXAMPLE 2: Polymorphism - Print a String");
    
    // versus one that prints a string.
    std::string msg("this is a string");
    print( msg );
    
    
    // Function polymorphism works fine in this case, but it is
    // not an ideal solution. The implementational details of print,
    // regardless of type, is the same so why must we copy the same
    // code block when only function prototype changes?
    
    // A solution to this replys on what's called C++ templates. Here
    // we create a parameterized function implementation where we
    // provide a type as part of the function call. This allows us to
    // create one implementation that accepts multiple parameter types.
    
    // ----------------------------------------------------------------
    // EXAMPLE 3: Template print
    // ----------------------------------------------------------------
    
    print_section("EXAMPLE 3: Template Invocation");
    
    // now we just provide they type as part of the function call and
    // both invocations use the same function implementation.
    
    print<std::string>(msg);
    print<double>(num);
   
    // This approach is is an example of the "generic programming" paradigm.
    
    int i = 121;
    print<double>(i);   // This works due to implicit typecasting
    
    // Now any object that implements the output operator
    // can be passed as an arugment.
   
    Point p = {7,13};
    print<Point>(p);
    
    return 0;
}


void print( double v ) {
    
     std::cout << "(type double parameter) " <<  v << std::endl;
}

void print( std::string s ) {
    
    std::cout << "(type std::string parameter) " <<  s << std::endl;
}

template <typename T>
void print( T item ) {
    std::cout << "(template T parameter) " <<  item << std::endl;
}
