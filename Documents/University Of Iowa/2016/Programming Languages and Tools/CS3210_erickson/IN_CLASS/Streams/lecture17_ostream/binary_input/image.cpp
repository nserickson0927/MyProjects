//
//  image.cpp
//  ABC
//
//  Created by Jason Alan Fries on 10/26/13.
//  Copyright (c) 2013 Jason Alan Fries. All rights reserved.
//

#include "image.h"

Image::Image(): m_width(0), m_height(0) {}

Image::~Image()
{
    std::cout << "** Image DESTRUCTOR invoked **" << std::endl;
}

void Image::set_width(int width) { m_width = width; }

void Image::set_height(int height){ m_height = height; }

int Image::width() const { return m_width; }

int Image::height() const { return m_height; }