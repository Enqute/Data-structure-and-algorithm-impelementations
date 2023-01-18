#pragma once

#include "Core.h"
#include <ostream>
#include <string>

template<typename T, size_t S>
class Array
{
private:
	T* m_List;
	const static size_t m_Size = S;

public:
	Array()
		: m_List(new T[S])
	{
	}

	~Array()
	{
		delete[] m_List;
	}

	inline size_t Size() const
	{
		return m_Size;
	}

	inline bool IsEmpty() const
	{
		return m_Size == 0;
	}

	const std::string ToString() const
	{
		std::string string = "[";
		for (int i = 0; i < m_Size; i++)
			string += std::to_string(m_List[i]) + (i == m_Size - 1 ? "]" : ", ");
		return string;
	}

	void Print() const
	{
		std::cout << ToString() << std::endl;
	}

	T& operator[] (const size_t& index)
	{
		ASSERT(index >= 0 && index < m_Size, "[Error]: ArrayIndexOutOfBoundException thrown.");
		return m_List[index];
	}

	friend std::ostream& operator<< (std::ostream& o, Array& list)
	{
		o << "[";
		for (int i = 0; i < m_Size; i++)
			o << list[i] << (i == m_Size - 1 ? "]" : ", ");
		return o;
	}
};
