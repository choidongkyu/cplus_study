#pragma once
#include <memory>
#include <vector>
#include <iostream>
namespace assignment4
{
	template<typename T>
	class TreeNode;

	template<typename T>
	class BinarySearchTree final
	{
	public:
		BinarySearchTree();
		void Insert(std::unique_ptr<T> data);
		bool Search(const T& data);
		bool Delete(const T& data);
		const std::weak_ptr<TreeNode<T>> GetRootNode() const;

		static std::vector<T> TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode);
		static void AddInOrder(std::vector<T>& v, std::shared_ptr<TreeNode<T>> node);

	private:
		std::shared_ptr<TreeNode<T>> FindSubTree(std::shared_ptr<TreeNode<T>>& node);
		bool SearchTreeNode(std::shared_ptr<TreeNode<T>>& node, const T& data);
		std::shared_ptr<TreeNode<T>>& SerchDeleteNode(std::shared_ptr<TreeNode<T>>& node, const T& data);
		void InsertTreeNode(std::shared_ptr<TreeNode<T>>& node, std::unique_ptr<T>(data), std::weak_ptr<TreeNode<T>> parent);
		std::shared_ptr<TreeNode<T>> mRootNode;
		std::shared_ptr<TreeNode<T>> mEmptyNode;

		size_t mSize;
	};


	template<typename T>
	inline BinarySearchTree<T>::BinarySearchTree()
		: mSize(0)
		, mRootNode(nullptr)
	{
	}

	template<typename T>
	void BinarySearchTree<T>::Insert(std::unique_ptr<T> data)
	{
		if (mSize == 0)
		{
			mRootNode = std::make_shared<TreeNode<T>>(std::move(data));
			++mSize;
			return;
		}
		if (*data < *mRootNode->Data)
		{
			InsertTreeNode(mRootNode->Left, std::move(data), mRootNode);
		}
		else if (*data > *mRootNode->Data)
		{
			InsertTreeNode(mRootNode->Right, std::move(data), mRootNode);
		}

	}

	template<typename T>
	const std::weak_ptr<TreeNode<T>> BinarySearchTree<T>::GetRootNode() const
	{
		return mRootNode;
	}



	template<typename T>
	bool BinarySearchTree<T>::Search(const T& data)
	{
		if (mSize == 0)
		{
			return false;
		}
		return SearchTreeNode(mRootNode, data);
	}

	template<typename T>
	bool BinarySearchTree<T>::Delete(const T& data)
	{
		std::shared_ptr<TreeNode<T>> deleteNode;
		std::shared_ptr<TreeNode<T>> tmpNode;

		if (mSize == 0)
		{
			return false;
		}

		deleteNode = SerchDeleteNode(mRootNode, data);
		if (deleteNode == nullptr)
		{
			return false;
		}

		std::cout << "delete node = " << *deleteNode->Data << std::endl;
		if (deleteNode->Right != nullptr)
		{
			tmpNode = FindSubTree(deleteNode->Right);
		}
		else
		{
			tmpNode = FindSubTree(deleteNode);
		}

		std::cout << "FindSubTree = " << *tmpNode->Data << std::endl;

		if (deleteNode == tmpNode)
		{
			if (deleteNode->Parent.lock() != nullptr)
			{
				if (deleteNode->Left != nullptr)
				{
					deleteNode->Left->Parent = deleteNode->Parent;
					deleteNode->Parent.lock()->Left = deleteNode->Left;
				}
				if (deleteNode->Right != nullptr)
				{
					deleteNode->Right->Parent = deleteNode->Parent;
					deleteNode->Parent.lock()->Right = deleteNode->Right;
				}

				if (deleteNode->Right == nullptr && deleteNode->Left == nullptr)
				{
					if (*deleteNode->Data < *deleteNode->Parent.lock()->Data)
					{
						deleteNode->Parent.lock()->Left = nullptr;
					}
					else
					{
						deleteNode->Parent.lock()->Right = nullptr;
					}
				}
			}
			else
			{
				mRootNode = nullptr;
			}
		}
		else
		{
			if (*tmpNode->Data < *tmpNode->Parent.lock()->Data)
			{
				tmpNode->Parent.lock()->Left = nullptr;
			}
			else
			{
				tmpNode->Parent.lock()->Right = nullptr;
			}

			if (deleteNode->Left != nullptr)
			{
				if (deleteNode->Left != tmpNode)
				{
					deleteNode->Left->Parent = tmpNode;
					tmpNode->Left = deleteNode->Left;
				}
			}
			if (deleteNode->Right != nullptr)
			{
				if (deleteNode->Right != tmpNode)
				{
					deleteNode->Right->Parent = tmpNode;
					tmpNode->Right = deleteNode->Right;
				}
			}

			if (deleteNode->Parent.lock() != nullptr)
			{
				tmpNode->Parent = deleteNode->Parent;

				if (*deleteNode->Data < *deleteNode->Parent.lock()->Data)
				{
					deleteNode->Parent.lock()->Left = tmpNode;
				}
				else
				{
					deleteNode->Parent.lock()->Right = tmpNode;
				}
			}
			else
			{
				mRootNode = tmpNode;
				mRootNode->Parent.lock() = nullptr;
			}
		}
		return true;
	}

	template<typename T>
	std::vector<T> BinarySearchTree<T>::TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode)
	{
		std::vector<T> v;
		AddInOrder(v, startNode);
		return v;
	}

	template<typename T>
	inline void BinarySearchTree<T>::AddInOrder(std::vector<T>& v, std::shared_ptr<TreeNode<T>> node)
	{
		if (node != nullptr)
		{
			AddInOrder(v, node->Left);
			v.push_back(*node->Data);
			AddInOrder(v, node->Right);
		}
	}

	template<typename T>
	inline std::shared_ptr<TreeNode<T>> BinarySearchTree<T>::FindSubTree(std::shared_ptr<TreeNode<T>>& node)
	{
		if (node->Left != nullptr)
		{
			return FindSubTree(node->Left);
		}
		return node;
	}

	template<typename T>
	inline bool BinarySearchTree<T>::SearchTreeNode(std::shared_ptr<TreeNode<T>>& node, const T& data)
	{
		if (node == nullptr)
		{
			return false;
		}

		if (data < *node->Data)
		{
			return SearchTreeNode(node->Left, data);
		}
		else if (data > *node->Data)
		{
			return SearchTreeNode(node->Right, data);
		}
		else
		{
			std::cout << "mRootNode = " << *mRootNode->Data << std::endl;
			if (node->Parent.lock() != nullptr)
			{
				std::cout << "parent = " << *node->Parent.lock()->Data << std::endl;
			}
			else
			{
				std::cout << "parent = nullptr" << std::endl;
			}
			if (node->Left != nullptr)
			{
				std::cout << "Left = " << *node->Left->Data << std::endl;
			}
			else
			{
				std::cout << "Left = nullptr" << std::endl;
			}

			if (node->Right != nullptr)
			{
				std::cout << "Right = " << *node->Right->Data << std::endl;
			}
			else
			{
				std::cout << "Right = nullptr" << std::endl;
			}
			return true;
		}
	}

	template<typename T>
	inline std::shared_ptr<TreeNode<T>>& BinarySearchTree<T>::SerchDeleteNode(std::shared_ptr<TreeNode<T>>& node, const T& data)
	{
		if (node == nullptr)
		{
			return node;
		}

		if (data < *node->Data)
		{
			return SerchDeleteNode(node->Left, data);
		}
		else if (data > *node->Data)
		{
			return SerchDeleteNode(node->Right, data);
		}
		else
		{
			return node;
		}
	}

	template<typename T>
	inline void BinarySearchTree<T>::InsertTreeNode(std::shared_ptr<TreeNode<T>>& node, std::unique_ptr<T>(data), std::weak_ptr<TreeNode<T>> parent)
	{
		if (node == nullptr)
		{
			node = std::make_shared<TreeNode<T>>(parent.lock(), std::move(data));
			++mSize;
			return;
		}

		if (*data < *node->Data)
		{
			InsertTreeNode(node->Left, std::move(data), node);
		}
		else if (*data > *node->Data)
		{
			InsertTreeNode(node->Right, std::move(data), node);
		}
		else
		{
			return;
		}
	}
}