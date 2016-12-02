//HW05_13.cpp
//
//By: Nicholas Erickson

#include <iostream>

using namespace std;

double compound_interest(double InitialAmount, double AnnualInterest, int NumberOfYears){
    InitialAmount=InitialAmount+(InitialAmount*AnnualInterest);//Incremented interest in a year
    
    if(NumberOfYears>1){
        InitialAmount=compound_interest(InitialAmount, AnnualInterest, NumberOfYears-1);//call the funcion again but with one less year
    }
    
    return InitialAmount;
}

int main(){
    return 0;
}