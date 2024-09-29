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

/*
Source file inclusion (#include)
================================
This directive has been used assiduously in other sections of this tutorial. 
When the preprocessor finds an #include directive it replaces it by the entire content of the specified header or file. 
There are two ways to use #include:
 - #include <header>
 - #include "file" 

In the first case, a header is specified between angle-brackets <>. This is used to include headers provided by the implementation, 
such as the headers that compose the standard library (iostream, string,...). 
Whether the headers are actually files or exist in some other form is implementation-defined, but in any case they shall be properly included with this directive.

The syntax used in the second #include uses quotes, and includes a file. The file is searched for in an implementation-defined manner, 
which generally includes the current path. In the case that the file is not found, 
the compiler interprets the directive as a header inclusion, just as if the quotes ("") were replaced by angle-brackets (<>).
*/

/*
Pragma directive (#pragma)
==========================
This directive is used to specify diverse options to the compiler. These options are specific for the platform and the compiler you use. 
Consult the manual or the reference of your compiler for more information on the possible parameters that you can define with #pragma.

If the compiler does not support a specific argument for #pragma, it is ignored - no syntax error is generated.
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
