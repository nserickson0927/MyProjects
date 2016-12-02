#include <iostream>
// this is a Header file

class Point {
public:
  double x, y;
  void offset(double offsetX, double offsetY);
  void print();
  Point()
  {
    x=0.0;
    y=0.0;
    std::cout<<"point instance creates"<<std::endl;
  }
};

class Vector {
public:
  Point start, end;
  void offset(double offsetX, double offsetY);
  void print();
};