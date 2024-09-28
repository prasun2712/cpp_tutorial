#include <iostream>
#include <exception>
using namespace std;

// Example where standard exceptions need to be checked for is on memory allocation.
int main () {
  try
  {
    // Memory successfully allocated.
    //-------------------------------
    // int* myarray= new int[10000];

    // bad_alloc exception.
    //---------------------
    int* myarray= new int[10000000000];
  }
  catch (exception& e)
  {
    cout << "Standard exception: " << e.what() << endl;
  }
  return 0;
}


//=======
// ToDo
//=======
// double myfunction(char param) throw(int)
// {
//     cout << "Function received : " << param << "\n";
//     if (param == 'a')
//         return 0.1;
//     else if (param == 'A')
//     {
//         throw 1;
//     }
//     else
//     {
//         throw 'qq';
//     }
// }

// int main()
// {
//     char a;
//     cout << "Enter :\n";
//     cout << "1) 'a' for running function properly.\n";
//     cout << "2) 'A' throwing integer exception.\n";
//     cout << "3) Anything for throwing char exception.\n";
//     cin >> a;
//     try
//     {
//         myfunction(a);
//         return 0;
//     }
//     catch (int &i)
//     {
//         cout << "Received exception : " << i << "\n";
//         return EXIT_SUCCESS;
//     }
//     catch (char &ex)
//     {
//         std::cerr << "Error: unknown exception" << ex << std::endl;
//         return EXIT_FAILURE;
//     }
// }