//
//  pixel.h
//  ABC
//
//  Created by Jason Alan Fries on 10/26/13.
//  Copyright (c) 2013 Jason Alan Fries. All rights reserved.
//

#ifndef PIXEL_H
#define PIXEL_H

struct RGB
{
    RGB() { data[0] = 0; data[1] = 0; data[2] = 0; }
    unsigned char data[3];
    unsigned char & operator[](const int & idx) { return data[idx]; }
};

#endif
