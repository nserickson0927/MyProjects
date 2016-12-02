//
//  image.h
//  ABC
//
//  Created by Jason Alan Fries on 10/26/13.
//  Copyright (c) 2013 Jason Alan Fries. All rights reserved.
//

// This is an Abstract Base Class (ABC) for an image data type.
// The ABC allows us to formally specify an interface for this
// data type. Using virtual functions for core features (read/write)
// and protected class member functions to 

#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>
#include "pixel.h"

class Image
{
private:
    int m_width;
    int m_height;
    
protected:
    void set_width(int width);
    void set_height(int height);
    
public:
    Image();
    virtual ~Image();
    
    int width() const;
    int height() const;
    
    virtual RGB get_pixel(int x, int y) const = 0;
    virtual bool read(char * filename) = 0;
    virtual bool write(char * filename) = 0;
};

#endif
