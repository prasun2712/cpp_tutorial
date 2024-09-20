#ifndef CLASS_HELPER
#define CLASS_HELPER

#include <math.h>
#include <iostream>

class Rectangle
{
  int width, height;

public:
  /*
  In order to avoid that, a class can include a special function called its constructor, which is automatically called whenever a new object of this class is created,
  allowing the class to initialize member variables or allocate storage.
  This constructor function is declared just like a regular member function, but with a name that matches the class name and without any return type; not even void.
  */
  /*
  Overloading Constructor - a constructor can also be overloaded with different versions taking different parameters:
  with a different number of parameters and/or parameters of different types. The compiler will automatically call the one whose parameters match the arguments:
  */
  Rectangle(int, int);
  Rectangle();
  int area();
};

/*
Uniform initialization.
*/
class Circle
{
  double radius;

public:
  Circle(double r);
  double circum();
  double area();
};

/*
Member initialization in constructors
*/
class Cylinder
{
  Circle base;
  double height;

public:
  Cylinder(double, double);
  double volume();
};

/*
Overloading operators
*/
class CVector
{
public:
  int x, y;
  CVector() {};
  CVector(int, int);
  CVector operator+(const CVector &);
};

/*
Notice that some operators may be overloaded in two forms: either as a member function or as a non-member function:
The first case has been used in the example above for operator+. But some operators can also be overloaded as non-member functions;
In this case, the operator function takes an object of the proper class as first argument.
*/
CVector operator-(const CVector &, const CVector &);

/*
Const member functions
The access to its data members from outside the class is restricted to read-only,
as if all its data members were const for those accessing them from outside the class.
Note though, that the constructor is still called and is allowed to initialize and modify these data members:
*/
class MyClass
{
public:
  int x;
  MyClass(int val) : x(val) {}

  int get();
  /*
  The member functions of a const object can only be called if they are themselves specified as const members; in the example above,
  member get (which is not specified as const) cannot be called from foo. To specify that a member is a const member,
  the const keyword shall follow the function prototype, after the closing parenthesis for its parameters:

  Note that const can be used to qualify the type returned by a member function. This const is not the same as the one which specifies a member as const.
  Both are independent and are located at different places in the function prototype:
   - int get() const {return x;}        // const member function
   - const int& get() {return x;}       // member function returning a const&
   - const int& get() const {return x;} // const member function returning a const&

  Member functions specified to be const cannot modify non-static data members nor call other non-const member functions.
  In essence, const members shall not modify the state of an object.

  const objects are limited to access only member functions marked as const, but non-const objects are not restricted and thus can access
  both const and non-const member functions alike.
  */
  // int get() const;
  const int &get() const;
};

void print(const MyClass &arg);

/*
Template Function and Classes
*/
template <class T>
T sum(T a, T b)
{
  T result;
  result = a + b;
  return result;
}

// Templates are a powerful and versatile feature. They can have multiple template parameters, and the function can still use regular non-templated types.
// For example:
template <class T, class U>
bool are_equal(T a, U b)
{
  return (a == b);
}

// Non-type template arguments - The template parameters can not only include types introduced by class or typename,
// but can also include expressions of a particular type:
// The second argument of the fixed_multiply function template is of type int. It just looks like a regular function parameter,
// and can actually be used just like one.
// But there exists a major difference: the value of template parameters is determined on compile-time to generate a different
// instantiation of the function fixed_multiply, and thus the value of that argument is never passed during runtime:
// The two calls to fixed_multiply in main essentially call two versions of the function: one that always multiplies by two,
// and one that always multiplies by three. For that same reason, the second template argument needs to be a constant expression (it cannot be passed a variable).
template <class T, int N>
T fixed_multiply(T val)
{
  return val * N;
}

// Class template
//----------------
// The class that we have defined below serves to store two elements of any valid type. For example,
// if we wanted to declare an object of this class to store two integer values of type int with the values 115 and 36 we would write:
//  - mypair<int> myobject (115, 36);

template <class T>
class mypair
{
  T a, b;

public:
  mypair(T first, T second)
  {
    a = first;
    b = second;
  }
  T getmax();
};

// Confused by so many T's? There are three T's in this declaration: The first one is the template parameter.
// The second T refers to the type returned by the function. And the third T (the one between angle brackets) is also a requirement:
// It specifies that this function's template parameter is also the class template parameter.
template <class T>
T mypair<T>::getmax()
{
  T retval;
  retval = a > b ? a : b;
  return retval;
}

// Template specialization
//-------------------------
// It is possible to define a different implementation for a template when a specific type is passed as template argument. This is called a template specialization.
// For example, let's suppose that we have a very simple class called mycontainer that can store one element of any type and
// that has just one member function called increase, which increases its value.
// But we find that when it stores an element of type char it would be more convenient to have a completely different implementation with a function member uppercase,
// so we decide to declare a class template specialization for that type:

// Class template:
template <class T>
class mycontainer
{
  T element;

public:
  mycontainer(T arg) { element = arg; }
  T increase() { return ++element; }
};

// Class template specialization:
//--------------------------------
// This is the syntax used for the class template specialization:
//  - template <> class mycontainer <char> { ... };
// First of all, notice that we precede the class name with template<> , including an empty parameter list.
// This is because all types are known and no template arguments are required for this specialization, but still,
// it is the specialization of a class template, and thus it requires to be noted as such.

// But more important than this prefix, is the <char> specialization parameter after the class template name.
// This specialization parameter itself identifies the type for which the template class is being specialized (char).

// Notice the differences between the generic class template and the specialization:
//  - template <class T> class mycontainer { ... };
//  - template <> class mycontainer <char> { ... };
// The first line is the generic template, and the second one is the specialization.

// When we declare specializations for a template class, we must also define all its members, even those identical to the generic template class,
// because there is no "inheritance" of members from the generic template to the specialization.

template <>
class mycontainer<char>
{
  char element;

public:
  mycontainer(char arg) { element = arg; }
  char uppercase()
  {
    if ((element >= 'a') && (element <= 'z'))
      element += 'A' - 'a';
    return element;
  }
};

/*
Default constructor
===================
The default constructor is the constructor called when objects of a class are declared, but are not initialized with any arguments.
When any constructor is explicitly declared in a class, no implicit default constructors is automatically provided.
*/

class Example3
{
  std::string data;

public:
  Example3(const std::string &str);
  Example3();
  const std::string &content() const;
};

/*
Destructor
==========
Destructors fulfill the opposite functionality of constructors: They are responsible for the necessary cleanup needed by a class when its lifetime ends.
The classes we have defined in previous chapters did not allocate any resource and thus did not really require any clean up.

But now, let's imagine that the class in the last example allocates dynamic memory to store the string it had as data member;
in this case, it would be very useful to have a function called automatically at the end of the object's life in charge of releasing this memory.
To do this, we use a destructor. A destructor is a member function very similar to a default constructor: it takes no arguments and returns nothing,
not even void. It also uses the class name as its own name, but preceded with a tilde sign (~):
*/

class Example4
{
  std::string *ptr;

public:
  // constructors:
  Example4();
  Example4(const std::string &);
  // destructor:
  ~Example4();
  // access content:
  const std::string &content() const;
};

/*
Copy constructor.
=================
When an object is passed a named object of its own type as argument, its copy constructor is invoked in order to construct a copy.
A copy constructor is a constructor whose first parameter is of type reference to the class itself (possibly const qualified) and
which can be invoked with a single argument of this type. For example, for a class MyClass, the copy constructor may have the following signature:

 - MyClass::MyClass (const MyClass&);

If a class has no custom copy nor move constructors (or assignments) defined, an implicit copy constructor is provided.
This copy constructor simply performs a copy of its own members. For example, for a class such as:
 - class MyClass {
     public:
       int a, b; string c;
   };

An implicit copy constructor is automatically defined. The definition assumed for this function performs a shallow copy, roughly equivalent to:
 - MyClass::MyClass(const MyClass& x) : a(x.a), b(x.b), c(x.c) {}

This default copy constructor may suit the needs of many classes. But shallow copies only copy the members of the class themselves,
and this is probably not what we expect for classes like class Example4 we defined above, because it contains pointers of which it handles its storage.
For that class, performing a shallow copy means that the pointer value is copied, but not the content itself;
This means that both objects (the copy and the original) would be sharing a single string object (they would both be pointing to the same object),
and at some point (on destruction) both objects would try to delete the same block of memory, probably causing the program to crash on runtime.
This can be solved by defining the custom copy constructor that performs a deep copy as shown in example below.

The deep copy performed by this copy constructor allocates storage for a new string, which is initialized to contain a copy of the original object.
In this way, both objects (copy and original) have distinct copies of the content stored in different locations.
*/
class Example5
{
public:
  std::string *ptr;
  Example5();
  Example5(const std::string &);
  ~Example5();
  // copy constructor:
  Example5(const Example5 &);
  // access content:
  const std::string &content() const;
  // copy assignment: As soon as you comment the overloaded operator=, because of shallow copy, Segmentation fault (core dumped) is received.
  Example5 &operator=(const Example5 &);
};

/*
Move constructor and assignment.
=================================
Similar to copying, moving also uses the value of an object to set the value to another object. But, unlike copying,
the content is actually transferred from one object (the source) to the other (the destination):
the source loses that content, which is taken over by the destination. This moving only happens when the source of the value is an unnamed object.

Unnamed objects are objects that are temporary in nature, and thus haven't even been given a name.
Typical examples of unnamed objects are return values of functions or type-casts.

Using the value of a temporary object such as these to initialize another object or to assign its value, does not really require a copy:
the object is never going to be used for anything else, and thus, its value can be moved into the destination object.
These cases trigger the move constructor and move assignments:

The move constructor is called when an object is initialized on construction using an unnamed temporary.
Likewise, the move assignment is called when an object is assigned the value of an unnamed temporary:
 - MyClass fn();            // function returning a MyClass object
 - MyClass foo;             // default constructor
 - MyClass bar = foo;       // copy constructor
 - MyClass baz = fn();      // move constructor
 - foo = bar;               // copy assignment
 - baz = MyClass();         // move assignment
Both the value returned by fn and the value constructed with MyClass are unnamed temporaries. In these cases, there is no need to make a copy,
because the unnamed object is very short-lived and can be acquired by the other object when this is a more efficient operation.

The move constructor and move assignment are members that take a parameter of type rvalue reference to the class itself:
 - MyClass (MyClass&&);             // move-constructor
 - MyClass& operator= (MyClass&&);  // move-assignment

An rvalue reference is specified by following the type with two ampersands (&&). As a parameter,
an rvalue reference matches arguments of temporaries of this type.

The concept of moving is most useful for objects that manage the storage they use, such as objects that allocate storage with new and delete.
In such objects, copying and moving are really different operations:
    - Copying from A to B means that new memory is allocated to B and then the entire content of A is copied to this new memory allocated for B.
    - Moving from A to B means that the memory already allocated to A is transferred to B without allocating any new storage.
      It involves simply copying the pointer.

Compilers already optimize many cases that formally require a move-construction call in what is known as Return Value Optimization. 
Most notably, when the value returned by a function is used to initialize an object. In these cases, the move constructor may actually never get called.

Note that even though rvalue references can be used for the type of any function parameter, it is seldom useful for uses other than the move constructor. 
Rvalue references are tricky, and unnecessary uses may be the source of errors quite difficult to track.
*/
class Example6
{
  std::string *ptr;

public:
  Example6(const std::string &str);
  ~Example6();
  // move constructor
  Example6(Example6 &&);
  // move assignment
  Example6 &operator=(Example6 &&);
  // access content:
  const std::string &content() const;
  // addition:
  Example6 operator+(const Example6 &);
};

#endif
