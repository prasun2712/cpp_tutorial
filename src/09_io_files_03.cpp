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

int main()
{
    string line;
    ifstream myfile("../data/example01.txt");
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            cout << line << '\n';
        }
        myfile.close();
    }

    else
        cout << "Unable to open file";

    return 0;
}