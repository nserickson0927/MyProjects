//
//  main.cpp
//  C++ Template Classes
//
//  Created by Jason Alan Fries on 11/4/13.
//  Copyright (c) 2013 Jason Alan Fries. All rights reserved.
//

#include <iostream>
#include "stack.h"
#include "pair.h"
#include "treasure.h"
#include "formatter.h"

int main(int argc, const char * argv[])
{
    using namespace std;
    
    print_header( "C++ Templates" );
    
    //
    // I. Template Classes
    //
    print_section("I. Template Classes");
    
    // ----------------------------------------------------------------
    // EXAMPLE 1: Definining a template container class
    // ----------------------------------------------------------------
    
    print_example("EXAMPLE 1: Definining a template container class");
    
    // You often ecounter the need to create a container object consisting
    // of various data types. For instance, it would be conveinant if your
    // linked list implementation from homework 4 could support classes beyond
    // the Book object. One solution to this is to use template classses.
    
    // Strictly speaking, templates are *not* class and member function
    // definitions/implementations. Templates provide parameratized types
    // and need to be instantiated by providing a type argument
    
    Stack<int> stack = Stack<int>(5);
    
    // add ints to stack
    for(int i=0;i<5;i++)
    {
        stack.push(i);
    }
    
    // ... and remove them
    while( !stack.empty() )
    {
        cout << stack.pop() << endl;
    }
    
    cout << stack << endl;
 
    
    // ----------------------------------------------------------------
    // II. Template Paramterizations
    // ----------------------------------------------------------------
    print_section( "II. Template Paramterizations" );
    
    
    // ----------------------------------------------------------------
    // Example 2: Template Paramterizations : Mixed Types
    // ----------------------------------------------------------------
    
    print_example("EXAMPLE 1: Mixed Types");
    
    // Templates can accept multiple type arguments of different types
    
    Pair<int, double> pair = Pair<int, double>(2,103.45);
    cout << pair << endl << endl;
    
    
    // ----------------------------------------------------------------
    // Example 3: Template Paramterizations : Non-type Arguments
    // ----------------------------------------------------------------
    
    print_example("EXAMPLE 2: Non-type Arguments");
    
    // type and non-type arguments
    
    SizedStack<Treasure,5> chest = SizedStack<Treasure,5>();
    for(int i=0;i<5;i++)
    {
        chest.push(Treasure());
    }
   
    while( !stack.empty() )
    {
        cout << chest.pop() << endl;
    }
    
    // recursive template use to create a cumbersome 2D structures
    SizedStack< SizedStack<int,5>, 10> twodee;
    
    // a more realistic example would be to define an array class, i.e.,
    // Array<typename T,int n>
    // and init using
    // Array< Array<int,5>, 10> twodee;
    
    
    // ----------------------------------------------------------------
    // III. Template Pitfalls
    // ----------------------------------------------------------------
    
    print_section("III. Template Pifalls");
    
    
    // ----------------------------------------------------------------
    // Example 3: Valid types
    // ----------------------------------------------------------------
    print_example("EXAMPLE 1: Valid types");
    
    // You might be tempted to do something like this
    // Stack<int[2]> pts = Stack<int[2]>(10);
    
    // however, this doesn't work. C++ uses your template code to
    // generate temporary source code, which it then compiles. This
    // temporary code consists of your template code "filled in" with
    // the type(s) your provided as paramters.
    
    // Providing a static array as a "type" would result in source code
    // that looks like this:
    // T * m_data;
    // becomes
    // int[2] * m_data;
    // which is clearly incorrect.
    
    // you have to be careful with pointers too
    Stack<int *> ptrs = Stack<int *>(10);
    
    // remember, this doesn't actually allocate any memory for ints -- just pointers
    
    // that means something like this would work
    int g = 113;
    ptrs.push(&g);
    
    if( !ptrs.empty() )
    {
        int * g_ptr = ptrs.pop();
        cout << *g_ptr << endl;
        *g_ptr = 200;
    }
    cout << g << endl;
    
    // but not this
    // ptrs.push(10);
    
    // There are disadvantages to assuming any type can be provided via a template argument
    
    // if we didn't implement the << operator for Treasure, this would fail to compile
    Pair<int, Treasure> tpair = Pair<int, Treasure>(2,Treasure());
    cout << tpair << endl << endl;
    
    return 0;
}

