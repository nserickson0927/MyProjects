//
//  main.cpp
//  image
//
//  Created by Jason Alan Fries on 11/14/13.
//  Copyright (c) 2013 Jason Alan Fries. All rights reserved.
//

#include <iostream>
#include <fstream>

struct Planet
{
    char name[20];
    long population;
    double g;
    
    friend std::ostream & operator<<(std::ostream & os, Planet & p)
    {
        os << p.name << " " << p.population << " " << p.g;
        return os;
    }
};

unsigned int echo_textfile(char * filename);


int main(int argc, const char * argv[])
{
    
    //
    // I. Writing/Reading Binary Data
    //
    
    // ----------------------------------------------------------------
    // EXAMPLE 1: Writing to Text File
    // ----------------------------------------------------------------
    int x;
    int y{};
    Planet earth = {"Earth", 7042000000, 9.78};
    std::cout << "PLANET: " << earth << std::endl;
    
    // Writing to a text file simply involves using an ofstream object
    // that maps to a file (instead of stdout). Otherwise use of this
    // object is the same as cout.
    std::ofstream ftxtout("data/planet.txt", std::ios_base::out | std::ios_base::app ); // write and append to file
    ftxtout << earth.name << " " << earth.population << " " << earth.g << std::endl;
    ftxtout.close();
    
    
    // ----------------------------------------------------------------
    // EXAMPLE 2: Reading a text file
    // ----------------------------------------------------------------
    std::cout << "Text File Contents" << std::endl;
    std::cout << "-------------------------------" << std::endl;
    echo_textfile( (char*)"data/planet.txt" );
    std::cout << "-------------------------------" << std::endl;
    
    // ----------------------------------------------------------------
    // EXAMPLE 2: Writing to Binary File
    // ----------------------------------------------------------------
    
    // But this is cumbersome and output files take up more space.
    // A more effecient way is to use a binary format
    // if you wanted to append to an existing file (vs create a new file) you would use the flag
    // std::ios_base::app
    std::ofstream fout( "data/planet.dat", std::ios_base::out | std::ios_base::binary );
    fout.write( (char *) &earth, sizeof earth );
    fout.close();

    // Now we can read the file back in as follows
    // NOTE: we are using an *ifstream* object here
    Planet mirror_earth;
    std::cout << "Copy PLANET:" << mirror_earth << std::endl;
    
    std::ifstream fin("data/planet.dat", std::ios_base::in | std::ios_base::binary );
    fin.read( (char *) &mirror_earth, sizeof mirror_earth );
    fin.close();
    
    // This process of converting data objects and object state to a format
    // that can stored and reloaded at another time is called serialization
    
    std::cout << "Copy PLANET:" << mirror_earth << std::endl;
    
    return 0;
}



// echo text file contexts to stdout
unsigned int echo_textfile(char * filename) {

    std::string line;
    std::ifstream fin;
  
    fin.open(filename);
    if ( !fin )
    {
        std::cout << "File not found" << std::endl;
        return false;
    }
    
    while ( getline(fin,line) )    // read in a file line-by-line
    {
        std::cout << line << std::endl;
    }
    
    return true;
}


