#include <iostream>
using namespace std;

int main()
{
    // Example 1
    //==================================================================================================================================
    int firstvalue = 5, secondvalue = 15;
    int *p1, *p2;
    p1 = &firstvalue;  // p1 = address of firstvalue
    p2 = &secondvalue; // p2 = address of secondvalue
    *p1 = 10;          // value pointed to by p1 = 10
    *p2 = *p1;         // value pointed to by p2 = value pointed to by p1
    p1 = p2;           // p1 = p2 (value of pointer is copied)
    *p1 = 20;          // value pointed to by p1 = 20
    cout << "firstvalue is " << firstvalue << " and p1 " << *p1 << '\n';
    cout << "secondvalue is " << secondvalue << " and p2 " << *p2 << '\n';

    // Example 2
    //==================================================================================================================================
    int numbers[5];
    int *p;
    /*
    After that, p and numbers would be equivalent and would have very similar properties. 
    The main difference being that p can be assigned a different address, 
    whereas numbers can never be assigned anything, and will always represent the same block of 5 elements of type int. 
    Therefore, the following assignment would not be valid:
        numbers = p;
    */
    p = numbers;
    // numbers = p;
    *p = 10;
    p++;
    *p = 20;
    p = &numbers[2];
    *p = 30;
    p = numbers + 3;
    *p = 40;
    p = numbers;
    *(p + 4) = 50;
    for (int n = 0; n < 5; n++)
        if (n != 4)
            cout << numbers[n] << ", ";
        else
            cout << numbers[n] << "\n";
    return 0;
}