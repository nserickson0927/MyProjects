//
//  Treasure.cpp
//  classes2
//
//  Created by Jason Alan Fries on 9/26/13.
//  Copyright (c) 2013 Jason Fries. All rights reserved.
//

#include "treasure.h"
#include <stdlib.h>

// static member variables
std::string Treasure::adjectives[6] = {"Gold","Tin","Copper","Lead","Granite","Cookie Dough"};
std::string Treasure::nouns[6] = {"Staff","Sword","Puzzle","Bag","Robe","Pants"};
int Treasure::seeded = Treasure::seed(); // Q: Why does this have to be a static function?

// This function is only called once, since we assign the
// value to a static varible inside our class
int Treasure::seed()
{
    int seed = int(time(NULL));
    srand(seed);
    return seed;
}

// CONSTRUCTOR
Treasure::Treasure()
{
    m_name = adjectives[int(rand() % 6)] + " " + nouns[int(rand()%6)];
    m_value = int(rand() % 100);
}

// COPY CONSTRUCTOR
Treasure::Treasure(const Treasure & t)
{
    m_value = t.m_value;
    m_name.assign(t.m_name);
}

// get value of treasure
int Treasure::get_value() const
{
    return m_value;
}

// get name of treasure
std::string Treasure::get_name() const
{
    return m_name;
}

std::ostream & operator<<(std::ostream & os, const Treasure & t)
{
    os << "Treasure[" << t.m_name << " is worth " << t.m_value << "]";
    return os;
}