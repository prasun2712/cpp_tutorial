#include <iostream>
#include <new>
using namespace std;

/*
Dynamic memory is allocated using operator new. new is followed by a data type specifier and, if a sequence of more than one element is required, 
the number of these within brackets []. It returns a pointer to the beginning of the new block of memory allocated. Its syntax is:

pointer = new type
pointer = new type [number_of_elements]

For deletion.
delete pointer;
delete[] pointer;

There is a substantial difference between declaring a normal array and allocating dynamic memory for a block of memory using new. 
The most important difference is that the size of a regular array needs to be a constant expression, 
and thus its size has to be determined at the moment of designing the program, before it is run, 
whereas the dynamic memory allocation performed by new allows to assign memory during runtime using any variable value as size.

The dynamic memory requested by our program is allocated by the system from the memory heap. However, computer memory is a limited resource, 
and it can be exhausted. Therefore, there are no guarantees that all requests to allocate memory using operator new are going to be granted by the system. 

*/

int main()
{
    long long int i, n;
    int *p;
    cout << "How many numbers would you like to type? ";
    cin >> i;

    // Method 1
    //=======================================================================================================================
    /*
    The method is known as nothrow, and what happens when it is used is that when a memory allocation fails,
    instead of throwing a bad_alloc exception or terminating the program, the pointer returned by new is a null pointer,
    and the program continues its execution normally.
    */
    // p = new (nothrow) int[i];
    // if (p == nullptr)
    //     cout << "Error: memory could not be allocated";
    // else
    // {
    //     for (n = 0; n < i; n++)
    //     {
    //         cout << "Enter number: ";
    //         cin >> p[n];
    //     }
    //     cout << "You have entered: ";
    //     for (n = 0; n < i; n++)
    //         cout << p[n] << ", ";
    //     delete[] p;
    // }


    // Method 2
    //======================================================================================================================
    try
    {
        p = new (nothrow) int[i];
        // throw runtime_error("Can not allocate memory.");
        for (n = 0; n < i; n++)
        {
            cout << "Enter number: ";
            cin >> p[n];
        }
        cout << "You have entered: ";
        for (n = 0; n < i; n++)
            cout << p[n] << ", ";
        delete[] p;
    }
    catch (exception &e)
    {
        cout << "Exception " << e.what() << endl;
    }

    return 0;
}