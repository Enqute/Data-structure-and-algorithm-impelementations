#pragma once

#include "Core.h"
#include <iostream>
#include <string>

template<typename T>
class Vector
{
private:
	T* m_List = nullptr;
	size_t m_Size = 0;
	size_t m_Capacity = 0;

private:
	void ReAllocate(size_t capacity)
	{
		//T* newList = new T[capacity];
		T* newList = (T*)::operator new(capacity * sizeof(T));

		if (capacity < m_Size)
			m_Size = capacity;

		for (size_t i = 0; i < m_Size; i++)
			newList[i] = std::move(m_List[i]);

		for (size_t i = 0; i < m_Size; i++)
			m_List[i].~T();

		//delete[] m_List;
		::operator delete(m_List, m_Capacity * sizeof(T));
		m_List = newList;
		m_Capacity = capacity;
	}

public:
	Vector()
	{
		ReAllocate(2);
		m_List = new T[m_Capacity];
	}

	~Vector()
	{
		Clear();
		::operator delete(m_List, m_Capacity * sizeof(T));
	}
	
	const size_t Size() const
	{
		return m_Size;
	}

	void PushBack(const T& item)
	{
		if (m_Size >= m_Capacity)
			ReAllocate(m_Capacity + m_Capacity / 2);

		m_List[m_Size++] = item;
	}

	void PushBack(T&& item)
	{
		if (m_Size >= m_Capacity)
			ReAllocate(m_Capacity + m_Capacity / 2);

		m_List[m_Size++] = std::move(item);
	}

	template<typename... Args>
	T& EmplaceBack(Args&&... args)
	{
		if (m_Size >= m_Capacity)
			ReAllocate(m_Capacity + m_Capacity / 2);

		//m_List[m_Size] = T(std::forward<Args>(args)...);
		new(&m_List[m_Size]) T(std::forward<Args>(args)...);
		return m_List[m_Size++];
	}

	void PopBack()
	{
		ASSERT(m_Size > 0, "[Error]: IllegalAccessException thrown from 'PopBack()'.");
		m_List[--m_Size].~T();
	}

	void Clear()
	{
		ASSERT(m_Size > 0, "[Error]: IllegalAccessException thrown from 'Clear()'.");
		for (size_t i = 0; i < m_Size; i++)
			m_List[i].~T();
		m_Size = 0;
	}

	T& At(const size_t& index)
	{
		ASSERT(index >= 0 && index < m_Size, "[Error]: IndexOutOfBoundException thrown.");
		return m_List[index];
	}

	T& operator[] (const size_t& index)
	{
		return At(index);
	}

	const T& operator[] (const size_t& index) const
	{
		return At(index);
	}

	std::string ToString()
	{
		std::string string = "[";
		for (size_t i = 0; i < m_Size; i++)
			string += std::to_string(m_List[i]) + (i == m_Size - 1 ? "]" : ", ");
		return string;
	}

	void Print()
	{
		std::cout << ToString() << std::endl;
	}
};
