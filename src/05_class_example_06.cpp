#include <iostream>
using namespace std;

#include "class_helper.hpp"

int main()
{
    // Default constructor.
    Example3 foo;
    Example3 bar("Example");
    cout << "bar's content: " << bar.content() << '\n';
    return 0;
}