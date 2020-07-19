/* shape class is a template class. rectangle class is also a template
class but inherited from shape class.*/

/* compile: g++ -W -Wall -std=c++11 -o inhr_template 3_inheritance_template.cpp*/

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <thread>

using namespace std;

// Base class
template <typename T>
class shape{
protected:
  T height;
  T width;
public:
  shape(T &h, T &w) {
    height = h;
    width = w;
  }
  double area() {
    return height*width;
  }
};

// Derived class
template <typename T>
class rectangle : public shape<T> {
protected:
  string class_type;
public:
  rectangle(T &h, T &w, string &type_name):shape<T>(h, w){
    class_type = type_name;
  }
  T perimeter(){
    return 2*(shape<T>::height + shape<T>::width);
  }
  void get_class_name(){
    std::cout << "class_name=" << this->class_type << std::endl;
  }
};

int main(int argc, char** argv) {
  double height = 4.0;
  double width = 3.0;

  shape<double> quad_obj(height, width);
  std::cout << "shape::area=" << quad_obj.area() << std::endl;

  string class_name = "rectangle";
  rectangle<double> rect(height, width, class_name);
  rect.get_class_name();
  std::cout << "rectangle::perimeter=" << rect.perimeter() << std::endl;
}
