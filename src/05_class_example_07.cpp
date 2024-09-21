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

    /*
    Friend classes
    --------------
    */
    FriendClassRectangle rect;
    FriendClassSquare sqr(4);
    rect.convert(sqr);
    std::cout << rect.area() << std::endl;

    return 0;
}