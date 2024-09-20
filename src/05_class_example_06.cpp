#include <iostream>
using namespace std;

#include "class_helper.hpp"

int main()
{
    // Default constructor.
    Example3 foo;
    Example3 bar("Example");
    cout << "bar's 3 content: " << bar.content() << '\n';

    // Destructor.
    Example4 foo_4;
    Example4 bar_4("Example");
    cout << "bar's 4 content: " << bar_4.content() << '\n';

    // Copy constructor.
    Example5 foo_5("Example");
    Example5 bar_5 = foo_5;
    cout << "bar's 5 content: " << bar_5.content() << '\n';
    return 0;
}