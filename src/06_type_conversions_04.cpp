#include <iostream>
#include <exception>
using namespace std;

/*
Dynamic Cast
============
dynamic_cast can only be used with pointers and references to classes (or with void*). 
Its purpose is to ensure that the result of the type conversion points to a valid complete object of the destination pointer type.

This naturally includes pointer upcast (converting from pointer-to-derived to pointer-to-base), in the same way as allowed as an implicit conversion.

But dynamic_cast can also downcast (convert from pointer-to-base to pointer-to-derived) polymorphic classes (those with virtual members) if -and 
only if- the pointed object is a valid complete object of the target type. For example:
*/
class Base
{
    virtual void dummy() {}
};
class Derived : public Base
{
    int a;
};

int main()
{
    try
    {
        Base *pba = new Derived;
        Base *pbb = new Base;
        Derived *pd;

        pd = dynamic_cast<Derived *>(pba);
        if (pd == 0)
            cout << "Null pointer on first type-cast.\n";

        pd = dynamic_cast<Derived *>(pbb);
        if (pd == 0)
            cout << "Null pointer on second type-cast.\n";
    }
    catch (exception &e)
    {
        cout << "Exception: " << e.what();
    }
    return 0;
}

/*
Compatibility note: This type of dynamic_cast requires Run-Time Type Information (RTTI) to keep track of dynamic types. 
Some compilers support this feature as an option which is disabled by default. 
This needs to be enabled for runtime type checking using dynamic_cast to work properly with these types.

The code above tries to perform two dynamic casts from pointer objects of type Base* (pba and pbb) to a pointer object of type Derived*,
but only the first one is successful. Notice their respective initializations:
 - Base * pba = new Derived;
 - Base * pbb = new Base;

Even though both are pointers of type Base*, pba actually points to an object of type Derived, while pbb points to an object of type Base. 
Therefore, when their respective type-casts are performed using dynamic_cast, pba is pointing to a full object of class Derived, 
whereas pbb is pointing to an object of class Base, which is an incomplete object of class Derived.

When dynamic_cast cannot cast a pointer because it is not a complete object of the required class -as in the second conversion in the previous example- 
it returns a null pointer to indicate the failure. If dynamic_cast is used to convert to a reference type and the conversion is not possible,
an exception of type bad_cast is thrown instead.

dynamic_cast can also perform the other implicit casts allowed on pointers: casting null pointers between pointers types (even between unrelated classes), 
and casting any pointer of any type to a void* pointer.
*/

/*
Static Cast
===========
static_cast can perform conversions between pointers to related classes, not only upcasts (from pointer-to-derived to pointer-to-base), 
but also downcasts (from pointer-to-base to pointer-to-derived). No checks are performed during runtime to guarantee that 
the object being converted is in fact a full object of the destination type. Therefore, it is up to the programmer to ensure that the conversion is safe. 
On the other side, it does not incur the overhead of the type-safety checks of dynamic_cast.
 - class Base {};
 - class Derived: public Base {};
 - Base * a = new Base;
 - Derived * b = static_cast<Derived*>(a);

This would be valid code, although b would point to an incomplete object of the class and could lead to runtime errors if dereferenced.

Therefore, static_cast is able to perform with pointers to classes not only the conversions allowed implicitly, but also their opposite conversions.

static_cast is also able to perform all conversions allowed implicitly (not only those with pointers to classes), 
and is also able to perform the opposite of these. It can:
 * Convert from void* to any pointer type. In this case, it guarantees that if the void* value was obtained by converting from that same pointer type, 
 the resulting pointer value is the same.
 * Convert integers, floating-point values and enum types to enum types.

Additionally, static_cast can also perform the following:
 * Explicitly call a single-argument constructor or a conversion operator.
 * Convert to rvalue references.
 * Convert enum class values into integers or floating-point values.
 * Convert any type to void, evaluating and discarding the value.
*/

/*
Reinterpret Cast
================
reinterpret_cast converts any pointer type to any other pointer type, even of unrelated classes. 
The operation result is a simple binary copy of the value from one pointer to the other. 
All pointer conversions are allowed: neither the content pointed nor the pointer type itself is checked.

It can also cast pointers to or from integer types. The format in which this integer value represents a pointer is platform-specific. 
The only guarantee is that a pointer cast to an integer type large enough to fully contain it (such as intptr_t), 
is guaranteed to be able to be cast back to a valid pointer.

The conversions that can be performed by reinterpret_cast but not by static_cast are low-level operations based on reinterpreting the binary 
representations of the types, which on most cases results in code which is system-specific, and thus non-portable. For example:
 - class A { Code };
 - class B { Code };
 - A * a = new A;
 - B * b = reinterpret_cast<B*>(a);

This code compiles, although it does not make much sense, since now b points to an object of a totally unrelated and likely incompatible class. 
Dereferencing b is unsafe.
*/