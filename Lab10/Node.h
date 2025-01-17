#pragma once
#include <iostream>
#include <memory>
namespace lab10
{
	template<typename T>
	class Node
	{
	public:
		Node(std::unique_ptr<T> data);
		Node(std::unique_ptr<T> data, std::shared_ptr<Node<T>> prev);
		~Node();
		std::unique_ptr<T> Data;
		std::shared_ptr<Node<T>> Next;
		std::weak_ptr<Node<T>> Previous;
	};

	template<typename T>
	Node<T>::Node(std::unique_ptr<T> data)
		: Data(std::move(data))
	{
		//std::cout << "node create : " << *Data << std::endl;
	}

	template<typename T>
	Node<T>::Node(std::unique_ptr<T> data, std::shared_ptr<Node<T>> prev)
		: Data(std::move(data))
	{
		Previous = prev;
		//std::cout << "node create : " << *Data << std::endl;
	}

	template<typename T>
	inline Node<T>::~Node()
	{
		//std::cout << "node delete : " << *Data << std::endl;
	}
}