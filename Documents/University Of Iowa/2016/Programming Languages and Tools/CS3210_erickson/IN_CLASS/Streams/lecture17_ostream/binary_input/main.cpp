//
//  main.cpp
//  image
//
//  Created by Jason Alan Fries on 11/14/13.
//  Copyright (c) 2013 Jason Alan Fries. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "ppm.h"

int main(int argc, const char * argv[])
{
    
    //
    // II. Image Binary Loading
    //
    char * filename = (char *)"data/ice_cream.pbm";
    
    PPM foo = PPM( filename );
    
    foo.write( (char *)"data/copy.pbm" );
    
    return 0;
}
