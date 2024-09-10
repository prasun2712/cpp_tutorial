#include <iostream>

#include "class_helper.hpp"

int main()
{
    // Arguments are passed to the constructor at the moment at which the objects of this class are created.
    // Constructors cannot be called explicitly as if they were regular member functions. They are only executed once, when a new object of that class is created.
    /*
    But this example also introduces a special kind constructor: the default constructor. The default constructor is the constructor that takes no parameters,
    and it is special because it is called when an object is declared but is not initialized with any arguments.
    */
    Rectangle rect(3, 4), rectb;
    std::cout << "rect area: " << rect.area() << std::endl;
    std::cout << "rectb area: " << rectb.area() << std::endl;
    return 0;
}