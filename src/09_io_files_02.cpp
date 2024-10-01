#include <iostream>
#include <fstream>
using namespace std;

/*
Text Files
==========
Text file streams are those where the ios::binary flag is not included in their opening mode. 
These files are designed to store text and thus all values that are input or output from/to them can suffer some formatting transformations, 
which do not necessarily correspond to their literal binary value.

Writing operations on text files are performed in the same way we operated with cout:
*/
int main()
{
    ofstream myfile("../data/example01.txt");
    if (myfile.is_open())
    {
        myfile << "This is a line.\n";
        myfile << "This is another line.\n";
        myfile.close();
    }
    else
        cout << "Unable to open file";
    return 0;
}