#include <iostream>
using namespace std;

/*
Const Cast
==========
This type of casting manipulates the constness of the object pointed by a pointer, either to be set or to be removed.
For example, in order to pass a const pointer to a function that expects a non-const argument:
*/
void print(char *str)
{
    cout << str << '\n';
}

int main()
{
    const char *c = "sample text";
    print(const_cast<char *>(c));
    /*
    The example above is guaranteed to work because function print does not write to the pointed object.
    Note though, that removing the constness of a pointed object to actually write to it causes undefined behavior.
    */
    return 0;
}