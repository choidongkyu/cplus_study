#include <iostream>
#include <cassert>
#include <string>
#include "MyString.h"
using namespace assignment1;
using namespace std;
int main()
{
	MyString removeTest("Hello");
	bool b1 = removeTest.RemoveAt(0); // s�� "ello", b1�� true
	std::cout << "Hello�� ù���� ����� : " << removeTest.GetCString() << ", �������� : " << b1 << std::endl;
	assert(strcmp(removeTest.GetCString(), "ello") == 0);
	assert(b1 == true);

	bool b2 = removeTest.RemoveAt(3); // s�� "ell", b2�� true
	std::cout << "ello�� �׹�° ���� ����� : " << removeTest.GetCString() << ", �������� : " << b2 << std::endl;
	assert(strcmp(removeTest.GetCString(), "ell") == 0);
	assert(b2 == true);

	bool b3 = removeTest.RemoveAt(4); // s�� "ell", b3�� false
	std::cout << "ell�� �ټ���° ���� ����� : " << removeTest.GetCString() << ", �������� : " << b3 << std::endl;
	assert(strcmp(removeTest.GetCString(), "ell") == 0);
	assert(b3 == false);


    return 0;
}