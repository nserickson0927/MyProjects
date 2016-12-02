//
//  alerts.h
//  exceptions
//
//  Created by Jason Fries on 11/7/13.
//  Copyright (c) 2013 Jason Alan Fries. All rights reserved.
//

#ifndef ALERT_H
#define ALERT_H

#include <iostream>
#include <exception>

class Alert : public std::exception
{
protected:
    std::string m_msg;
    
public:
    static const std::string MAGENTA;
    static const std::string BLUE;
    static const std::string GREEN;
    static const std::string ORANGE;
    static const std::string RED;
    static const std::string ENDC;
    static const std::string BOLD_TXT;

    Alert();
    Alert(std::string msg);
    virtual ~Alert() throw();
    
    virtual const char * what() const throw();
    virtual const std::string message() const throw();
};


class OrangeAlert : public Alert
{
public:
    OrangeAlert();
    virtual ~OrangeAlert() throw();
    
    virtual const char * what() const throw();
    virtual const std::string message() const throw();
};


class RedAlert : public OrangeAlert
{
public:
    RedAlert();
    virtual ~RedAlert() throw();
    
    virtual const char * what() const throw();
    virtual const std::string message() const throw();
};

#endif
