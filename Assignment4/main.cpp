#include "TreeNode.h"
#include "BinarySearchTree.h"
#include <assert.h>
using namespace assignment4;
int main()
{
	BinarySearchTree<int> tree;
	tree.Insert(std::make_unique<int>(50));
	tree.Insert(std::make_unique<int>(25));
	tree.Insert(std::make_unique<int>(75));
	tree.Insert(std::make_unique<int>(70));
	tree.Insert(std::make_unique<int>(85));
	tree.Insert(std::make_unique<int>(15));
	tree.Insert(std::make_unique<int>(30));
	tree.Insert(std::make_unique<int>(2));
	tree.Insert(std::make_unique<int>(18));
	tree.Insert(std::make_unique<int>(26));
	tree.Insert(std::make_unique<int>(32));
	//tree.Delete(85);
	//tree.Delete(70);
	tree.Delete(15);
	//tree.Search(32);
	tree.Search(18);

	return 0;

}