#include <iostream>

using namespace std;

/*
This program at first creates a class SHAPE. Then two derived classes RECTANGLE
and SQUARE are created based on Inheritance method. The class SQUARE overrides
the PrintInfo() method of SHAPE class using Polymorphism method. The SHAP class
also shows how to use a Friend function of a class.
*/

// Base class
class Shape {
protected:
  int height;
  int width;
public:
  Shape(int h,int w);
  int Area();
  void PrintInfo();
  friend void CheckSides(Shape& obj);
};

Shape::Shape(int h, int w) {
  height = h;
  width = w;
}

int Shape::Area() {
  std::cout << "Shape::Area is called" << std::endl;
  return height*width;
}

void Shape::PrintInfo() {
  std::cout << "(height,width)=" << height << "," << width << std::endl;
}

// Inheritance example
class Rectangle:public Shape {
public:
  Rectangle(int h, int w) : Shape(h,w) {}
  int Perimeter();
};

int Rectangle::Perimeter() {
  std::cout << "Rectangle::Perimeter is called" << std::endl;
  return 2*(height+width);
}

// Inheritance with polymorphism example
class Square:public Shape {
public:
  Square(int h, int w): Shape(h,w) {}
  int Perimeter();
  void PrintInfo(); // polymorphism
};

int Square::Perimeter() {
  std::cout << "Square::Perimeter is called" << std::endl;
  return 4*height;
}

void Square::PrintInfo() {
  std::cout << "Each side=" << height << std::endl;
}

void CheckSides(Shape& obj) {
  if (obj.height != obj.width) {
    std::cout << "Sides are not equal" << std::endl;
  }
  else {
    std::cout << "All sides are equal" << std::endl;
  }
}

int main(int argc, char** argv) {
  // create a shape object
  Shape s = Shape(2,3);
  s.PrintInfo();
  std::cout << "Area: " << s.Area() << std::endl;
  CheckSides(s);
  std::cout << "-----------------------" << std::endl;

  // create a rectangle object
  Rectangle r = Rectangle(4,9);
  r.PrintInfo();
  std::cout << "Rectangle Area: " << r.Area() << std::endl;
  std::cout << "Rectangle Perimeter: " << r.Perimeter() << std::endl;
  CheckSides(r);
  std::cout << "-----------------------" << std::endl;

  // create a square object
  Square sq = Square(4,4);
  sq.PrintInfo();
  std::cout << "Square Area: " << sq.Area() << std::endl;
  std::cout << "Square Perimeter: " << sq.Perimeter() << std::endl;
  CheckSides(sq);
  std::cout << "-----------------------" << std::endl;

  return 0;
}
