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
  const int &get() const;
};

void print(const MyClass &arg);

/*
Template Function and Classes
*/
template <class T>
T sum(T a, T b)
{
  T result;
  result = a + b;
  return result;
}

// Templates are a powerful and versatile feature. They can have multiple template parameters, and the function can still use regular non-templated types.
// For example:
template <class T, class U>
bool are_equal(T a, U b)
{
  return (a == b);
}

// Non-type template arguments - The template parameters can not only include types introduced by class or typename, 
// but can also include expressions of a particular type:
// The second argument of the fixed_multiply function template is of type int. It just looks like a regular function parameter, 
// and can actually be used just like one.
// But there exists a major difference: the value of template parameters is determined on compile-time to generate a different 
// instantiation of the function fixed_multiply, and thus the value of that argument is never passed during runtime: 
// The two calls to fixed_multiply in main essentially call two versions of the function: one that always multiplies by two, 
// and one that always multiplies by three. For that same reason, the second template argument needs to be a constant expression (it cannot be passed a variable).
template <class T, int N>
T fixed_multiply(T val)
{
  return val * N;
}

#endif
