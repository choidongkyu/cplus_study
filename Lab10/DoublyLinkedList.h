#pragma once

#include <memory>
#include <iostream>

namespace lab10
{
	template<typename T>
	class Node;

	template<typename T>
	class DoublyLinkedList
	{
	public:
		DoublyLinkedList();
		void Insert(std::unique_ptr<T> data);
		void Insert(std::unique_ptr<T> data, unsigned int index);
		bool Delete(const T& data);
		bool Search(const T& data) const;
		void Printf() const;

		std::shared_ptr<Node<T>> operator[](unsigned int index) const;
		unsigned int GetLength() const;

	private:
		size_t mSize;
		std::shared_ptr<Node<T>> mHead;
		std::shared_ptr<Node<T>> mTail;

	};

	template<typename T>
	DoublyLinkedList<T>::DoublyLinkedList()
		: mSize(0)
		, mHead(nullptr)
	{
	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data)
	{
		if (mSize == 0)
		{
			mHead = std::make_shared<Node<T>>(std::move(data));
			mTail = mHead;
			mTail->Next = nullptr;
		}
		else
		{
			mTail->Next = std::make_shared<Node<T>>(std::move(data), mTail);
			mTail = mTail->Next;
			mTail->Next = nullptr;
		}
		++mSize;
	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data, unsigned int index)
	{
		std::shared_ptr<Node<T>> curr = mHead;
		std::shared_ptr<Node<T>> newNode;
		if (index >= mSize)
		{
			Insert(std::move(data));
			return;
		}

		if (index == 0)
		{
			newNode = std::make_shared<Node<T>>(std::move(data));
			newNode->Next = curr;
			curr->Previous = newNode;
			mHead = newNode;
			mHead->Previous.lock() = nullptr;
			++mSize;
			return;
		}

		for (size_t i = 0; i < index; ++i)
		{
			curr = curr->Next;
		}

		newNode = std::make_shared<Node<T>>(std::move(data), curr->Previous.lock());
		curr->Previous.lock()->Next = newNode;
		newNode->Next = curr;
		curr->Previous = newNode;
		++mSize;
		return;
	}

	template<typename T>
	bool DoublyLinkedList<T>::Delete(const T& data)
	{
		std::weak_ptr<Node<T>> prev;
		std::shared_ptr<Node<T>> next;
		std::shared_ptr<Node<T>> curr = mHead;
		for (size_t i = 0; i < mSize; ++i)
		{
			if (*(curr->Data) == data)
			{
				if (i == 0) // 첫 인덱스를 지울때
				{
					if (mSize == 1)
					{
						mHead = nullptr;
						--mSize;
						return true;
					}

					mHead = curr->Next;
					mHead->Previous.lock() = nullptr;
					--mSize;
					return true;
				}

				if (i == mSize - 1) // 끝 인덱스를 지울때
				{
					mTail = curr->Previous.lock();
					mTail->Next = nullptr;
					--mSize;
					return true;
				}

				prev = curr->Previous;
				next = curr->Next;
				prev.lock()->Next = next;
				next->Previous = prev;
				curr = nullptr;
				--mSize;
				return true;
			}
			curr = curr->Next;
		}
		return false;
	}

	template<typename T>
	bool DoublyLinkedList<T>::Search(const T& data) const
	{
		std::shared_ptr<Node<T>> curr = mHead;
		for (size_t i = 0; i < mSize; ++i)
		{
			if (*(curr->Data) == data)
			{
				return true;
			}
			curr = curr->Next;
		}
		return false;
	}

	template<typename T>
	inline void DoublyLinkedList<T>::Printf() const
	{
		auto cur = mHead;

		if (mHead == nullptr)
		{
			return;
		}

		for (size_t i = 0; i < mSize; ++i)
		{
			std::cout << *(cur->Data) << std::endl;
			cur = cur->Next;
		}
	}

	template<typename T>
	std::shared_ptr<Node<T>> DoublyLinkedList<T>::operator[](unsigned int index) const
	{
		if (index >= mSize)
		{
			return nullptr;
		}
		std::shared_ptr<Node<T>> curr = mHead;
		for (size_t i = 0; i < index; ++i)
		{
			curr = curr->Next;
		}
		return curr;
	}

	template<typename T>
	unsigned int DoublyLinkedList<T>::GetLength() const
	{
		return mSize;
	}
}