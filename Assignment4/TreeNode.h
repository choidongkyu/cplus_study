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
	}

	template<typename T>
	TreeNode<T>::TreeNode(std::shared_ptr<TreeNode<T>> parent, std::unique_ptr<T> data)
		: Data(std::move(data))
		, Parent(parent)
		, Left(nullptr)
		, Right(nullptr)
	{
	}
	
	template<typename T>
	inline TreeNode<T>::~TreeNode()
	{
	}
}