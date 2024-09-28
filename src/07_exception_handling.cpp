#include <iostream>
using namespace std;

/*
Exceptions provide a way to react to exceptional circumstances (like runtime errors) in programs by transferring control to special functions called handlers.

To catch exceptions, a portion of code is placed under exception inspection. This is done by enclosing that portion of code in a try-block.
When an exceptional circumstance arises within that block, an exception is thrown that transfers the control to the exception handler.
If no exception is thrown, the code continues normally and all handlers are ignored.

An exception is thrown by using the throw keyword from inside the try block. Exception handlers are declared with the keyword catch,
which must be placed immediately after the try block:

The code under exception handling is enclosed in a try block. In this example this code simply throws an exception:
 - throw 20;
A throw expression accepts one parameter (in this case the integer value 20), which is passed as an argument to the exception handler.

The exception handler is declared with the catch keyword immediately after the closing brace of the try block.
The syntax for catch is similar to a regular function with one parameter. The type of this parameter is very important,
since the type of the argument passed by the throw expression is checked against it, and only in the case they match, the exception is caught by that handler.

Multiple handlers (i.e., catch expressions) can be chained; each one with a different parameter type.
Only the handler whose argument type matches the type of the exception specified in the throw statement is executed.

If an ellipsis (...) is used as the parameter of catch, that handler will catch any exception no matter what the type of the exception thrown.
This can be used as a default handler that catches all exceptions not caught by other handlers:
 - try {
 -   // code here
 - }
 - catch (int param) { cout << "int exception"; }
 - catch (char param) { cout << "char exception"; }
 - catch (...) { cout << "default exception"; }

In this case, the last handler would catch any exception thrown of a type that is neither int nor char.

After an exception has been handled the program, execution resumes after the try-catch block, not after the throw statement!.

It is also possible to nest try-catch blocks within more external try blocks.
In these cases, we have the possibility that an internal catch block forwards the exception to its external level.
This is done with the expression throw; with no arguments. For example:
 - try {
 -   try {
 -       // code here
 -   }
 -   catch (int n) {
 -       throw;
 -   }
 - }
 - catch (...) {
 -   cout << "Exception occurred";
 - }
*/
int main()
{
    try
    {
        try
        {
            cout << "Enter 1 for integer exception and anything else for other exception - ";
            int a;
            cin >> a;
            if (a == 1)
                throw 20;
            else
                throw "a";
        }
        catch (int e)
        {
            cout << "An exception occurred. Exception Nr. " << e << '\n';
        }
    }
    catch (...)
    {
        cout << "General exception occurred\n";
    }
    return 0;
}