//HW05_14.cpp
//
//By: Nicholas Erickson

#include <iostream>

using namespace std;

//int MyArray[5]={1,2,3,4,5};

template <typename I>
void modify(I MyArray){
    int newArray[5]={};
    std::cout<<"Old array elements"<<std::endl;
    for(int i=0; i<5; i++){
        std::cout<<MyArray[i]<<std::endl;
        newArray[i]=MyArray[i]+=1;
    }
    std::cout<<"New array elements."<<std::endl;
    for(int elem=0; elem<5; elem++){

        std::cout<<newArray[elem]<<std::endl;
    }
}

int main(){
    int AnArray[5]={1,2,3,4,5};

    modify(AnArray);

    return 0;
}