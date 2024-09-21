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

/*
Default constructor.
*/
Example3::Example3(const std::string &str) : data(str)
{
}
Example3::Example3()
{
}
const std::string &Example3::content() const
{
    return data;
}

/*
Destructor.
*/
Example4::Example4() : ptr(new std::string)
{
    std::cout << "Example4 : Default constructor called. \n";
}

Example4::Example4(const std::string &str) : ptr(new std::string(str))
{
    std::cout << "Example4 : Constructor called. \n";
}

Example4::~Example4()
{
    delete ptr;
    std::cout << "Example4 : Destructor called. \n";
}

const std::string &Example4::content() const
{
    return *ptr;
}

/*
Copy constructor.
*/
Example5::Example5() : ptr(new std::string)
{
    std::cout << "Example5 : Default constructor called. \n";
}

Example5::Example5(const std::string &str) : ptr(new std::string(str))
{
    std::cout << "Example5 : Constructor called. \n";
}

Example5::~Example5()
{
    std::cout << "Example5 : Destructor called. \n";
    delete ptr;
}

Example5::Example5(const Example5 &x) : ptr(new std::string(x.content()))
{
    std::cout << "Example5 : Custom copy constructor called. (Deep copy done.)\n";
}

const std::string &Example5::content() const
{
    return *ptr;
}

Example5 &Example5::operator=(const Example5 &x)
{
    std::cout << "Copy assignment called for the object of class Example5. \n";
    delete ptr;                         // delete currently pointed string
    ptr = new std::string(x.content()); // allocate space for new string, and copy
    return *this;
    // Or
    // *ptr = x.content();
    // return *this;
}

/*
Move constructor and assignment.
*/
Example6::Example6(const std::string &str) : ptr(new std::string(str))
{
    std::cout << "Example6 : Constructor called. \n";
}

Example6::~Example6()
{
    std::cout << "Example6 : Destructor called. \n";
    delete ptr;
}

Example6::Example6(Example6 &&x) : ptr(x.ptr)
{
    std::cout << "Example6 : Move constructor called. \n";
    x.ptr = nullptr;
}

Example6 &Example6::operator=(Example6 &&x)
{
    std::cout << "Example6 : Move assignment called. \n";
    delete ptr;
    ptr = x.ptr;
    x.ptr = nullptr;
    return *this;
}

const std::string &Example6::content() const
{
    std::cout << "Example6 : Content accessed. \n";
    return *ptr;
}

Example6 Example6::operator+(const Example6 &rhs)
{
    std::cout << "Example6 : Addition performed. \n";
    return Example6(content() + rhs.content());
}

/*
Implicit members
================
*/

Rect::Rect(int x, int y) : width(x), height(y)
{
    std::cout << "Rect class constructor called. \n";
}

Rect::Rect() = default;

Rect::Rect(const Rect &other) = delete;

int Rect::area()
{
    return width * height;
}

/*
Friend functions
----------------
*/

FriendRectangle::FriendRectangle()
{
    std::cout << "FriendRectangle class default constructor called.\n";
}

FriendRectangle::FriendRectangle(int x, int y) : width(x), height(y)
{
    std::cout << "FriendRectangle class constructor called.\n";
}

int FriendRectangle::area()
{
    std::cout << "Rectangle area calculator function called.\n";
    return width * height;
}

FriendRectangle duplicate (const FriendRectangle& param)
{
  FriendRectangle res;
  res.width = param.width*2;
  res.height = param.height*2;
  return res;
}