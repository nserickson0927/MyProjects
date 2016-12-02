#include <iostream>
#include "calculator.h"
#include <climits>
#include <stdexcept>

using namespace std;


int main() {
    double a_arr[] = {INT_MAX, 3};
    double b_arr[] = {6, 6};
    Calculate a(a_arr);
    Calculate b(b_arr);
    try{
        Calculate c = a + b;
    }
    catch (std::overflow_error e){
        std::cout << e.what() << std::endl;
    }

    try{
        Calculate c=a*b;
    }
    catch (std::overflow_error e){
        std::cout << e.what() << std::endl;
    }
    catch (std::underflow_error e){
        std::cout<<e.what()<<std::endl;
    }
    try{
        Calculate c=a/b;
    }
    catch (div_by_zero e) {
        std::cout<<e.what()<<std::endl;
    }


    return 0;
}