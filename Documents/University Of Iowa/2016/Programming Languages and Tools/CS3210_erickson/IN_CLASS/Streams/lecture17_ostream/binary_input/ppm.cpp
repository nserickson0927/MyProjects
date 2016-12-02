//
//  ppm.cpp
//  ABC
//
//  Created by Jason Alan Fries on 10/26/13.
//  Copyright (c) 2013 Jason Alan Fries. All rights reserved.
//

#include "pixel.h"
#include "ppm.h"
#include <fstream>
#include <stdlib.h>

// CONSTRUCTOR
PPM::PPM(): m_magic_num(0), m_data(NULL) {}

// CONSTRUCTOR
PPM::PPM(char * filename):
    m_magic_num(0),
    m_color_depth(255),
    m_data(NULL)
{
    std::streamoff offset = 0;
    parse_header(filename,offset);
    
    // BINARY
    if(m_magic_num == 6)
    {
        std::cout << "Loading Binary PBM ..." << std::endl;
        read_binary(filename,offset);
    }
    // ASCII
    else if(m_magic_num == 3)
    {
        std::cout << "Loading ASCII PPM ..." << std::endl;
        read_ascii(filename,offset);
    }
}

// DESTRUCTOR
PPM::~PPM()
{
    if(m_data)
        delete [] m_data;
}

// COPY CONSTRUCTOR - note how we invoke the base class
// copy constructor by passing in the PPM object. How
// does this work, since the Image base class has no
// copy constructor defined with argument type PPM?
PPM::PPM(const PPM & ppm) : Image(ppm)
{
    m_data = new RGB[width() * height()];
    
    for(int i = 0; i < width() * height(); i++)
    {
        m_data[i] = ppm.m_data[i];
    }
    
    m_magic_num = ppm.m_magic_num;
    m_color_depth = ppm.m_color_depth;
}

// Assignment operator
PPM & PPM::operator=(const PPM & ppm)
{
    if(this == &ppm)
        return *this;
    
    Image::operator=(ppm);      // copy base class portion
    
    if(m_data)
        delete [] m_data;       // free previous memory

    m_data = new RGB[width()*height()];
    for(int i=0;i<width()*height(); i++)
    {
        m_data[i] = ppm.m_data[i];
    }

    return *this;
}


// Return the pixel at coordinate (x,y)
RGB PPM::get_pixel(int x, int y) const
{
    return m_data[y * width() + x];
}


// Parse header for PPM file, assigning height, width,
// color depth, and magic number to their respective
// member variables.
bool PPM::parse_header(char * filename, std::streamoff & offset)
{
    std::fstream fin(filename, std::ios_base::in);
    
    if(not fin){
        return false;
    }
    
    int i = 0;
    std::string token;
    
    while(fin >> token && i < 4)
    {
        // skip comments, which have to follow a # char
        if(token[0] == '#')
        {
            fin.ignore(256,'\n');
            continue;
        }

        switch(i)
        {
            case 0: m_magic_num = int(token[1]-'0');
                
            case 1: set_width(atoi(token.c_str()));
                
            case 2: set_height(atoi(token.c_str()));
                
            case 3: m_color_depth = atoi(token.c_str());
        }
        
        ++i;
        offset = fin.tellg();
    }
    
    fin.close();
    offset += 1;
    
    return true;
}

// Reads in a text ppm file
bool PPM::read_ascii(char * filename, std::streamoff offset)
{
    std::fstream fin(filename, std::ios_base::in);
    
    if(!fin)
        return false;
    
    // jump past header information
    fin.seekg(offset);
    
    int i = 0;
    unsigned short token;
    
    m_data = new RGB[ width() * height()];
    RGB * curr_pixel = &m_data[0];
    
    while(fin >> token)
    {
        // assign current pixel
        (*curr_pixel)[i % 3] = token;
        
        // iterate to next pixel
        if(i % 3 == 2)
           ++curr_pixel;
        
        ++i;
    }
        
    fin.close();
    
    return true;
}


// Write PPM file out to disk
bool PPM::write_ascii(char * filename)
{
    int max_row_pixels = 5;
    std::ofstream outfile;
    outfile.open(filename);
    
    // problem opening output file?
    if(!outfile)
        return false;
    
    outfile << "P3" << std::endl;
    outfile << width() << " " << height() << std::endl;
    outfile << m_color_depth << std::endl;
    
    for(int i=0; i < width() * height(); i++)
    {
        outfile << int(m_data[i][0]) << " ";
        outfile << int(m_data[i][1]) << " ";
        
        // only print out max_row_pixels per row
        if(i % max_row_pixels == 0)
            outfile << int(m_data[i][2]) << std::endl;
        else
            outfile << int(m_data[i][2]) << " ";
    }
    
    outfile.close();
    
    return true;
}



bool PPM::read_binary(char * filename,std::streamoff offset)
{
    std::fstream fin(filename, std::ios_base::in | std::ios_base::binary);
    
    if(!fin)
        return false;
    
    // jump past header information
    fin.seekg(offset);
    
    int i = 0;
    unsigned char token;
    
    m_data = new RGB[ width() * height()];
    RGB * curr_pixel = &m_data[0];
    
    while( fin.read((char *)&token, sizeof token) )
    {
        // assign current pixel
        (*curr_pixel)[i % 3] = token;
        
        // iterate to next pixel
        if(i % 3 == 2)
            ++curr_pixel;
        
        ++i;
    }
    
    fin.close();
    
    return true;
}

bool PPM::write_binary(char * filename)
{
    // write out header information
    std::ofstream ftxtout(filename, std::ios_base::out  );
    ftxtout << "P6" << std::endl;
    ftxtout << width() << std::endl << height() << std::endl;
    ftxtout << m_color_depth << std::endl;
    ftxtout.close();

    // write out binary pixel information
    // NOTE: type is very important here, as is the append (std::ios_base::app).
    // We don't want to overwrite our header information.
    std::ofstream fout( filename, std::ios_base::out | std::ios_base::binary | std::ios_base::app );
    fout.write( (char *) m_data, sizeof(RGB) * width() * height() );
    fout.close();
    
    return true;
}

// Write file to disk
bool PPM::write(char * filename)
{
    if(m_magic_num==3)
    {
        std::cout << "Writing ASCII PPM ..." << std::endl;
        write_ascii(filename);
        return true;
    }
    else if(m_magic_num == 6)
    {
        std::cout << "Writing Binary PBM ..." << std::endl;
        write_binary(filename);
        return true;
    }
    
    return false;
}

bool PPM::read(char * filename)
{
    return true;
}

