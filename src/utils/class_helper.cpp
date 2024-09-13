#include "class_helper.hpp"

Rectangle::Rectangle(int x, int y)
{
    width = x;
    height = y;
};

Rectangle::Rectangle()
{
    width = 5;
    height = 5;
}

int Rectangle::area()
{
    return width * height;
}

/*
Uniform initialization.
*/
Circle::Circle(double r)
{
    radius = r;
}

double Circle::circum()
{
    return 2 * radius * 3.14159265;
}

double Circle::area()
{
    return radius * radius * 3.14159265;
}

/*
Member initialization in constructors
When a constructor is used to initialize other members, these other members can be initialized directly, without resorting to statements in its body.
This is done by inserting, before the constructor's body, a colon (:) and a list of initializations for class members.
For example, consider a class with the following declaration:

class Rectangle {
    int width,height;
  public:
    Rectangle(int,int);
    int area() {return width*height;}
};

The constructor for this class could be defined, as usual, as:

 - Rectangle::Rectangle (int x, int y) { width=x; height=y; }

But it could also be defined using member initialization as:

 - Rectangle::Rectangle (int x, int y) : width(x) { height=y; }

Or even:

 - Rectangle::Rectangle (int x, int y) : width(x), height(y) { }

For members of fundamental types, it makes no difference which of the ways above the constructor is defined,
because they are not initialized by default, but for member objects (those whose type is a class),
if they are not initialized after the colon, they are default-constructed.

Default-constructing all members of a class may or may always not be convenient: in some cases,
this is a waste (when the member is then reinitialized otherwise in the constructor), but in some other cases,
default-construction is not even possible (when the class does not have a default constructor).
In these cases, members shall be initialized in the member initialization list.

In this example, class Cylinder has a member object whose type is another class (base's type is Circle).
Because objects of class Circle can only be constructed with a parameter,
Cylinder's constructor needs to call base's constructor, and the only way to do this is in the member initializer list.
*/
// Cylinder::Cylinder(double r, double h) : base(r), height(h)
Cylinder::Cylinder(double r, double h) : base{r}, height{h}
{
}

double Cylinder::volume()
{
    return base.area() * height;
}

/*
Overloading operators
Operators are overloaded by means of operator functions, which are regular functions with special names:
their name begins by the operator keyword followed by the operator sign that is overloaded. The syntax is:
 - type operator sign (parameters) { ... body ... }

For example, cartesian vectors are sets of two coordinates: x and y.
The addition operation of two cartesian vectors is defined as the addition both x coordinates together, and both y coordinates together.
For example, adding the cartesian vectors (3,1) and (5,2) together would result in (3+5,1+2) = (8,3). This could be implemented in C++ with the following code:
*/
CVector::CVector(int a, int b) : x(a), y(b)
{
}

CVector CVector::operator+(const CVector &param)
{
    CVector temp;
    temp.x = x + param.x;
    temp.y = y + param.y;
    return temp;
}

CVector operator-(const CVector &lhs, const CVector &rhs)
{
    CVector temp;
    temp.x = lhs.x - rhs.x;
    temp.y = lhs.y - rhs.y;
    return temp;
}

/*
Const member functions
*/
int MyClass::get()
{
    std::cout << "Non-constant member function get() is called." << "\n";
    return x;
}

// int MyClass::get() const
// {
//     return x;
// }

/*
If in this example, get was not specified as a const member, the call to arg.get() in the print function would not be possible, 
because const objects only have access to const member functions.

Member functions can be overloaded on their constness: i.e., a class may have two member functions with identical signatures except 
that one is const and the other is not: in this case, the const version is called only when the object is itself const, 
and the non-const version is called when the object is itself non-const.
*/
const int &MyClass::get() const
{
    std::cout << "Constant member function get() is called." << "\n";
    return x;
}

void print(const MyClass &arg)
{
    std::cout << arg.get() << '\n';
}