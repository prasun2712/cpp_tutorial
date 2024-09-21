#include <iostream>
using namespace std;

#include "class_helper.hpp"

int main()
{
    // // Default constructor.
    // //=====================
    // Example3 foo;
    // Example3 bar("Example");
    // cout << "bar's 3 content: " << bar.content() << '\n';

    // // Destructor.
    // //============
    // Example4 foo_4;
    // Example4 bar_4("Example");
    // cout << "bar's 4 content: " << bar_4.content() << '\n';

    // // Copy constructor.
    // //==================
    // Example5 foo_5("Example");
    // Example5 bar_5 = foo_5;
    // cout << "bar's 5 content: " << bar_5.content() << '\n';

    // Copy Assignment
    //================
    /*
    Objects are not only copied on construction, when they are initialized: They can also be copied on any assignment operation. See the difference:
     - MyClass foo;
     - MyClass bar (foo);       // object initialization: copy constructor called
     - MyClass baz = foo;       // object initialization: copy constructor called
     - foo = bar;               // object already initialized: copy assignment called
    Note that baz is initialized on construction using an equal sign, but this is not an assignment operation! (although it may look like one):
    The declaration of an object is not an assignment operation, it is just another of the syntaxes to call single-argument constructors.

    The assignment on foo is an assignment operation. No object is being declared here, but an operation is being performed on an existing object; foo.

    The copy assignment operator is an overload of operator= which takes a value or reference of the class itself as parameter.
    The return value is generally a reference to *this (although this is not required). For example, for a class MyClass,
    the copy assignment may have the following signature:
     - MyClass& operator= (const MyClass&);

    The copy assignment operator is also a special function and is also defined implicitly if a class has no custom copy nor move assignments
    (nor move constructor) defined.

    But again, the implicit version performs a shallow copy which is suitable for many classes,
    but not for classes with pointers to objects they handle its storage, as is the case in Example5.
    In this case, not only the class incurs the risk of deleting the pointed object twice,
    but the assignment creates memory leaks by not deleting the object pointed by the object before the assignment.
    These issues could be solved with a copy assignment that deletes the previous object and performs a deep copy:

     - Example5& operator= (const Example5& x)
     - {
     -  delete ptr;                      // delete currently pointed string
     -  ptr = new string (x.content());  // allocate space for new string, and copy
     -  return *this;
     - }
    Or even better, since its string member is not constant, it could re-utilize the same string object:

     - Example5& operator= (const Example5& x)
     - {
     -  *ptr = x.content();
     -  return *this;
     - }
    */
    // Example5 baz_5, faz_5;
    // baz_5 = faz_5;
    // *faz_5.ptr = "Sample";
    // cout << "baz's 5 content: " << baz_5.content() << '\n';

    // // Move constructor and assignment.
    // //=================================
    // Example6 foo_6("Exam");
    // Example6 bar_6 = Example6("ple"); // move-construction
    // // Example6 bar_6(Example6("ple"));  // move-construction
    // foo_6 = foo_6 + bar_6; // move-assignment
    // cout << "foo's content: " << foo_6.content() << '\n';

    // Implicit members.
    //==================
    Rect foo_7;
    Rect bar_7(10, 20);
    /*
    Here, Rectangle can be constructed either with two int arguments or be default-constructed (with no arguments).
    It cannot however be copy-constructed from another Rectangle object, because this function has been deleted.
    Therefore, assuming the objects of the last example, the following statement would not be valid:
     - Rect baz_7(bar_7);
    It could, however, be made explicitly valid by defining its copy constructor as:
     - Rect::Rect (const Rect& other) = default;
    Which would be essentially equivalent to:
     - Rect::Rect (const Rect& other) : width(other.width), height(other.height) {}
    Note that, the keyword default does not define a member function equal to the default constructor (i.e., where default constructor means 
    constructor with no parameters), but equal to the constructor that would be implicitly defined if not deleted.

    In general, and for future compatibility, classes that explicitly define one copy/move constructor or one copy/move assignment but not both, 
    are encouraged to specify either delete or default on the other special member functions they don't explicitly define.
    */
    cout << "bar_7's area: " << bar_7.area() << '\n';

    return 0;
}