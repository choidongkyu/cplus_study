#include <cassert>
#include "TreeNode.h"
#include "BinarySearchTree.h"

using namespace assignment4;

int main()
{
    bool bDelete = false;
    bool bSearch = false;
    BinarySearchTree<int> tree;
    std::vector<int> traverseResult;

    bDelete = tree.Delete(15);
    bSearch = tree.Search(15);
    traverseResult = tree.TraverseInOrder(tree.GetRootNode().lock());
    assert(!bDelete);
    assert(!bSearch);
    assert(traverseResult.empty());

    tree.Insert(std::make_unique<int>(15));
    traverseResult = tree.TraverseInOrder(tree.GetRootNode().lock());
    bDelete = tree.Delete(15);
    assert(bDelete);
    assert(traverseResult.size() == 1);
    assert(traverseResult[0] == 15);
    assert(tree.GetRootNode().lock() == nullptr);

    BinarySearchTree<int> tree1;
    tree1.Insert(std::make_unique<int>(10));
    tree1.Insert(std::make_unique<int>(5));
    tree1.Insert(std::make_unique<int>(15));
    bDelete = tree1.Delete(10);
    assert(bDelete);
    traverseResult = tree1.TraverseInOrder(tree1.GetRootNode().lock());
    assert(traverseResult[0] == 5);
    assert(traverseResult[1] == 15);

    BinarySearchTree<int> tree2;
    tree2.Insert(std::make_unique<int>(10));
    tree2.Insert(std::make_unique<int>(5));
    tree2.Insert(std::make_unique<int>(15));
    tree2.Insert(std::make_unique<int>(13));
    tree2.Insert(std::make_unique<int>(20));
    bDelete = tree2.Delete(10);
    assert(bDelete);
    traverseResult = tree2.TraverseInOrder(tree2.GetRootNode().lock());
    assert(traverseResult[0] == 5);
    assert(traverseResult[1] == 13);
    assert(traverseResult[2] == 15);
    assert(traverseResult[3] == 20);

    BinarySearchTree<int> tree3;
    tree3.Insert(std::make_unique<int>(10));
    tree3.Insert(std::make_unique<int>(5));
    tree3.Insert(std::make_unique<int>(15));
    tree3.Insert(std::make_unique<int>(20));
    bDelete = tree3.Delete(10);
    assert(bDelete);
    traverseResult = tree3.TraverseInOrder(tree3.GetRootNode().lock());
    assert(traverseResult[0] == 5);
    assert(traverseResult[1] == 15);
    assert(traverseResult[2] == 20);

    BinarySearchTree<int> tree4;
    tree4.Insert(std::make_unique<int>(10));
    tree4.Insert(std::make_unique<int>(5));
    tree4.Insert(std::make_unique<int>(15));
    tree4.Insert(std::make_unique<int>(13));
    tree4.Insert(std::make_unique<int>(14));
    tree4.Insert(std::make_unique<int>(20));
    bDelete = tree4.Delete(10);
    assert(bDelete);
    traverseResult = tree4.TraverseInOrder(tree4.GetRootNode().lock());
    assert(traverseResult[0] == 5);
    assert(traverseResult[1] == 13);
    assert(traverseResult[2] == 14);
    assert(traverseResult[3] == 15);
    assert(traverseResult[4] == 20);

    BinarySearchTree<int> tree5;
    tree5.Insert(std::make_unique<int>(10));
    tree5.Insert(std::make_unique<int>(5));
    tree5.Insert(std::make_unique<int>(15));
    tree5.Insert(std::make_unique<int>(13));
    tree5.Insert(std::make_unique<int>(20));
    bDelete = tree5.Delete(15);
    assert(bDelete);
    traverseResult = tree5.TraverseInOrder(tree5.GetRootNode().lock());
    assert(traverseResult[0] == 5);
    assert(traverseResult[1] == 10);
    assert(traverseResult[2] == 13);
    assert(traverseResult[3] == 20);

    BinarySearchTree<int> tree6;
    tree6.Insert(std::make_unique<int>(10));
    tree6.Insert(std::make_unique<int>(5));
    tree6.Insert(std::make_unique<int>(15));
    tree6.Insert(std::make_unique<int>(1));
    tree6.Insert(std::make_unique<int>(2));
    bDelete = tree6.Delete(5);
    assert(bDelete);
    traverseResult = tree6.TraverseInOrder(tree6.GetRootNode().lock());
    assert(traverseResult[0] == 1);
    assert(traverseResult[1] == 2);
    assert(traverseResult[2] == 10);
    assert(traverseResult[3] == 15);


    BinarySearchTree<int> tree7;
    tree7.Insert(std::make_unique<int>(10));
    tree7.Insert(std::make_unique<int>(5));
    tree7.Insert(std::make_unique<int>(15));
    tree7.Insert(std::make_unique<int>(13));
    tree7.Insert(std::make_unique<int>(20));
    tree7.Insert(std::make_unique<int>(17));
    tree7.Insert(std::make_unique<int>(25));
    bDelete = tree7.Delete(15);
    assert(bDelete);
    traverseResult = tree7.TraverseInOrder(tree7.GetRootNode().lock());
    assert(traverseResult[0] == 5);
    assert(traverseResult[1] == 10);
    assert(traverseResult[2] == 13);
    assert(traverseResult[3] == 17);
    assert(traverseResult[4] == 20);
    assert(traverseResult[5] == 25);

    BinarySearchTree<int> tree8;
    tree8.Insert(std::make_unique<int>(15));
    tree8.Insert(std::make_unique<int>(10));
    tree8.Insert(std::make_unique<int>(20));
    tree8.Insert(std::make_unique<int>(5));
    tree8.Insert(std::make_unique<int>(13));
    tree8.Insert(std::make_unique<int>(12));
    tree8.Insert(std::make_unique<int>(14));
    bDelete = tree8.Delete(10);
    assert(bDelete);
    traverseResult = tree8.TraverseInOrder(tree8.GetRootNode().lock());
    assert(traverseResult[0] == 5);
    assert(traverseResult[1] == 12);
    assert(traverseResult[2] == 13);
    assert(traverseResult[3] == 14);
    assert(traverseResult[4] == 15);
    assert(traverseResult[5] == 20);

    BinarySearchTree<int> tree9;
    tree9.Insert(std::make_unique<int>(10));
    tree9.Insert(std::make_unique<int>(5));
    tree9.Insert(std::make_unique<int>(15));
    tree9.Insert(std::make_unique<int>(13));
    tree9.Insert(std::make_unique<int>(20));
    tree9.Insert(std::make_unique<int>(25));
    bDelete = tree9.Delete(15);
    assert(bDelete);
    traverseResult = tree9.TraverseInOrder(tree9.GetRootNode().lock());
    assert(traverseResult[0] == 5);
    assert(traverseResult[1] == 10);
    assert(traverseResult[2] == 13);
    assert(traverseResult[3] == 20);
    assert(traverseResult[4] == 25);

    BinarySearchTree<int> tree10;
    tree10.Insert(std::make_unique<int>(15));
    tree10.Insert(std::make_unique<int>(10));
    tree10.Insert(std::make_unique<int>(20));
    tree10.Insert(std::make_unique<int>(5));
    tree10.Insert(std::make_unique<int>(13));
    tree10.Insert(std::make_unique<int>(14));
    bDelete = tree10.Delete(10);
    assert(bDelete);
    traverseResult = tree10.TraverseInOrder(tree10.GetRootNode().lock());
    assert(traverseResult[0] == 5);
    assert(traverseResult[1] == 13);
    assert(traverseResult[2] == 14);
    assert(traverseResult[3] == 15);
    assert(traverseResult[4] == 20);

    BinarySearchTree<int> tree11;
    tree11.Insert(std::make_unique<int>(10));
    tree11.Insert(std::make_unique<int>(5));
    tree11.Insert(std::make_unique<int>(15));
    tree11.Insert(std::make_unique<int>(13));
    tree11.Insert(std::make_unique<int>(20));
    tree11.Insert(std::make_unique<int>(17));
    tree11.Insert(std::make_unique<int>(25));
    tree11.Insert(std::make_unique<int>(18));
    bDelete = tree11.Delete(15);
    assert(bDelete);
    traverseResult = tree11.TraverseInOrder(tree11.GetRootNode().lock());
    assert(traverseResult[0] == 5);
    assert(traverseResult[1] == 10);
    assert(traverseResult[2] == 13);
    assert(traverseResult[3] == 17);
    assert(traverseResult[4] == 18);
    assert(traverseResult[5] == 20);
    assert(traverseResult[6] == 25);

    bDelete = tree11.Delete(15);
    assert(!bDelete);

    bDelete = tree11.Delete(17);
    assert(bDelete);
    traverseResult = tree11.TraverseInOrder(tree11.GetRootNode().lock());
    assert(traverseResult[0] == 5);
    assert(traverseResult[1] == 10);
    assert(traverseResult[2] == 13);
    assert(traverseResult[3] == 18);
    assert(traverseResult[4] == 20);
    assert(traverseResult[5] == 25);

    bDelete = tree11.Delete(17);
    assert(!bDelete);

    bDelete = tree11.Delete(10);
    assert(bDelete);
    traverseResult = tree11.TraverseInOrder(tree11.GetRootNode().lock());
    assert(traverseResult[0] == 5);
    assert(traverseResult[1] == 13);
    assert(traverseResult[2] == 18);
    assert(traverseResult[3] == 20);
    assert(traverseResult[4] == 25);


    BinarySearchTree<int> tree12;
    tree12.Insert(std::make_unique<int>(15));
    tree12.Insert(std::make_unique<int>(7));
    tree12.Insert(std::make_unique<int>(20));
    tree12.Insert(std::make_unique<int>(5));
    tree12.Insert(std::make_unique<int>(11));
    tree12.Insert(std::make_unique<int>(9));
    tree12.Insert(std::make_unique<int>(14));
    tree12.Insert(std::make_unique<int>(10));
    bDelete = tree12.Delete(7);
    assert(bDelete);
    traverseResult = tree12.TraverseInOrder(tree12.GetRootNode().lock());
    assert(traverseResult[0] == 5);
    assert(traverseResult[1] == 9);
    assert(traverseResult[2] == 10);
    assert(traverseResult[3] == 11);
    assert(traverseResult[4] == 14);
    assert(traverseResult[5] == 15);
    assert(traverseResult[6] == 20);

    bDelete = tree12.Delete(7);
    assert(!bDelete);

    bDelete = tree12.Delete(9);
    assert(bDelete);
    traverseResult = tree12.TraverseInOrder(tree12.GetRootNode().lock());
    assert(traverseResult[0] == 5);
    assert(traverseResult[1] == 10);
    assert(traverseResult[2] == 11);
    assert(traverseResult[3] == 14);
    assert(traverseResult[4] == 15);
    assert(traverseResult[5] == 20);

    bDelete = tree12.Delete(9);
    assert(!bDelete);

    bDelete = tree12.Delete(10);
    assert(bDelete);

    traverseResult = tree12.TraverseInOrder(tree12.GetRootNode().lock());
    assert(traverseResult[0] == 5);
    assert(traverseResult[1] == 11);
    assert(traverseResult[2] == 14);
    assert(traverseResult[3] == 15);
    assert(traverseResult[4] == 20);

	return 0;
}