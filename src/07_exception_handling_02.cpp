#include <iostream>
#include <exception>
using namespace std;

/*
The C++ Standard library provides a base class specifically designed to declare objects to be thrown as exceptions.
It is called std::exception and is defined in the <exception> header.
This class has a virtual member function called 'what' that returns a null-terminated character sequence (of type char *) and
that can be overwritten in derived classes to contain some sort of description of the exception.

We have placed a handler that catches exception objects by reference (notice the ampersand & after the type),
therefore this catches also classes derived from exception, like our myex object of type myexception.

All exceptions thrown by components of the C++ Standard library throw exceptions derived from this exception class. These are:
============================================================================
exception	        description                                             |
============================================================================
bad_alloc	        thrown by new on allocation failure                     |
bad_cast	        thrown by dynamic_cast when it fails in a dynamic cast  |
bad_exception	    thrown by certain dynamic exception specifiers          |
bad_typeid	        thrown by typeid                                        |
bad_function_call	thrown by empty function objects                        |
bad_weak_ptr	    thrown by shared_ptr when passed a bad weak_ptr         |
============================================================================

Also deriving from exception, header <exception> defines two generic exception types that can be inherited by custom exceptions to report errors:
====================================================================
exception	    description                                         |
====================================================================
logic_error	    error related to the internal logic of the program  |
runtime_error	error detected during runtime                       |
====================================================================

*/
class myexception : public exception
{
    virtual const char *what() const throw()
    {
        return "My exception happened";
    }
} myex;

int main()
{
    try
    {
        // throw bad_exception();
        throw myex;
    }
    catch (exception &e)
    {
        cout << e.what() << '\n';
    }
    return 0;
}