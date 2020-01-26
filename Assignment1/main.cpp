#include <iostream>
#include <cassert>
#include <string>
#include "MyString.h"
using namespace assignment1;
using namespace std;
int main()
{
    /* GetLength() Ex */
    MyString s1("Hello");
    assert(s1.GetLength() == 5);

    /* GetCString() Ex */
    MyString s2("Hello");
    assert(s2 == MyString("Hello"));

    /* Append() Ex */
    MyString s3("Hello");
    s3.Append(" World");
    assert(s3 == MyString("Hello World"));

    /* operator+ Ex */
    MyString s41("Hello");
    MyString s42(" World");
    MyString s43 = s41 + s42;
    //s2 = s2 + s1;  ??? ??(?? ????? ???? ??)
    assert(s43 == MyString("Hello World"));

    /* IndexOf() Ex */
    MyString s5("Hello");
    assert(s5.IndexOf("ell") == 1);
    assert(s5.IndexOf("l") == 2);
    assert(s5.IndexOf("This") == -1);
    assert(s5.IndexOf("") == 0);
    assert(s5.IndexOf("lo") == 3);

    MyString s52("");
    assert(s52.IndexOf("") == 0);
    assert(s52.IndexOf("A") == -1);

    MyString s53("Hellello");
    MyString s54("Heloo");
    assert(s53.IndexOf("ell") == 1);
    assert(s54.IndexOf("ell") == -1);

    /* LastIndexOf() Ex */
    MyString s6("Hello");
    assert(s6.LastIndexOf("ell") == 1);
    assert(s6.LastIndexOf("l") == 3);
    assert(s6.LastIndexOf("This") == -1);
    assert(s6.LastIndexOf("") == 5);
    assert(s6.LastIndexOf("He") == 0);

    MyString s62("");
    assert(s62.LastIndexOf("") == 0);
    assert(s62.LastIndexOf("A") == -1);

    MyString s63("Hellello");
    MyString s64("Heloo");
    assert(s63.LastIndexOf("ell") == 4);
    assert(s64.LastIndexOf("ell") == -1);

    /* Interleave() Ex */
    MyString s7("Hello");
    s7.Interleave(" World");
    assert(s7 == MyString("H eWlolrold"));

    MyString s72("A");
    s72.Interleave("BCDEF");
    assert(s72 == MyString("ABCDEF"));

    MyString s73("bcdef");
    s73.Interleave("a");
    assert(s73 == MyString("bacdef"));

    /* RemoveAt() Ex */
    MyString s8("Hello");
    assert(s8.RemoveAt(0) == true);
    assert(s8 == MyString("ello"));
    assert(s8.RemoveAt(2) == true);
    assert(s8 == MyString("elo"));
    assert(s8.RemoveAt(4) == false);
    assert(s8 == MyString("elo"));

    MyString s82("");
    assert(s82.RemoveAt(0) == false);

    /* PadLeft() Ex */
    MyString s9("Hello");
    s9.PadLeft(2);  // "Hello"
    assert(s9 == MyString("Hello"));
    s9.PadLeft(8);  // "   Hello"
    assert(s9 == MyString("   Hello"));

    MyString s92("World");
    s92.PadLeft(3, '-');  // "World"
    assert(s92 == MyString("World"));
    s92.PadLeft(7, '-');  // "--World"
    assert(s92 == MyString("--World"));

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

    /* Reverse() Ex */
    MyString s11("Hello");
    s11.Reverse();  // olleH
    assert(s11 == MyString("olleH"));

    MyString s112("Banana");
    s112.Reverse();   // ananaB
    assert(s112 == MyString("ananaB"));

    MyString s113("A");
    s113.Reverse();   // A
    assert(s113 == MyString("A"));

    MyString s114("");
    s114.Reverse();   //
    assert(s114 == MyString(""));

    /* operator== Ex */
    MyString s121("Hello");
    MyString s122("Hello");
    MyString s123("World");
    MyString s124("Hello ");

    assert((s121 == s122) == true); // true
    assert((s121 == s123) == false);   // false
    assert((s121 == s124) == false);   // false

    /* ToLower() Ex */
    MyString s131("HEllo 123K");
    MyString s132("A To z");
    s131.ToLower();   // "hello 123k"
    assert(s131 == MyString("hello 123k"));

    s132.ToLower();   // "a to z"
    assert(s132 == MyString("a to z"));

    /* ToUpper() Ex */
    MyString s141("HEllo 123K");
    MyString s142("A To z");
    s141.ToUpper();   // "HELLO 123K"
    assert(s141 == MyString("HELLO 123K"));

    s142.ToUpper();   // "A TO Z"
    assert(s142 == MyString("A TO Z"));


    return 0;
}