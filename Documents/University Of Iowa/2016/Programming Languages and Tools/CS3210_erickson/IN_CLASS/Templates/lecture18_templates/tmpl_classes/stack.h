//
//  stack.h
//  templates
//
//  Created by Jason Alan Fries on 11/4/13.
//  Copyright (c) 2013 Jason Alan Fries. All rights reserved.
//

#ifndef STACK_H
#define STACK_H

#include <iostream>



template <typename T>       // some compilers require "template <class T>"
class Stack
{
private:
    int m_max_size; 
    int m_size;
    T * m_data;             // note that the type of m_data is T -- our template typename
    
public:
    Stack();
    Stack(int size);
    ~Stack();
    
    int size() const;
    bool empty() const;
    bool full() const;
    bool push(T item);
    T pop();
    
    // friend declaration
    friend std::ostream & operator<<(std::ostream & os, Stack<T> & stack)
    {
        os << "STACK size=" << stack.m_size;
        return os;
    }
};

// You might be tempted to define your friend function here, but you
// we will get a linker error if we try here because remember,
// friend functions aren't really members of the  template class!
// The easiest option is to define the function within the class definition
// as is done above

/*
template <typename T>
std::ostream & operator<<(std::ostream & os, Stack<T> & stack)
{
    os << "STACK size=" << stack.m_size;
    return os;
}*/


// Templates unfortunately can't be split into header
// and cpp file in an elegant way (**see link below), so
// we include defintion and implementation into a single file.
//
// ** See this link for more information on the topic:
// http://www.codeproject.com/Articles/48575/How-to-define-a-template-class-in-a-h-file-and-imp

// CONSTRUCTOR
template <typename T>
Stack<T>::Stack() : m_size(0), m_max_size(10)
{
    m_data = new T[m_max_size];
}

// CONSTRUCTOR
template <typename T>
Stack<T>::Stack(int size) : m_size(0), m_max_size(size)
{
    m_data = new T[m_max_size];
}

// DESTRUCTOR
template <typename T>
Stack<T>::~Stack()
{
    delete [] m_data;
}

// Returns true if stack is empty, false otherwise.
template <typename T>
bool Stack<T>::empty() const
{
    return !m_size;
}

// Returns true if stack is full, false otherwise.
template <typename T>
bool Stack<T>::full() const
{
    return m_max_size==m_size;
}

// Return current stack size.
template <typename T>
int Stack<T>::size() const
{
    return m_size;
}

// Removes item from top of stack by reference.
template <typename T>
T Stack<T>::pop()
{
    return m_data[--m_size];
}

// Adds item to top of stack, if there is space.
template <typename T>
bool Stack<T>::push(T item)
{
    if(m_size < m_max_size)
    {
        m_data[m_size++] = item;
        return true;
    }
    
    std::cerr << "++ stack is full ++" << std::endl;     // print to standard error
    return false;
}


// ==============================================================================

// templates have to have the same number of arguments, meaning we can't
// have a Stack class template named Stack that also accepts a size template argumnet

template <typename T, int n>
class SizedStack
{
private:
    int m_max_size;
    int m_size;
    T * m_data;
    
public:
    SizedStack();
    ~SizedStack();
    
    int size() const;
    bool empty() const;
    bool full() const;
    bool push(T item);
    T pop();
  
    friend std::ostream & operator<<(std::ostream & os, SizedStack<T,n> & stack)
    {
        os << "STACK size=" << stack.m_size;
        return os;
    }
};

// CONSTRUCTOR
template <typename T, int n>
SizedStack<T,n>::SizedStack() : m_size(0), m_max_size(n)
{
    m_data = new T[n];
}

// DESTRUCTOR
template <typename T, int n>
SizedStack<T,n>::~SizedStack()
{
    delete [] m_data;
}

// Returns true if stack is empty, false otherwise.
template <typename T, int n>
bool SizedStack<T,n>::empty() const
{
    return !m_size;
}

// Returns true if stack is full, false otherwise.
template <typename T, int n>
bool SizedStack<T,n>::full() const
{
    return m_max_size==m_size;
}

// Return current stack size.
template <typename T, int n>
int SizedStack<T,n>::size() const
{
    return m_size;
}

// Removes item from top of stack
template <typename T, int n>
T SizedStack<T,n>::pop()
{
    return m_data[--m_size];
}

// Adds item to top of stack, if there is space.
template <typename T, int n>
bool SizedStack<T,n>::push(T item)
{
    if(m_size < m_max_size)
    {
        m_data[m_size++] = item;
        return true;
    }
    
    std::cerr << "++ stack is full ++" << std::endl;     // print to standard error
    return false;
}

#endif
