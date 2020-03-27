#include <cassert>
#include "DoublyLinkedList.h"
#include "Node.h"

using namespace lab10;

int main()
{
	DoublyLinkedList<int> list;
	list.Insert(std::make_unique<int>(1)); // 1
	list.Insert(std::make_unique<int>(2)); // 1 -> 2
	list.Insert(std::make_unique<int>(3)); // 1 -> 2 -> 3
	list.Insert(std::make_unique<int>(10), 0); // 1 -> 10 -> 2 -> 3
	list.Printf();
	return 0;
}