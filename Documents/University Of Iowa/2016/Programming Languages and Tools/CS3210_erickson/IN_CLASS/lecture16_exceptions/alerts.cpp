//
//  alerts.cpp
//  exceptions
//
//  Created by Jason Fries on 11/7/13.
//  Copyright (c) 2013 Jason Alan Fries. All rights reserved.
//

#include "alerts.h"

const std::string Alert::MAGENTA = "\033[95m";
const std::string Alert::BLUE = "\033[94m";
const std::string Alert::GREEN = "\033[92m";
const std::string Alert::ORANGE = "\033[93m";
const std::string Alert::RED = "\033[91m";
const std::string Alert::ENDC = "\033[0m";
const std::string Alert::BOLD_TXT = "\033[1m";

// Base Alert
//-------------------------------------------------------------
Alert::Alert() : std::exception(), m_msg() {}

Alert::Alert( std::string msg ) : std::exception(), m_msg(msg) {}

Alert::~Alert() throw()
{
    std::cout << " ---> Base alert destructor" << std::endl;
}

const char * Alert::what() const throw() // exception specfication
{
    return static_cast<const char *>("Base Alert Exception");
}

const std::string Alert::message() const throw() {
    
    return m_msg;
}

// Orange Alert
//-------------------------------------------------------------
OrangeAlert::OrangeAlert() : Alert() {}

OrangeAlert::~OrangeAlert() throw()
{
    std::cout << " ---> Orange alert destructor" << std::endl;
}
    
const char * OrangeAlert::what() const throw() {
    
    return static_cast<const char *>("ORANGE Alert Exception");
}

const std::string OrangeAlert::message() const throw() {
    
    return Alert::ORANGE + "ORANGE Alert Exception" + Alert::ENDC;
}

// Red Alert
//-------------------------------------------------------------
RedAlert::RedAlert() : OrangeAlert() {}

RedAlert::~RedAlert() throw()
{
    std::cout << " ---> Red alert destructor" << std::endl;
}

const char * RedAlert::what() const throw()
{
    return static_cast<const char *>("***RED Alert*** Exception");
}

const std::string RedAlert::message() const throw() {

    return Alert::RED + BOLD_TXT +  "RED Alert Exception" + Alert::ENDC;
   
}
