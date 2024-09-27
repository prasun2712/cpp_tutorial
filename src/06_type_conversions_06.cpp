#include <iostream>
#include <typeinfo>
using namespace std;

/*
typeid allows to check the type of an expression:

 - typeid (expression)

This operator returns a reference to a constant object of type type_info that is defined in the standard header <typeinfo>. 
A value returned by typeid can be compared with another value returned by typeid using operators == and != or 
can serve to obtain a null-terminated character sequence representing the data type or class name by using its name() member.
*/
int main()
{
    int *a, b;
    a = 0;
    b = 0;
    if (typeid(a) != typeid(b))
    {
        cout << "a and b are of different types:\n";
        cout << "a is: " << typeid(a).name() << '\n';
        cout << "b is: " << typeid(b).name() << '\n';
    }
    return 0;
}