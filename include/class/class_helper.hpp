#ifndef CLASS_HELPER
#define CLASS_HELPER

#include <math.h>
#include <iostream>

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

/*
Overloading operators
*/
class CVector
{
public:
  int x, y;
  CVector() {};
  CVector(int, int);
  CVector operator+(const CVector &);
};

/*
Notice that some operators may be overloaded in two forms: either as a member function or as a non-member function:
The first case has been used in the example above for operator+. But some operators can also be overloaded as non-member functions;
In this case, the operator function takes an object of the proper class as first argument.
*/
CVector operator-(const CVector &, const CVector &);

/*
Const member functions
The access to its data members from outside the class is restricted to read-only, 
as if all its data members were const for those accessing them from outside the class. 
Note though, that the constructor is still called and is allowed to initialize and modify these data members:
*/
class MyClass
{
public:
  int x;
  MyClass(int val) : x(val) {}
  
  int get();
  /*
  The member functions of a const object can only be called if they are themselves specified as const members; in the example above, 
  member get (which is not specified as const) cannot be called from foo. To specify that a member is a const member, 
  the const keyword shall follow the function prototype, after the closing parenthesis for its parameters:

  Note that const can be used to qualify the type returned by a member function. This const is not the same as the one which specifies a member as const. 
  Both are independent and are located at different places in the function prototype:
   - int get() const {return x;}        // const member function
   - const int& get() {return x;}       // member function returning a const&
   - const int& get() const {return x;} // const member function returning a const& 

  Member functions specified to be const cannot modify non-static data members nor call other non-const member functions. 
  In essence, const members shall not modify the state of an object.

  const objects are limited to access only member functions marked as const, but non-const objects are not restricted and thus can access 
  both const and non-const member functions alike.
  */
  // int get() const;
  const int& get() const;
};

void print(const MyClass& arg);

/*
Template Function and Classes
*/
template <class T> T sum (T a, T b)
{
  T result;
  result = a + b;
  return result;
}

#endif
