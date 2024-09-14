#include <iostream>
using namespace std;

#include "class_helper.hpp"

// template <class T>
// T sum(T a, T b)
// {
//     T result;
//     result = a + b;
//     return result;
// }

int main()
{
    int i = 5, j = 6, k;
    double f = 2.0, g = 0.5, h;
    k = sum<int>(i, j);
    h = sum<double>(f, g);
    /*
    It is possible to instead simply write:
     - k = sum (i,j);
     - h = sum (f,g);
    without the type enclosed in angle brackets. Naturally, for that, the type shall be unambiguous.
    If sum is called with arguments of different types, the compiler may not be able to deduce the type of T automatically.
    */
    cout << k << '\n';
    cout << h << '\n';

    if (are_equal(10, 10.1))
        cout << "x and y are equal\n";
    else
        cout << "x and y are not equal\n";

    // Non-type template arguments
    cout << fixed_multiply<int, 2>(10) << '\n';
    cout << fixed_multiply<int, 3>(10) << '\n';
    return 0;
}