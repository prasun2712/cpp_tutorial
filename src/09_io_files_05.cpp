#include <iostream>
#include <fstream>
using namespace std;

/*
Binary files
============
For binary files, reading and writing data with the extraction and insertion operators (<< and >>) and functions like getline is not efficient,
since we do not need to format any data and data is likely not formatted in lines.

File streams include two member functions specifically designed to read and write binary data sequentially: write and read. 
The first one (write) is a member function of ostream (inherited by ofstream). And read is a member function of istream (inherited by ifstream).
Objects of class fstream have both. Their prototypes are:

 - write ( memory_block, size );
 - read ( memory_block, size );

Where memory_block is of type char* (pointer to char), and represents the address of an array of bytes where the read data elements are stored or 
from where the data elements to be written are taken. The size parameter is an integer value that specifies the number of characters to be read or 
written from/to the memory block.

In this example, the entire file is read and stored in a memory block. Let's examine how this is done:

First, the file is open with the ios::ate flag, which means that the get pointer will be positioned at the end of the file. 
This way, when we call to member tellg(), we will directly obtain the size of the file.

Once we have obtained the size of the file, we request the allocation of a memory block large enough to hold the entire file:
 - memblock = new char[size];

Right after that, we proceed to set the get position at the beginning of the file (remember that we opened the file with this pointer at the end), 
then we read the entire file, and finally close it:
 - file.seekg (0, ios::beg);
 - file.read (memblock, size);
 - file.close();

At this point we could operate with the data obtained from the file. But our program simply announces that the content of the file is in memory and then finishes.
*/

/*
Buffers and Synchronization
===========================
When we operate with file streams, these are associated to an internal buffer object of type streambuf.
This buffer object may represent a memory block that acts as an intermediary between the stream and the physical file.
For example, with an ofstream, each time the member function put (which writes a single character) is called, 
the character may be inserted in this intermediate buffer instead of being written directly to the physical file with which the stream is associated.

The operating system may also define other layers of buffering for reading and writing to files.

When the buffer is flushed, all the data contained in it is written to the physical medium (if it is an output stream).
This process is called synchronization and takes place under any of the following circumstances:

    * When the file is closed: before closing a file, all buffers that have not yet been flushed are synchronized and all pending data is 
      written or read to the physical medium.
    * When the buffer is full: Buffers have a certain size. When the buffer is full it is automatically synchronized.
    * Explicitly, with manipulators: When certain manipulators are used on streams, an explicit synchronization takes place.
      These manipulators are: flush and endl.
    * Explicitly, with member function sync(): Calling the stream's member function sync() causes an immediate synchronization.
      This function returns an int value equal to -1 if the stream has no associated buffer or in case of failure. 
      Otherwise (if the stream buffer was successfully synchronized) it returns 0.

*/
int main()
{
    streampos size;
    char *memblock;

    // ifstream file("../data/example01.txt", ios::in | ios::binary | ios::ate);
    ifstream file("../data/NotoSansShavian-Regular.bin", ios::in | ios::binary | ios::ate);
    if (file.is_open())
    {
        size = file.tellg();
        memblock = new char[size];
        file.seekg(0, ios::beg);
        file.read(memblock, size);
        file.close();

        cout << "The entire file content is in memory.\n";
        cout << "Size is : " << size << endl;

        delete[] memblock;
    }
    else
        cout << "Unable to open file.\n";
    return 0;
}