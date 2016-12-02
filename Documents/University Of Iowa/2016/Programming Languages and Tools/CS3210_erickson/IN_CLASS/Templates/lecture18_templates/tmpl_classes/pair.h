//
//  pair.h
//  templates
//
//  Created by Jason Alan Fries on 11/4/13.
//  Copyright (c) 2013 Jason Alan Fries. All rights reserved.
//

#ifndef PAIR_H
#define PAIR_H

// this has come *before* the defintion of the Pair class,
// so we use the following syntax to let the compiler know
// about the Pair class
template <typename T, typename U> class Pair;
template <typename T, typename U>
std::ostream & operator<<(std::ostream & os, const Pair<T,U> & pair)
{
    os << "Pair (" << pair.m_a << ", " << pair.m_b << ")";
    return os;
}

// ==============================================================================

template <typename T, typename U>
class Pair
{
private:
    T m_a;
    U m_b;
    
public:
    Pair(T a, U b);
    
    friend std::ostream & operator<< <T,U> (std::ostream & os, const Pair<T,U> & pair);
};

// CONSTRUCTOR
template <typename T, typename U>
Pair<T,U>::Pair(T a, U b) : m_a(a), m_b(b)
{
    std::cout << "General template Pair<typename T, typename U> " << std::endl;
}

// ==============================================================================

template <typename T>
class Pair<T,int>
{
private:
    T m_a;
    int m_b;
    
public:
    Pair();
    Pair(T a, int b);
    
    friend std::ostream & operator<< <T,int> (std::ostream & os, const Pair<T,int> & pair);
};

template <typename T>
Pair<T,int>::Pair(T a, int b) : m_a(a), m_b(b)
{
    std::cout << "Partial specialization Pair<typename T, int> " << std::endl;
}

// ==============================================================================

// not template arguments to define, but we still need to
// let the compiler know this is a template class
template <>
class Pair<int,int>
{
private:
    int m_a;
    int m_b;
    
public:
    Pair();
    Pair(int a, int b);
    
    friend std::ostream & operator<< <int,int> (std::ostream & os, const Pair<int,int> & pair);
};

Pair<int,int>::Pair(int a, int b) : m_a(a), m_b(b)
{
    std::cout << "Explicit specialization Pair<int, int> " << std::endl;
}

#endif
