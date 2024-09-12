#include <iostream>

#include "class_helper.hpp"

int main()
{
    CVector foo(3, 1);
    CVector bar(5, 2);
    CVector result;
    result = foo + bar;
    std::cout << "result.x is : " << result.x << ',' << " and result.y is : " << result.y << '\n';
    return 0;
}