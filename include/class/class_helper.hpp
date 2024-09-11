#ifndef CLASS_HELPER
#define CLASS_HELPER

#include <math.h>

class Rectangle
{
  int width, height;

public:
  /*
  In order to avoid that, a class can include a special function called its constructor, which is automatically called whenever a new object of this class is created,
  allowing the class to initialize member variables or allocate storage.
  This constructor function is declared just like a regular member function, but with a name that matches the class name and without any return type; not even void.
  */
  /*
  Overloading Constructor - a constructor can also be overloaded with different versions taking different parameters:
  with a different number of parameters and/or parameters of different types. The compiler will automatically call the one whose parameters match the arguments:
  */
  Rectangle(int, int);
  Rectangle();
  int area();
};

/*
Uniform initialization.
*/
class Circle
{
  double radius;

public:
  Circle(double r);
  double circum();
  double area();
};

/*
Member initialization in constructors
*/
class Cylinder
{
  Circle base;
  double height;

public:
  Cylinder(double, double);
  double volume();
};

#endif
