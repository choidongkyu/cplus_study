#include <iostream>
#include <cassert>
#include <string>
#include "MyString.h"
using namespace assignment1;
using namespace std;
int main()
{
    /* PadRight() Ex */
    MyString s10("Hello");
    s10.PadRight(2);  // "Hello"
    assert(s10 == MyString("Hello"));
    s10.PadRight(8);  // "Hello   "
    assert(s10 == MyString("Hello   "));
    

    MyString s102("World");
    s102.PadRight(3, '-');  // "World"
    assert(s102 == MyString("World"));
    s102.PadRight(7, '-');  // "World--"
    assert(s102 == MyString("World--"));

    return 0;
}