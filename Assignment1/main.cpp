#include <iostream>
#include "MyString.h"
using namespace assignment1;
using namespace std;
int main()
{
    MyString s1("Hello");

    s1.PadLeft(2); // s1: "Hello"
    s1.PadLeft(8); // s1: "   Hello"

    MyString s2("World");
    s2.PadLeft(3, '-'); // s2: "World"
    s2.PadLeft(7, '-'); // s2: "--World"
    s1.Printf();
    s2.Printf();
    return 0;
}