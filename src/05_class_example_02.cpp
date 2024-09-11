#include <iostream>

#include "class_helper.hpp"

int main()
{
    /*
    The way of calling constructors by enclosing their arguments in parentheses (), is known as functional form.
    But constructors can also be called with other syntaxes.
    */
    Circle foo(10.0); // functional form

    /*
    Constructors with a single parameter can be called using the variable initialization syntax (an equal sign followed by the argument):
     - class_name object_name = initialization_value;
    */
    Circle bar = 20.0; // assignment init.

    /*
    More recently, C++ introduced the possibility of constructors to be called using uniform initialization, which essentially is the same as the functional form,
    but using braces ({}) instead of parentheses (()):
     - class_name object_name { value, value, value, ... }
    */
    Circle baz{30.0}; // uniform initialization.

    /*
    Optionally, the above syntax can include an equal sign before the braces.
    */
    Circle qux = {40.0}; // POD-like

    /*
    An advantage of uniform initialization over functional form is that, unlike parentheses, braces cannot be confused with function declarations,
    and thus can be used to explicitly call default constructors:
     - Rectangle rectb;   // default constructor called
     - Rectangle rectc(); // function declaration (default constructor NOT called)
     - Rectangle rectd{}; // default constructor called
    */

    std::cout << "foo's circumference: " << foo.circum() << '\n';
    std::cout << "bar's circumference: " << bar.circum() << '\n';
    std::cout << "baz's circumference: " << baz.circum() << '\n';
    std::cout << "qux's circumference: " << qux.circum() << '\n';

    /*
    Member initialization in constructors
    */
    Cylinder poo{10, 20};
    std::cout << "foo's volume: " << poo.volume() << '\n';

    /*
    Pointers to classes
    */
    Rectangle rect_obj(3, 4);
    Rectangle *rect_foo, *rect_bar, *rect_baz;
    rect_foo = &rect_obj;
    rect_bar = new Rectangle(5, 6);
    rect_baz = new Rectangle[2]{{2, 5}, {3, 6}};
    std::cout << "rect_obj's area: " << rect_obj.area() << '\n';
    std::cout << "*rect_foo's area: " << rect_foo->area() << '\n';
    std::cout << "*rect_bar's area: " << rect_bar->area() << '\n';
    std::cout << "rect_baz[0]'s area:" << rect_baz[0].area() << '\n';
    std::cout << "rect_baz[1]'s area:" << rect_baz[1].area() << '\n';
    delete rect_bar;
    delete[] rect_baz;
    return 0;
}