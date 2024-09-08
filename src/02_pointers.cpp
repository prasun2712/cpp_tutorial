#include <iostream>
using namespace std;

int main()
{
    // Example 1 - Pointers
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

    // Example 2 - Pointers and arrays
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

    // Example 3 - Pointers and const
    //==================================================================================================================================
    void increment_all(int *, int *);
    /*
    Pointers can be used to access a variable by its address, and this access may include modifying the value pointed.
    But it is also possible to declare pointers that can access the pointed value to read it, but not to modify it.
    For this, it is enough with qualifying the type pointed to by the pointer as const.

    And this is where a second dimension to constness is added to pointers: Pointers can also be themselves const.
    And this is specified by appending const to the pointed type (after the asterisk):
    int x;
            int *       p1 = &x;  // non-const pointer to non-const int
    const   int *       p2 = &x;  // non-const pointer to const int
            int * const p3 = &x;  // const pointer to non-const int
    const   int * const p4 = &x;  // const pointer to const int
    */
    void print_all(const int *, const int *);

    int digits[] = {10,
                    20,
                    30};
    increment_all(digits, digits + 3);
    print_all(digits, digits + 3);

    // Example 4 - Pointers to pointers
    //==================================================================================================================================
    char a;
    char *b;
    char **c;
    a = 'z';
    b = &a;
    c = &b;
    cout << "a " << a << " *b " << *b << " **c " << **c << endl;

    // Example 5 - void pointers
    //==================================================================================================================================
    /*
    The void type of pointer is a special type of pointer. In C++, void represents the absence of type.
    Therefore, void pointers are pointers that point to a value that has no type (and thus also an undetermined length and undetermined dereferencing properties).
    This gives void pointers a great flexibility, by being able to point to any data type, from an integer value or a float to a string of characters.
    In exchange, they have a great limitation: the data pointed to by them cannot be directly dereferenced
    (which is logical, since we have no type to dereference to), and for that reason,
    any address in a void pointer needs to be transformed into some other pointer type that points to a concrete data type before being dereferenced.
    One of its possible uses may be to pass generic parameters to a function.

    nullptr
    Do not confuse null pointers with void pointers! A null pointer is a value that any pointer can take to represent that it is pointing to "nowhere",
    while a void pointer is a type of pointer that can point to somewhere without a specific type.
    One refers to the value stored in the pointer, and the other to the type of data it points to.
    */
    void increase(void *, int);
    char d = 'x';
    int e = 1602;
    increase(&d, sizeof(d));
    increase(&e, sizeof(e));
    cout << d << ", " << e << '\n';

    // Example 6 - Pointers to functions
    //==================================================================================================================================
    /*
    C++ allows operations with pointers to functions. The typical use of this is for passing a function as an argument to another function.
    Pointers to functions are declared with the same syntax as a regular function declaration,
    except that the name of the function is enclosed between parentheses () and an asterisk (*) is inserted before the name:
    In the example below, minus is a pointer to a function that has two parameters of type int. It is directly initialized to point to the function subtraction.
    */
    int addition(int, int);
    int subtraction(int, int);
    int operation(int, int, int (*)(int, int));
    int m, n;
    int (*minus)(int, int) = subtraction;
    m = operation(7, 5, addition);
    n = operation(20, m, minus);
    cout << "n is : " << n << "\n";

    return 0;
}

void increment_all(int *start, int *stop)
{
    int *current = start;
    while (current != stop)
    {
        ++(*current); // increment value pointed
        ++current;    // increment pointer
    }
}

void print_all(const int *start, const int *stop)
{
    const int *current = start;
    while (current != stop)
    {
        // Error
        // ++(*current);
        cout << *current << '\n';
        ++current; // increment pointer
    }
}

void increase(void *data, int psize)
{
    if (psize == sizeof(char))
    {
        char *pchar;
        pchar = (char *)data;
        ++(*pchar);
    }
    else if (psize == sizeof(int))
    {
        int *pint;
        pint = (int *)data;
        ++(*pint);
    }
}

int addition(int a, int b)
{
    return (a + b);
}

int subtraction(int a, int b)
{
    return (a - b);
}

int operation(int x, int y, int (*functocall)(int, int))
{
    int g;
    g = (*functocall)(x, y);
    return (g);
}