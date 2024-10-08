#include <iostream>

#include <class_helper.hpp>

int main()
{
    /*
    Friend functions
    ----------------
    */
    std::cout << "===\n";
    std::cout << "Friend functions example.\n";
    std::cout << "---\n";
    FriendRectangle foo;
    FriendRectangle bar(2, 3);
    foo = duplicate(bar);
    std::cout << foo.area() << '\n';
    std::cout << "===\n\n";

    /*
    Friend classes
    --------------
    */
    std::cout << "===\n";
    std::cout << "Friend classes example.\n";
    std::cout << "---\n";
    FriendClassRectangle rect;
    FriendClassSquare sqr(4);
    rect.convert(sqr);
    std::cout << rect.area() << std::endl;
    std::cout << "===\n\n";

    /*
    Inheritance between classes
    ---------------------------
    */
    std::cout << "===\n";
    std::cout << "Inheritance between classes example.\n";
    std::cout << "---\n";
    DerivedRectangle rec;
    DerivedTriangle trgl;
    rec.set_values(4, 5);
    trgl.set_values(4, 5);
    std::cout << "Rectangle area : " << rec.area() << '\n';
    std::cout << "Triangle area : " << trgl.area() << '\n';
    std::cout << "===\n\n";

    /*
    Inheritance and base class constructor
    --------------------------------------
    */
    std::cout << "===\n";
    std::cout << "Inheritance and base class constructor example.\n";
    std::cout << "---\n";
    Daughter kelly(0);
    Son bud(0);
    std::cout << "===\n\n";

    /*
    Multiple Inheritance
    --------------------
    */
    std::cout << "===\n";
    std::cout << "Multiple inheritance example.\n";
    std::cout << "---\n";
    MultipleInheritanceRectangle recta(4.5, 5);
    MultipleInheritanceTriangle trgle(4.5, 5);
    recta.print(recta.area());
    MultipleInheritanceTriangle::print(trgle.area());
    std::cout << "===\n\n";

    /*
    Polymorphism
    ============
    Pointers to base class
    ----------------------
    One of the key features of class inheritance is that a pointer to a derived class is type-compatible with a pointer to its base class.
    Polymorphism is the art of taking advantage of this simple but powerful and versatile feature.

    Function main declares two pointers to Polygon (named ppoly1 and ppoly2). These are assigned the addresses of rect and trgl, respectively,
    which are objects of type Rectangle and Triangle. Such assignments are valid, since both Rectangle and Triangle are classes derived from Polygon.

    Dereferencing ppoly1 and ppoly2 (with ppoly1-> and ppoly2->) is valid and allows us to access the members of their pointed objects.
    For example, the following two statements would be equivalent in the below example:
     - ppoly1->set_values (4,5);
     - rect.set_values (4,5);

    But because the type of both ppoly1 and ppoly2 is pointer to Polygon (and not pointer to Rectangle nor pointer to Triangle),
    only the members inherited from Polygon can be accessed, and not those of the derived classes Rectangle and Triangle.
    That is why the program above accesses the area members of both objects using rect and trgl directly, instead of the pointers;
    the pointers to the base class cannot access the area members.

    Member area could have been accessed with the pointers to Polygon if area were a member of Polygon instead of a member of its derived classes,
    but the problem is that Rectangle and Triangle implement different versions of area, therefore there is not a single common version that
    could be implemented in the base class.
    */
    std::cout << "===\n";
    std::cout << "Polymorphism -  Pointers to base class example.\n";
    std::cout << "---\n";
    DerivedRectangle d_rect;
    DerivedTriangle d_trgl;
    BasePolygon *ppoly1 = &d_rect;
    BasePolygon *ppoly2 = &d_trgl;
    // BasePolygon *ppoly1, *ppoly2;
    // ppoly1 = &d_rect;
    // ppoly2 = &d_trgl;
    ppoly1->set_values(4.2, 5.1);
    ppoly2->set_values(4.4, 5.3);
    std::cout << d_rect.area() << '\n';
    std::cout << d_trgl.area() << '\n';
    std::cout << "===\n\n";

    /*
    Virtual Members
    ---------------
    */
    std::cout << "===\n";
    std::cout << "Polymorphism -  Virtual members.\n";
    std::cout << "---\n";
    VirtualRectangle v_rect;
    VirtualTriangle v_trgl;
    VirtualPolygon v_poly;
    VirtualPolygon *v_ppoly1 = &v_rect;
    VirtualPolygon *v_ppoly2 = &v_trgl;
    VirtualPolygon *v_ppoly3 = &v_poly;
    v_ppoly1->set_values(4, 5);
    v_ppoly2->set_values(4, 5);
    v_ppoly3->set_values(4, 5);
    std::cout << v_ppoly1->area() << '\n';
    std::cout << v_ppoly2->area() << '\n';
    std::cout << v_ppoly3->area() << '\n';
    std::cout << "===\n\n";

    /*
    Abstract Classes - 1
    --------------------
    */
    std::cout << "===\n";
    std::cout << "Polymorphism -  Abstract classes.\n";
    std::cout << "---\n";
    AbstractRectangle a_rect;
    AbstractTriangle a_trgl;
    // Not allowed for abstract classes.
    // AbstractPolygon a_poly;
    AbstractPolygon *a_ppoly1 = &a_rect;
    AbstractPolygon *a_ppoly2 = &a_trgl;
    a_ppoly1->set_values(4, 5);
    a_ppoly2->set_values(4, 5);
    std::cout << a_ppoly1->area() << '\n';
    std::cout << a_ppoly2->area() << '\n';
    std::cout << "===\n\n";

    /*
    Abstract Base Classes - 2
    -------------------------
    */
    std::cout << "===\n";
    std::cout << "Polymorphism -  Abstract classes (Base class accessing virtual members of derived class using this pointer).\n";
    std::cout << "---\n";
    AbstractRectangle2 a2_rect;
    AbstractTriangle2 a2_trgl;
    AbstractPolygon2 *a2_ppoly1 = &a2_rect;
    AbstractPolygon2 *a2_ppoly2 = &a2_trgl;
    a2_ppoly1->set_values(4, 5);
    a2_ppoly2->set_values(4, 5);
    a2_ppoly1->printarea();
    a2_ppoly2->printarea();
    std::cout << "===\n\n";

    /*
    Abstract Base Classes - 3
    -------------------------
    */
    std::cout << "===\n";
    std::cout << "Polymorphism -  Abstract classes (Base class accessing virtual members of derived class using this pointer and using concepts such as dynamic memory, constructor initializers, etc).\n";
    std::cout << "---\n";
    // Notice that the a3_ppoly pointers:
    // are declared being of type "pointer to Polygon", but the objects allocated have been declared having the derived class type directly (Rectangle and Triangle).
    AbstractPolygon3 *a3_ppoly1 = new AbstractRectangle3(4.1, 5.1);
    AbstractPolygon3 *a3_ppoly2 = new AbstractTriangle3(4.2, 5.2);
    a3_ppoly1->printarea();
    a3_ppoly2->printarea();
    delete a3_ppoly1;
    delete a3_ppoly2;
    std::cout << "===\n\n";

    return 0;
}