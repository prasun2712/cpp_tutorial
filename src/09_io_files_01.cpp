#include <iostream>
#include <unistd.h>
#include <fstream>
using namespace std;

/*
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