#include <iostream>
#include <unistd.h>
#include <fstream>
using namespace std;

/*
Input/output with files
=======================
C++ provides the following classes to perform output and input of characters to/from files:

    ofstream    : Stream class to write on files
    ifstream    : Stream class to read from files
    fstream     : Stream class to both read and write from/to files.


These classes are derived directly or indirectly from the classes istream and ostream. 
We have already used objects whose types were these classes: cin is an object of class istream and cout is an object of class ostream. 
Therefore, we have already been using classes that are related to our file streams. 
And in fact, we can use our file streams the same way we are already used to use cin and cout, 
with the only difference that we have to associate these streams with physical files. Let's see an example:
This code creates a file called example.txt and inserts a sentence into it in the same way we are used to do with cout, but using the file stream myfile instead.
*/
int main()
{
    ofstream myfile;
    // Path is relative to build folder.
    myfile.open("../data/example.txt");
    myfile << "Writing this to a file.\n";
    myfile.close();
    return 0;
}

/*
Open a file
===========
The first operation generally performed on an object of one of these classes is to associate it to a real file. This procedure is known as to open a file. 
An open file is represented within a program by a stream (i.e., an object of one of these classes; in the previous example, this was myfile) and 
any input or output operation performed on this stream object will be applied to the physical file associated to it.

In order to open a file with a stream object we use its member function open:
 - open (filename, mode);

Where filename is a string representing the name of the file to be opened, and mode is an optional parameter with a combination of the following flags:
=================================================================================================================================================
ios::           in	Open for input operations.
ios::out	    Open for output operations.
ios::binary	    Open in binary mode.
ios::ate	    Set the initial position at the end of the file.
                If this flag is not set, the initial position is the beginning of the file.
ios::app	    All output operations are performed at the end of the file, appending the content to the current content of the file.
ios::trunc	    If the file is opened for output operations and it already existed, its previous content is deleted and replaced by the new one.
=================================================================================================================================================

All these flags can be combined using the bitwise operator OR (|). 
For example, if we want to open the file example.bin in binary mode to add data we could do it by the following call to member function open:
 - ofstream myfile;
 - myfile.open ("example.bin", ios::out | ios::app | ios::binary);

Each of the open member functions of classes ofstream, ifstream and fstream has a default mode that is used if the file is opened without a second argument:
==================================
class	    default mode parameter
==================================
ofstream	ios::out
ifstream	ios::in
fstream	    ios::in | ios::out
==================================

For ifstream and ofstream classes, ios::in and ios::out are automatically and respectively assumed, 
even if a mode that does not include them is passed as second argument to the open member function (the flags are combined).

For fstream, the default value is only applied if the function is called without specifying any value for the mode parameter. 
If the function is called with any value in that parameter the default mode is overridden, not combined.

File streams opened in binary mode perform input and output operations independently of any format considerations. 
Non-binary files are known as text files, and some translations may occur due to formatting of some special characters (like newline and carriage return characters).

Since the first task that is performed on a file stream is generally to open a file, 
these three classes include a constructor that automatically calls the open member function and has the exact same parameters as this member.
Therefore, we could also have declared the previous myfile object and conduct the same opening operation in our previous example by writing:
 - ofstream myfile ("example.bin", ios::out | ios::app | ios::binary);

Combining object construction and stream opening in a single statement. Both forms to open a file are valid and equivalent.

To check if a file stream was successful opening a file, you can do it by calling to member is_open. 
This member function returns a bool value of true in the case that indeed the stream object is associated with an open file, or false otherwise:
 - if (myfile.is_open()) { ok, proceed with output. }
*/

/*
Closing a file
==============
When we are finished with our input and output operations on a file we shall close it so that the operating system is notified 
and its resources become available again. For that, we call the stream's member function close. 
This member function takes flushes the associated buffers and closes the file:
 - myfile.close();

Once this member function is called, the stream object can be re-used to open another file, and the file is available again to be opened by other processes.

In case that an object is destroyed while still associated with an open file, the destructor automatically calls the member function close.
*/