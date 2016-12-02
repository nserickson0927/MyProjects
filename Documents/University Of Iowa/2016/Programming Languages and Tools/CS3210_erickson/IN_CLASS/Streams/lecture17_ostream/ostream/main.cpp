//
//  I/O Streams
//  main.cpp
//
//  Created by Jason Alan Fries on 11/12/13.
//  Copyright (c) 2013 Jason Alan Fries. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <sstream>
#include "formatter.h"

int main(int argc, const char * argv[])
{
    using namespace std;
    
    //
    // I. ostream revisited
    //
    print_section("I. Formatting Output");
    
    // As you begin work on your final project, you may find it helpful
    // to learn about some more advanced features available to you for
    // formatting output and reading/writing files.
    
    // ----------------------------------------------------------------
    // EXAMPLE 1. Output with cout
    // ----------------------------------------------------------------
    print_header("EXAMPLE 1. ostream revisited: output with cout");
    
    // You are very familiar with the insertion operator
    cout << "foo" << endl;
    
    // you can also print partiuclar spans of c-stirng output using write()
    string msg = "this is a longer output message";
    for(int i=0; i<=msg.size(); i++)
    {
        cout.write(msg.c_str(), i);
        cout.write("\n",1);
    }
    cout << endl;
    
    // ----------------------------------------------------------------
    // EXAMPLE 2. Printing single characters
    // ----------------------------------------------------------------
    print_header("EXAMPLE 2. Printing single characters");
    // we can print single characters using the put method
    cout.put('x');
    cout << endl;
    
    // and concatenate output
    cout.put('x').put('x').put('x').put('x').put('x').put('x');
    cout << endl << endl;
    
    // ----------------------------------------------------------------
    // EXAMPLE 3. Formatting output: width()
    // ----------------------------------------------------------------
    print_header("EXAMPLE 3. Formatting output with width()");
    
    // You might also find the need for evenly spaced columns when
    // printing output. That can be done using the width() member
    // function of cout
    
    cout << "----------------------------------------------------" << endl;
    
    for(int i=1;i<12;i++)
    {
        cout.width(2);
        for(int j=1;j<11;j++)
        {
            cout << j*i;
            cout.width(5);
        }
        cout << 11*i;
        cout << endl;
    }
    
    cout << "----------------------------------------------------" << endl << endl;
    
    
    // ----------------------------------------------------------------
    // EXAMPLE 4. Formatting output: setw()
    // ----------------------------------------------------------------
    print_header("EXAMPLE 4. Formatting output with setw()");
    // The library <iomanip> provides a shorthand version of the above task
    // where you can concatentate the the width separator using setw()
    
    cout << "----------------------------------------------------" << endl;
    
    for(int i=1;i<12;i++)
    {
        cout << setw(2);            // Q: What if we didn't use this?
        for(int j=1;j<11;j++)
        {
            cout << j*i << setw(5);
          
        }
        cout << 11*i << endl;
    }
    
    cout << "----------------------------------------------------" << endl << endl;
    
    
    // ----------------------------------------------------------------
    // EXAMPLE 5. C++ type format display
    // ----------------------------------------------------------------
    print_header("EXAMPLE 5. C++ type format display");
    // We can set floating point display precision
    
    float fp = 1.0 + 1.0/3.0,
          dollars = 1.80;
    
    cout << fp << endl;
    cout << "$" << dollars << endl << endl;
    
    // But the above defaults to ugly output, esp dollars which prints as "$1.8"
    // We can manually set the display preferences for floating pointer numbers as follows:
    
    cout.setf(ios_base::showpoint);     // "set flag", ios_base::showpoint is just a system constant
    cout << "ios_base::showpoint == " << ios_base::showpoint << endl;
    cout.precision(3);                  // this lasts until changed
    
    cout << fp << endl;
    cout << "$" << dollars << endl;
    
    
    // Display booleans
    cout << "---------------------------------------------------" << endl << endl;
    
    bool coffee = true,
         beans = false;
    cout << coffee << endl;
    cout << beans << endl;
    
    cout.setf(ios_base::boolalpha); // now boolean types with print out as true/false
    
    cout << coffee << endl;
    cout << beans << endl;

    // but integer types still print out as 0/1
    cout << 1 << endl;
    cout << 0 << endl;
    
    // there are lots of other specific ios_base flags
    // See text book pg 1087 for specific printing tasks.

    
    //
    // II. cin and exceptions
    //
    print_section("II. cin and exceptions");
    
    // You can set various exception modes for intput using cin.exceptions()
    // The default setting for is ios_base::goodbit -- i.e., no exceptions thrown
    // We can change the mode to throw exceptions for other fail states:
    
    // ios_base::badbit   -- stream is corrupted
    // ios_base::failbit  -- faied to read or write the expected characters
    
    cout << "---------------------------------------------------" << endl << endl;
    
    // this uses what's called the bitwise OR and its used to set more than 1 bit
    cin.exceptions(ios_base::failbit | ios_base::badbit);
    
    int input = 0, sum = 0;
    
    try{
        // read in integer input
        while(cin >> input)
        {
            sum += input;
        }
        
    }catch(ios_base::failure & bf){
        
        cout << "Exception Thrown: " << bf.what() << endl;
    }
    
    cout << "SUM == " << sum << endl;
    
    cout << "---------------------------------------------------" << endl << endl;
    
    
    //
    // III. sstream (string streams)
    //
    print_section("III. sstream (string streams)");
    
    // You might also at some point find it useful to convert numbers
    // or objects to a string representation that can be assigned to a variable.
    
    stringstream ss;
    ss << 100.345;
    string foo = ss.str();
    
    // we can print that string out now
    cout << foo << endl;
    
    // as well as modify it
    foo = foo + " sweeeet";
    cout << foo << endl;
    

    return 0;
}

