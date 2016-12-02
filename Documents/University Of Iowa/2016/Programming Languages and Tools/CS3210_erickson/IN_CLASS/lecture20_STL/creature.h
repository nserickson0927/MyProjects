//
//  creature.h
//  STL
//
//  Created by Jason Fries on 11/19/13.
//  Copyright (c) 2013 Jason Fries. All rights reserved.
//

#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>

class Creature
{
private:
    std::string m_name;
    int m_xp;
    
public:
    Creature();
    Creature(std::string name, int xp);
    virtual ~Creature();
    
    std::string name() const;
    int xp() const;
};

#endif
