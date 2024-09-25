#include <iostream>
using namespace std;

/*
On a function call, C++ allows one implicit conversion to happen for each argument. This may be somewhat problematic for classes, 
because it is not always what is intended. For example, if we add the following function to the last example:
 - void fn (B arg) {}

This function takes an argument of type B, but it could as well be called with an object of type A as argument:
 - fn (foo);

This may or may not be what was intended. But, in any case, it can be prevented by marking the affected constructor with the explicit keyword:
*/
class A
{
};

class B
{
public:
    explicit B(const A &x) {cout << "Explicit conversion.\n";}
    B &operator=(const A &x) {cout << "Assignment conversion.\n";return *this; }
    operator A() {cout << "Type cast operator.\n";return A(); }
};

void fn(B x) {}

int main()
{
    A foo;

    // Additionally, constructors marked with explicit cannot be called with the assignment-like syntax; 
    // In the above example, bar could not have been constructed with:
    //  - B bar = foo;
    // Type-cast member functions (those described in the previous section) can also be specified as explicit. 
    // This prevents implicit conversions in the same way as explicit-specified constructors do for the destination type.
    B bar(foo);
    bar = foo;
    foo = bar;

    // fn(foo);  // not allowed for explicit constuctor.
    fn(bar);

    return 0;
}