#include <iostream>
#include "MyString.h"
using namespace assignment1;
using namespace std;
int main()
{
    MyString s1("Hello");
    MyString s2(" World");

    MyString s3 = s1 + s2; // s3는 "Hello World"가 되며, s1와 s2는 여전히 "Hello"와 " World"임
    return 0;
}