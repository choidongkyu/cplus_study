#pragma once

#include <memory>
#include <iostream>

namespace assignment4
{
	template<typename T>
	class TreeNode final
	{
	public:
		TreeNode(std::unique_ptr<T> data);
		TreeNode(std::shared_ptr<TreeNode<T>> parent, std::unique_ptr<T> data);
		~TreeNode();
		std::unique_ptr<T> Data;
		std::shared_ptr<TreeNode<T>> Left;
		std::shared_ptr<TreeNode<T>> Right;
		std::weak_ptr<TreeNode<T>> Parent;
	};

	template<typename T>
	TreeNode<T>::TreeNode(std::unique_ptr<T> data)
		: Data(std::move(data))
		, Right(nullptr)
		, Left(nullptr)
	{
		//std::cout << "create TreeNode : " << *Data << std::endl;
	}

	template<typename T>
	TreeNode<T>::TreeNode(std::shared_ptr<TreeNode<T>> parent, std::unique_ptr<T> data)
		: Data(std::move(data))
		, Parent(parent)
		, Left(nullptr)
		, Right(nullptr)
	{
		//std::cout << "create TreeNode : " << *Data << std::endl;
	}
	
	template<typename T>
	inline TreeNode<T>::~TreeNode()
	{
		//std::cout << "delete TreeNode : " << *Data << std::endl;
	}
}