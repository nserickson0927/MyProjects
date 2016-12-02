// stone1.cpp -- user-defined conversion functions
// compile with stonewt1.cpp
#include <iostream>
#include "stonewt1.h"

void printWhateverDouble(double x){
  std::cout<<x<<std::endl;
}

void printWhateverStone(Stonewt s) {
  s.show_stn();
}
int main()
{
    using std::cout;
    Stonewt poppins(9,2.8);     // 9 stone, 2.8 pounds
    double p_wt = poppins;      // implicit conversion
    cout << "Convert to double => ";
    cout << "Poppins: " << p_wt << " pounds.\n";
    cout << "Convert to int => ";
    cout << "Poppins: " << int (poppins) << " pounds.\n";
	// std::cin.get();
    
    printWhateverDouble(poppins);
    printWhateverDouble(p_wt);
    printWhateverStone(poppins);
    printWhateverStone(p_wt);
    return 0; 
}
