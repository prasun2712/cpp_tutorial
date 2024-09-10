#include <iostream>

#include "class_helper.hpp"

int main()
{
    Rectangle rect;
    rect.set_values(3, 4);
    std::cout << "Area is : " << rect.area() << "\n";
    return 0;
}