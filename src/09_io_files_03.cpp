#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
Text files
==========
Reading from a file can also be performed in the same way that we did with cin.

This example reads a text file and prints out its content on the screen. We have created a while loop that reads the file line by line, using getline.
The value returned by getline is a reference to the stream object itself,
which when evaluated as a boolean expression (as in this while-loop) is true if the stream is ready for more operations,
and false if either the end of the file has been reached or if some other error occurred.
*/

/*
Checking state flags
====================
The following member functions exist to check for specific states of a stream (all of them return a bool value):

bad()
    Returns true if a reading or writing operation fails. For example, in the case that we try to write to a file that is not open for writing 
    or if the device where we try to write has no space left.
fail()
    Returns true in the same cases as bad(), but also in the case that a format error happens, 
    like when an alphabetical character is extracted when we are trying to read an integer number.
eof()
    Returns true if a file open for reading has reached the end.
good()
    It is the most generic state flag: it returns false in the same cases in which calling any of the previous functions would return true. 
    Note that good and bad are not exact opposites (good checks more state flags at once).

The member function clear() can be used to reset the state flags.
*/

int main()
{
    string line;
    ifstream myfile("../data/example01.txt");
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            cout << line << '\n';
            cout << "File reading has reached the end of stream : " << myfile.eof() << endl;
        }
        cout << "File reading has reached the end of stream : " << myfile.eof() << endl;
        myfile.close();
    }

    else
        cout << "Unable to open file";

    return 0;
}