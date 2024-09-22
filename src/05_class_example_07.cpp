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

    /*
    Inheritance between classes
    ---------------------------
    */
    DerivedRectangle rec;
    DerivedTriangle trgl;
    rec.set_values(4, 5);
    trgl.set_values(4, 5);
    std::cout << "Rectangle area : " << rec.area() << '\n';
    std::cout << "Triangle area : " << trgl.area() << '\n';

    return 0;
}