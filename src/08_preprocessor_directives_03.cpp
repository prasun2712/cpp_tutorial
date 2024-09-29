#include <iostream>
using namespace std;

/*
Line control (#line)
====================
When we compile a program and some error happens during the compiling process,
the compiler shows an error message with references to the name of the file where the error happened and a line number,
so it is easier to find the code generating the error.

When we compile a program and some error happens during the compiling process,
the compiler shows an error message with references to the name of the file where the error happened and a line number,
so it is easier to find the code generating the error.
 - #line number "filename"

Where number is the new line number that will be assigned to the next code line.
The line numbers of successive lines will be increased one by one from this point on.

"filename" is an optional parameter that allows to redefine the file name that will be shown. For example:
 - #line 20 "assigning variable"
 - int a?;
This code will generate an error that will be shown as error in file "assigning variable", line 20.
*/

/*
Error directive (#error)
========================
This directive aborts the compilation process when it is found, generating a compilation error that can be specified as its parameter:
 - #ifndef __cplusplus
 - #error A C++ compiler is required!
 - #endif

This example aborts the compilation process if the macro name __cplusplus is not defined (this macro name is defined by default in all C++ compilers).
*/

int main()
{
#line 29 "Assigning variable syntax error..."
    int a ? ;

#ifndef __cplusplus
#error A C++ compiler is required!
#endif

#ifndef forced_error
#error I created this error intentionally!!!!!!!
#endif

return 0;
}
