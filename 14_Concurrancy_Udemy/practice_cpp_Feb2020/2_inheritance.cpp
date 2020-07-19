// compile with -> g++ -W -Wall -std=c++11 -o inheritance 2_inheritance.cpp
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <thread>

using namespace std;

// Base class
class shape{
protected:
  double height;
  double width;
public:
  shape(double &h, double &w) {
    height = h;
    width = w;
  }
  double area() {
    return height*width;
  }
};

// Derived class
class rectangle : public shape {
public:
  rectangle(double &h, double &w):shape(h, w){

  }
  double perimeter(){
    return 2*(height + width);
  }
};

int main(int argc, char** argv) {
  double height = 4.0;
  double width = 3.0;

  shape quad_obj(height, width);
  std::cout << "shape::area=" << quad_obj.area() << std::endl;

  rectangle rect(height, width);
  std::cout << "rectangle::perimeter=" << rect.perimeter() << std::endl;
}
