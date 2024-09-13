#include <iostream>

#include "class_helper.hpp"
using namespace std;

class Dummy
{
public:
    bool isitme(Dummy &param);
    /*
    A static data member (either data or functions) of a class is also known as a "class variable",
    because there is only one common variable for all the objects of that same class,
    sharing the same value: i.e., its value is not different from one object of this class to another.

    Classes can also have static member functions. These represent the same: members of a class that are common to all object of that class,
    acting exactly as non-member functions but being accessed like members of the class. Because they are like non-member functions,
    they cannot access non-static members of the class (neither member variables nor member functions). They neither can use the keyword this.
    */
    static int n;
};

/*
In fact, static members have the same properties as non-member variables but they enjoy class scope.
For that reason, and to avoid them to be declared several times, they cannot be initialized directly in the class,
but need to be initialized somewhere outside it.
*/
int Dummy::n = 5;

bool Dummy::isitme(Dummy &param)
{
    /*
    The keyword this represents a pointer to the object whose member function is being executed.
    It is used within a class's member function to refer to the object itself.
    */
    if (&param == this)
        return true;
    else
        return false;
}

int main()
{
    Dummy a;
    Dummy *b = &a;
    if (b->isitme(a))
        cout << "yes, &a is b\n";

    /*
    Because it is a common variable value for all the objects of the same class,
    it can be referred to as a member of any object of that class or even directly by the class name
    Both statements below are same.
    */
    cout << a.n << '\n';
    cout << Dummy::n << '\n';

    /*
    Const member functions
    */
    const MyClass foo(10);
    // foo.x = 20;              // not valid: x cannot be modified
    cout << foo.x << '\n'; // ok: data member x can be read

    /*
    The statement below can now be called as get is overloaded as a const member function of class.
    */
    cout << foo.get() << '\n';

    MyClass boo(100);
    print(boo);
    boo.get();

    return 0;
}