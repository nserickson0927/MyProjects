//
//  Treasure.h
//  class definitions
//
//  Created by Jason Alan Fries on 9/26/13.
//  Copyright (c) 2013 Jason Fries. All rights reserved.
//

#ifndef TREASURE_H
#define TREASURE_H

#include <iostream>

class Treasure
{
private:
    std::string m_name;
    int m_value;
    static int seeded;
    static std::string adjectives[6];
    static std::string nouns[6];
    
    static int seed();
    
public:
    Treasure();
    Treasure(const Treasure & t);
    int get_value() const;
    std::string get_name() const;
    
    friend std::ostream & operator<<(std::ostream & os, const Treasure & t);
};

#endif
