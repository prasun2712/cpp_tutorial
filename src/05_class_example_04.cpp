#include <iostream>
using namespace std;

class Dummy
{
public:
    bool isitme(Dummy &param);
};

bool Dummy::isitme(Dummy &param)
{
    /* 
    The keyword this represents a pointer to the object whose member function is being executed. 
    It is used within a class's member function to refer to the object itself.
    */
    if (&param == this)
        return true;
    else
        return false;
}

int main()
{
    Dummy a;
    Dummy *b = &a;
    if (b->isitme(a))
        cout << "yes, &a is b\n";
    return 0;
}