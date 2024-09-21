#include <iostream>

#include <class_helper.hpp>

int main()
{
    /*
    Friend functions
    ----------------
    */
    FriendRectangle foo;
    FriendRectangle bar(2, 3);
    foo = duplicate(bar);
    std::cout << foo.area() << '\n';
    return 0;
}