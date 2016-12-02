//  main.cpp
//  Homework 02
//  Author: 

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include "complex.h"
#include "lodepng.h"
#include "rgb.h"


// struct for storing command line argument values
struct Arguments {
    int width;
    int height;
    int color_depth;
    int max_itr;
    const char * filename;
    double zoom;
    double origin[2];
    Complex c;
};

// Function prototypes
int julia_recursive( Complex & z, const Complex & c, int itr, int max_itr, const double radius2=4 );
int julia( Complex & z, const Complex & c, const int max_itr=256, const double radius2=4 );
unsigned int parse_args(int argc, const char * argv[], Arguments & args);
void print_usage();

int main(int argc, const char * argv[]) {
    
    // parse command line arguments
    Arguments args;
    if ( !parse_args( argc, argv, args ) ) {
        print_usage();
        return 0;
    }
    
    // print out size of image, and other arguments
    // This is not in the requirements, but it may make debugging easier if you don't want to user a debugger
      
      
      
    // TODO: allocate our dynamic array of pixels (width x height x 4)
    // use the variable name "img"
    
    // TODO: Loop through all pixels in the image
    for ( ; ;  ) {
        for ( ; ; ) {
            
            // create a complex number for this specific pixel
            // by transforming coordinates to range [-1,1]
            
	    //TODO: Calculate Real Value a
            //TODO: Calculate complex value  b
            Complex z(a,b);
            
	    //TODO: Complete either the iterative version or recursive version
	    
            // Calculate the escape time
            int esc_t = julia( z, args.c, args.max_itr );
            
            // recursive version
            //int esc_t = julia_recursive(z, args.c, 0, args.max_itr);
            
            // 1D array offset
            int offset = args.color_depth * (y * args.width + x);
            
            rgb color = color_map(esc_t, 0, args.max_itr);
            
            img[ offset + 0 ] = color.r * (esc_t % 256);
            img[ offset + 1 ] = color.g * (esc_t % 256);
            img[ offset + 2 ] = color.b * (esc_t % 256);
            img[ offset + 3 ] = 255;            
        }
    }
    
    // write out PNG file
    std::cout << "Writing fractal to " << args.filename << std::endl;
    unsigned int error = lodepng::encode(args.filename, img, args.width, args.height);
    
    if (error) {
        std::cout << "ERROR: Failed to save png to " << args.filename << std::endl;
    }
    
    delete [] img;

    return 0;
}

// parse command line arguments and return a stuct of parameter values
unsigned int parse_args(int argc, const char * argv[], Arguments & args) {
    
    // defaults
    args.zoom = 1.0;
    args.origin[0] = args.origin[1] = 0;
    args.max_itr = 256;
    args.color_depth = 4;                           // bytes per pixel
    args.c = Complex(-0.7,0.27015);
    
    //TODO: parse command line arguments
    switch ( argc ) {
        case 7:
            
        case 6:
            
        case 4:
            
            break;
        default:
            return 0;   // command line parsing failure
    }
    
    return 1; // command line parsing success
}

//TODO: complete the recursive version or the iterative version
// Feel free to change the parameters if you have an alternative idea

// recursive version
int julia_recursive( Complex & z, const Complex & c, int itr, int max_itr, const double radius2 ) {
    
    
    return julia_recursive( , , , );
}


// iterative version
int julia( Complex & z, const Complex & c, const int max_itr, const double radius2 ) {
        
}

// show command line options
void print_usage()
{
    std::cerr << "Usage: " << "fractal <width> <height> <filename> <a> <b>";
    std::cerr << std::endl;
}
