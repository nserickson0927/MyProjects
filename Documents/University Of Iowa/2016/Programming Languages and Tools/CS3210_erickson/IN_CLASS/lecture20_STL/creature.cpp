//
//  creature.cpp
//  STL
//
//  Created by Jason Fries on 11/19/13.
//  Copyright (c) 2013 Jason Fries. All rights reserved.
//

#include "creature.h"

Creature::Creature() : m_name("unknown"), m_xp(0) {}

Creature::Creature(std::string name, int xp) : m_name(name), m_xp(xp) {}

Creature::~Creature() {}

std::string Creature::name() const { return m_name; }

int Creature::xp() const { return m_xp; }
