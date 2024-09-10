#ifndef CLASS_HELPER
#define CLASS_HELPER

#include <math.h>

class Rectangle
{
  int width, height;

public:
  void set_values(int, int);
  int area() { return width * height; }
};

#endif
