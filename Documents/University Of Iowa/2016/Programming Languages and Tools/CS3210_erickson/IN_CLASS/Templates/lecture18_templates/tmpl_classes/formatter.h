//
//  formatter.h
//  OperatorOverloading
//
//  Created by Jason Alan Fries on 9/30/14.
//  Copyright (c) 2014 University of Iowa. All rights reserved.
//

#ifndef FORMATTER_H
#define FORMATTER_H

void print_section(const char * s) {

    std::cout << std::endl;
    std::cout << s << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;
}

void print_example(const char * s) {
    
    std::cout << "=================================================" << std::endl;
    std::cout  << s << std::endl;
    std::cout << "=================================================" << std::endl;
}

void print_header(const char * s) {
    
    std::cout << "_________________________________________________" << std::endl << std::endl;
    std::cout  << s << std::endl;
    std::cout  << "_________________________________________________" << std::endl << std::endl;
}


#endif
