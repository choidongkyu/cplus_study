#include <iostream>
#include "MyString.h"
using namespace assignment1;
using namespace std;
int main()
{
    MyString s1("Hello");
    MyString s2(" World");

    MyString s3 = s1 + s2; // s3�� "Hello World"�� �Ǹ�, s1�� s2�� ������ "Hello"�� " World"��
    return 0;
}