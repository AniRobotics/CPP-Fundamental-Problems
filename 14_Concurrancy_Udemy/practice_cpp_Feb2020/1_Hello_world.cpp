#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <thread>

using namespace std;

template <typename T>
class shape{
protected:
  T height;
  T width;
public:
  shape(T& h, T& w) {
    height = h;
    width = w;
  }
  T area() {
    cout << height*width << endl;
    return height*width;
  }
};


int main() {
  std::cout << "Hello World!!!!" << std::endl;

  double height = 2.0;
  double width = 2.0;

  shape<double> quad_obj(height, width);
  std::cout << "area=" << quad_obj.area() << std::endl;
}
