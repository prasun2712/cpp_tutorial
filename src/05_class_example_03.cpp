#include <iostream>

#include "class_helper.hpp"

int main()
{
    CVector foo(3, 1);
    CVector bar(5, 2);
    CVector result;
    /*
    The function operator+ of class CVector overloads the addition operator (+) for that type. Once declared, 
    this function can be called either implicitly using the operator, or explicitly using its functional name:
     - result = foo + bar;
     - result = foo.operator+ (bar);
    Both expressions are equivalent.

    The parameter expected for a member function overload for operations such as operator+ is naturally the operand to the right hand side of the operator. 
    This is common to all binary operators (those with an operand to its left and one operand to its right). 
    But operators can come in diverse forms. Here you have a table with a summary of the parameters needed for each of the different 
    operators than can be overloaded (please, replace @ by the operator in each case):

    Expression	        Operator	                                        Member function	            Non-member function
    -----------------------------------------------------------------------------------------------------------------------
    @a  	            + - * & ! ~ ++ --	                                A::operator@()	            operator@(A)
    a@	                ++ --	                                            A::operator@(int)	        operator@(A,int)
    a@b	                + - * / % ^ & | < > == != <= >= << >> && || ,	    A::operator@(B)	            operator@(A,B)
    a@b	                = += -= *= /= %= ^= &= |= <<= >>= []	            A::operator@(B)	            -
    a(b,c...)	        ()	                                                A::operator()(B,C...)	    -
    a->b                ->	                                                A::operator->()	            -
    (TYPE) a	        TYPE	                                            A::operator TYPE()	        -

    Where a is an object of class A, b is an object of class B and c is an object of class C. 
    TYPE is just any type (that operators overloads the conversion to type TYPE).
    */
    result = foo + bar;
    // result = foo.operator+ (bar);
    std::cout << "result.x is : " << result.x << ',' << " and result.y is : " << result.y << '\n';

    result = foo - bar;
    std::cout << "result.x is : " << result.x << ',' << " and result.y is : " << result.y << '\n';
    
    return 0;
}