#include <iostream>
using namespace std;

/*
Conditional inclusions (#ifdef, #ifndef, #if, #endif, #else and #elif)
======================================================================
These directives allow to include or discard part of the code of a program if a certain condition is met.

#ifdef allows a section of a program to be compiled only if the macro that is specified as the parameter has been defined,
no matter which its value is. For example:
 - #ifdef TABLE_SIZE
 - int table[TABLE_SIZE];
 - #endif
In this case, the line of code int table[TABLE_SIZE]; is only compiled if TABLE_SIZE was previously defined with #define, independently of its value.
If it was not defined, that line will not be included in the program compilation.

#ifndef serves for the exact opposite: the code between #ifndef and #endif directives is only compiled if the specified identifier has not been previously defined.
For example:
 - #ifndef TABLE_SIZE
 - #define TABLE_SIZE 100
 - #endif
 - int table[TABLE_SIZE];
In this case, if when arriving at this piece of code, the TABLE_SIZE macro has not been defined yet, it would be defined to a value of 100.
If it already existed it would keep its previous value since the #define directive would not be executed.

The #if, #else and #elif (i.e., "else if") directives serve to specify some condition to be met in order for the portion of code they surround to be compiled.
The condition that follows #if or #elif can only evaluate constant expressions, including macro expressions. For example:
 - #if TABLE_SIZE>200
 - #undef TABLE_SIZE
 - #define TABLE_SIZE 200

 - #elif TABLE_SIZE<50
 - #undef TABLE_SIZE
 - #define TABLE_SIZE 50

 - #else
 - #undef TABLE_SIZE
 - #define TABLE_SIZE 100
 - #endif

 - int table[TABLE_SIZE];
Notice how the entire structure of #if, #elif and #else chained directives ends with #endif.

The behavior of #ifdef and #ifndef can also be achieved by using the special operators defined and !defined respectively in any #if or #elif directive:
 - #if defined ARRAY_SIZE
 - #define TABLE_SIZE ARRAY_SIZE
 - #elif !defined BUFFER_SIZE
 - #define TABLE_SIZE 128
 - #else
 - #define TABLE_SIZE BUFFER_SIZE
 - #endif
*/

int main()
{
#ifdef TABLE_SIZE
    int table[TABLE_SIZE];
#endif
#ifndef TABLE_SIZE
#define TABLE_SIZE 210
#endif
    int table[TABLE_SIZE];
    cout << "Table 1 size is : " << sizeof(table) / sizeof(int) << ".\n";

#if TABLE_SIZE > 200
#undef TABLE_SIZE
#define TABLE_SIZE 200

#elif TABLE_SIZE < 50
#undef TABLE_SIZE
#define TABLE_SIZE 50

#else
#undef TABLE_SIZE
#define TABLE_SIZE 100
#endif

    int table_1[TABLE_SIZE];
    cout << "Table 2 size is : " << sizeof(table_1) / sizeof(table_1[0]) << ".\n";

#if defined ARRAY_SIZE
#define TABLE_SIZE ARRAY_SIZE
#elif !defined BUFFER_SIZE
#undef TABLE_SIZE
#define TABLE_SIZE 128
#else
#define TABLE_SIZE BUFFER_SIZE
#endif

    int table_2[TABLE_SIZE];
    cout << "Table 3 size is : " << sizeof(table_2) / sizeof(table_2[0]) << ".\n";


}
