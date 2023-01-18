#pragma once

#include "LinkedList.h"
#include "Array.h"

template<typename T>
class StackByLinkedList
{
private:
	LinkedList<T> m_List;

public:
	void Push(const T& item)
	{
		m_List.AddFirst(item);
	}

	T& Pop()
	{
		return m_List.RemoveLast();
	}

	T& Peek() const
	{
		return m_List.PeekLast();
	}

	bool IsEmpty() const
	{
		return m_List.IsEmpty();
	}
};

template<typename T>
class StackByArray
{
private:
	Array<T, 100> m_List;
	size_t m_Size = 0;
	size_t m_Capacity = m_List.Size();

public:
	void Push(const T& item)
	{
		m_List[m_Size++] = item;
	}

	T& Pop()
	{
		T data = m_List[m_Size - 1];
		Array<T, 100> temp = m_List;
		for (int i = 0; i < m_Size - 1; i++)
			temp[i] = m_List[i];
		m_List = temp;
		m_Size--;
		return data;
	}

	T& Peek() const
	{
		return m_List[m_Size - 1];
	}

	bool IsFull() const
	{
		return m_Size == m_Capacity;
	}

	bool IsEmpty() const
	{
		return m_Size == 0;
	}
};
