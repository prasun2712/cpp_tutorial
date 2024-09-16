#include <iostream>
using namespace std;

#include "class_helper.hpp"

int main()
{
    // Default constructor.
    Example3 foo;
    Example3 bar("Example");
    cout << "bar's content: " << bar.content() << '\n';

    // Destructor.
    Example4 foo_4;
    Example4 bar_4("Example");
    cout << "bar's content: " << bar_4.content() << '\n';
    return 0;
}