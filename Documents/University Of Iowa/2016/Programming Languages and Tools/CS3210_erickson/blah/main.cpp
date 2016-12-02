#include <iostream>

int main(int argc, char **argv) {
    int    * myArrayINT=new int[5];
    float * myArrayFLOAT=new float[5];
    
    myArrayINT=myArrayFLOAT;//can't convert 'float*' to 'int*'
    return 0;
}
