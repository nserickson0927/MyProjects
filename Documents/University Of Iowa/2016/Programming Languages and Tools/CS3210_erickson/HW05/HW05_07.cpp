#include <iostream>
#include <string>

template <typename I, typename J, typename K>
double average(I itema, J itemb, K itemc){
    double a=itema;
    double b=itemb;
    double c=itemc;

    double avg=(a+b+c)/3.0;

    return avg;
};

int main(){
    std::cout<<average<int, double, float>(5, 9.0, 8.0)<<std::endl;


    return 0;
}