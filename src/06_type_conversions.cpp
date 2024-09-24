#include <iostream>

using namespace std;

class A
{
};

class B
{
/*
In the world of classes, implicit conversions can be controlled by means of three member functions:

     - Single-argument constructors: allow implicit conversion from a particular type to initialize an object.
     - Assignment operator: allow implicit conversion from a particular type on assignments.
     - Type-cast operator: allow implicit conversion to a particular type.

For example:
*/
public:
    // conversion from A (constructor):
    B(const A &x) {std::cout<<"Conversion from A (constructor)\n";}
    // conversion from A (assignment):
    B &operator=(const A &x) { std::cout<<"Conversion from A (assignment)\n";return *this; }
    // conversion to A (type-cast operator)
    operator A() { std::cout<<"Conversion from A (type-cast operator)\n";return A(); }
    /*
    The type-cast operator uses a particular syntax: it uses the operator keyword followed by the destination type and an empty set of parentheses. 
    Notice that the return type is the destination type and thus is not specified before the operator keyword.
    */
};

int main()
{
    A foo;
    B bar = foo; // calls constructor
    bar = foo;   // calls assignment
    foo = bar;   // calls type-cast operator
    return 0;
}