#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct movies_t
{
    string title;
    int year;
} mine, yours;

void printmovie(movies_t movie);

int main()
{
    string mystr;

    mine.title = "2001 A Space Odyssey";
    mine.year = 1968;

    cout << "Enter title: ";
    getline(cin, yours.title);
    cout << "Enter year: ";
    getline(cin, mystr);
    stringstream(mystr) >> yours.year;

    cout << "My favorite movie is:\n ";
    printmovie(mine);
    cout << "And yours is:\n ";
    printmovie(yours);

    // Pointers to structures
    //=====================================================================
    /*
    Expression	    What is evaluated	                        Equivalent
    a.b	            Member b of object a
    a->b	        Member b of object pointed to by a	        (*a).b
    *a.b	        Value pointed to by member b of object a    *(a.b)
    */

    movies_t amovie;
    
    // Correct way to use it.
    // movies_t *pmovie;
    // pmovie = &amovie;
    // cout << "Enter title: ";
    // getline(cin, pmovie->title);
    // cout << "Enter year: ";
    // getline(cin, mystr);
    // (stringstream) mystr >> pmovie->year;

    movies_t *pmovie = new movies_t;
    cout << "Enter title: ";
    getline(cin, amovie.title);
    cout << "Enter year: ";
    getline(cin, mystr);
    (stringstream) mystr >> amovie.year;
    *pmovie = amovie;



    cout << "\nYou have entered:\n";
    cout << pmovie->title;
    cout << " (" << pmovie->year << ")\n";
    delete pmovie;

    return 0;
}

void printmovie(movies_t movie)
{
    cout << movie.title;
    cout << " (" << movie.year << ")\n";
}