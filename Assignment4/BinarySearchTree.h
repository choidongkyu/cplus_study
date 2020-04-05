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
		std::shared_ptr<TreeNode<T>> FindSubTree(std::shared_ptr<TreeNode<T>>& node);
		bool SearchTreeNode(std::shared_ptr<TreeNode<T>>& node, const T& data);
		std::shared_ptr<TreeNode<T>>& SerchDeleteNode(std::shared_ptr<TreeNode<T>>& node, const T& data);
		static std::vector<T> TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode);
		static void AddInOrder(std::vector<T>& v, std::shared_ptr<TreeNode<T>> node);
		void InsertTreeNode(std::shared_ptr<TreeNode<T>>& node, std::unique_ptr<T>(data), std::shared_ptr<TreeNode<T>>& parent);

	private:
		std::shared_ptr<TreeNode<T>> mRootNode;
	};


	template<typename T>
	inline BinarySearchTree<T>::BinarySearchTree()
		: mRootNode(nullptr)
	{
	}

	template<typename T>
	void BinarySearchTree<T>::Insert(std::unique_ptr<T> data)
	{
		if (Search(*data))
		{
			return;
		}

		if (mRootNode == nullptr)
		{
			mRootNode.reset(new TreeNode(std::move(data)));
			return;
		}
		std::shared_ptr<TreeNode<T>> curr = mRootNode;
		std::shared_ptr<TreeNode<T>> parent = nullptr;
		while (curr != nullptr)
		{
			parent = curr;
			if (*data < *parent->Data)
			{
				curr = curr->Left;
			}
			else
			{
				curr = curr->Right;
			}
		}
		if (*data < *parent->Data)
		{
			parent->Left.reset(new TreeNode(parent, std::move(data)));
		}
		else
		{
			parent->Right.reset(new TreeNode(parent, std::move(data)));
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
		if (mRootNode == nullptr)
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
		std::shared_ptr<TreeNode<T>> childNode;

		if (mRootNode == nullptr)
		{
			return false;
		}

		deleteNode = SerchDeleteNode(mRootNode, data);
		if (deleteNode == nullptr)
		{
			return false;
		}

		std::cout << "delete node = " << *deleteNode->Data << std::endl;

		//delete node가 단말인 경우
		if (deleteNode->Left == nullptr && deleteNode->Right == nullptr)
		{
			if (deleteNode->Parent.lock() != nullptr)
			{
				if (deleteNode->Parent.lock()->Left == deleteNode)
				{
					deleteNode->Parent.lock()->Left = nullptr;
				}
				else
				{
					deleteNode->Parent.lock()->Right = nullptr;
				}
			}
			else
			{
				mRootNode = nullptr;//부모가 없다면 rootnode이다.
			}
		}
		//delete node에 자식노드가 하나인 경우
		else if (deleteNode->Left == nullptr || deleteNode->Right == nullptr)
		{
			tmpNode = (deleteNode->Left != nullptr) ? deleteNode->Left : deleteNode->Right;
			if (deleteNode->Parent.lock() != nullptr)
			{
				if (deleteNode->Parent.lock()->Left == deleteNode)
				{
					deleteNode->Parent.lock()->Left = tmpNode;
					tmpNode->Parent = deleteNode->Parent;
				}
				else
				{
					deleteNode->Parent.lock()->Right = tmpNode;
					tmpNode->Parent = deleteNode->Parent;
				}
			}
			else
			{
				mRootNode = tmpNode;
			}
		}
		//두개의 자식노드를 가지는 경우
		else
		{
			tmpNode = FindSubTree(deleteNode->Right);
			deleteNode->Data = nullptr;//기존 deleteNode의 유니크포인터 값을 초기화
			deleteNode->Data = std::move(tmpNode->Data);//deleteNode의 값을 tmpnode의 값으로 바꿈
			if (tmpNode->Left == nullptr && tmpNode->Right == nullptr)//tmpnode를 지우는데 tmpnode가 단말인경우
			{
				if (tmpNode->Parent.lock()->Left == tmpNode)
				{
					tmpNode->Parent.lock()->Left = nullptr;
				}
				else
				{
					tmpNode->Parent.lock()->Right = nullptr;
				}
			}
			else if (tmpNode->Left == nullptr || tmpNode->Right == nullptr)//tmpnode를 지우는데 하나의 자식노드를 가지는경우
			{
				childNode = (tmpNode->Left != nullptr) ? tmpNode->Left : tmpNode->Right;
				if (tmpNode->Parent.lock()->Left == tmpNode)
				{
					tmpNode->Parent.lock()->Left = childNode;
					childNode->Parent = tmpNode->Parent;
				}
				else
				{
					tmpNode->Parent.lock()->Right = childNode;
					childNode->Parent = tmpNode->Parent;
				}
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
	void BinarySearchTree<T>::AddInOrder(std::vector<T>& v, std::shared_ptr<TreeNode<T>> node)
	{
		if (node != nullptr)
		{
			AddInOrder(v, node->Left);
			v.push_back(*node->Data);
			//std::cout << *node->Data << std::endl;
			AddInOrder(v, node->Right);
		}
	}

	template<typename T>
	std::shared_ptr<TreeNode<T>> BinarySearchTree<T>::FindSubTree(std::shared_ptr<TreeNode<T>>& node)
	{
		if (node->Left != nullptr)
		{
			return FindSubTree(node->Left);
		}
		return node;
	}

	template<typename T>
	bool BinarySearchTree<T>::SearchTreeNode(std::shared_ptr<TreeNode<T>>& node, const T& data)
	{
		if (node == nullptr)
		{
			return false;
		}

		if (data < *node->Data)
		{
			return SearchTreeNode(node->Left, data);
		}
		else if (data > * node->Data)
		{
			return SearchTreeNode(node->Right, data);
		}
		else
		{
			/*std::cout << "searchNode = " << *node->Data << std::endl;
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
			}*/
			return true;
		}
	}

	template<typename T>
	std::shared_ptr<TreeNode<T>>& BinarySearchTree<T>::SerchDeleteNode(std::shared_ptr<TreeNode<T>>& node, const T& data)
	{
		if (node == nullptr)
		{
			return node;
		}

		if (data < *node->Data)
		{
			return SerchDeleteNode(node->Left, data);
		}
		else if (data > * node->Data)
		{
			return SerchDeleteNode(node->Right, data);
		}
		else
		{
			return node;
		}
	}

	template<typename T>
	void BinarySearchTree<T>::InsertTreeNode(std::shared_ptr<TreeNode<T>>& node, std::unique_ptr<T>(data), std::shared_ptr<TreeNode<T>>& parent)
	{
		if (node == nullptr)
		{
			node = std::make_shared<TreeNode<T>>(parent, std::move(data));
			return;
		}

		if (*node->Data < *data)
		{
			InsertTreeNode(node->Right, std::move(data), node);
		}
		else
		{
			InsertTreeNode(node->Left, std::move(data), node);
		}

	}
}