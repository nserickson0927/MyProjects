//
//  ppm.h
//  ABC
//
//  Created by Jason Alan Fries on 10/26/13.
//  Copyright (c) 2013 Jason Alan Fries. All rights reserved.
//

#ifndef PPM_H
#define PPM_H

#include <iostream>
#include "image.h"

class PPM: public Image
{
private:
    int m_magic_num;
    int m_color_depth;
    RGB * m_data;
    
    bool read_ascii(char * filename, std::streamoff offset);
    bool read_binary(char * filename, std::streamoff offset);
    bool write_ascii(char * filename);
    bool write_binary(char * filename);
    bool parse_header(char * filename, std::streamoff & offset);
    
public:
    PPM();
    PPM(char * filename);
    PPM(const PPM & ppm);
    virtual ~PPM();
    
    virtual bool read(char * filename);
    virtual bool write(char * filename);
  
    RGB get_pixel(int x, int y) const;
    
    PPM & operator=(const PPM & ppm);
};

#endif
