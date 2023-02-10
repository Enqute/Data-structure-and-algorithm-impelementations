#include <iostream>
#include <stdlib.h>
#include <string>

#define ASSERT(x, message) if (!(x)) { std::cout << message << std::endl; system("Pause"); exit(-1); }

template<typename T>
class CircularLinkedList
{
private:
	struct Node
	{
		T Data;
		Node* Prev;
		Node* Next;
	};

private:
	#define null NULL;
	size_t m_Size = 0;
	Node* m_Head = nullptr;
	Node* m_Tail = nullptr;

public:
	const size_t Size() const
	{
		return m_Size;
	}

	const bool IsEmpty() const
	{
		return m_Size == 0;
	}

	const int IndexOf(const T& item) const
	{
		ASSERT(!IsEmpty(), "[Error]: IllegalAccessException thrown from 'IndexOf()'.");
		
		size_t index = 0;
		Node* node = m_Head;

		for (; node != m_Tail; node = node->Next)
		{
			if (node->Data == item)
				return index;
			index++;
		}

		return -1;
	}

	const bool Contains(const T& item) const
	{
		return IndexOf(item) != -1;
	}

	void Add(const T& item)
	{
		AddLast(item);
	}

	void AddFirst(const T& item)
	{
		Node* node = new Node{ item, nullptr, nullptr };
		if (IsEmpty())
			m_Head = m_Tail = node;
		else
		{
			node->Next = m_Head;
			m_Head->Prev = node;
			node->Prev = m_Tail;
			m_Head = node;
		}
		m_Size++;
	}

	void AddLast(const T& item)
	{
		Node* node = new Node{ item, nullptr, nullptr };
		if (IsEmpty())
			m_Head = m_Tail = node;
		else
		{
			m_Tail->Next = node;
			node->Prev = m_Tail;
			node->Next = m_Head;
			m_Tail = node;
		}
		m_Size++;
	}
	
	void Insert(const T& item, int index)
	{
	    ASSERT(index >= 0 && index <= m_Size, "[Error]: IndexOutOfBoundException thrown from 'Insert(...)'.");
	    if (index == 0)
	        AddFirst(item);
	    else if (index == m_Size)
	        AddLast(item);
	    else
	    {
	        Node* elem = new Node{ item, nullptr, nullptr };
	        Node* node = m_Head;
	        int counter = 0;
	        for (; (node != m_Tail && counter != index - 1); node = node->Next, counter++);
	        Node* temp = node->Next;
	        node->Next = elem;
	        elem->Prev = node;
	        elem->Next = temp;
	        temp->Prev = elem;
	        m_Size++;
	    }
	}

	const T& PeekFirst() const
	{
		ASSERT(!IsEmpty(), "[Error]: IllegalAccessException thrown from 'PeekFirst()'.");
		return m_Head->Data;
	}

	const T& PeekLast() const
	{
		ASSERT(!IsEmpty(), "[Error]: IllegalAccessException thrown from 'PeekFirst()'.");
		return m_Tail->Data;
	}

	T& RemoveFirst()
	{
		ASSERT(!IsEmpty(), "[Error]: IllegalAccessException thrown from 'RemoveFirst()'.");
		T data = m_Head->Data;
		if (m_Head == m_Tail)
		{
			m_Head->Data = m_Tail->Data = null;
			delete m_Head->Next, m_Head->Prev, m_Head;
			delete m_Tail->Next, m_Tail->Prev, m_Tail;
		}
		else
		{
			Node* node = m_Head->Next;
			delete m_Head;
			node->Prev = m_Tail;
			m_Head = node;
		}
		m_Size--;
		return data;
	}

	T& RemoveLast()
	{
		ASSERT(!IsEmpty(), "[Error]: IllegalAccessException thrown from 'RemoveLast()'.");
		T data = m_Tail->Data;
		if (m_Head == m_Tail)
		{
			m_Head->Data = m_Tail->Data = null;
			delete m_Head->Next, m_Head->Prev, m_Head;
			delete m_Tail->Next, m_Tail->Prev, m_Tail;
		}
		else
		{
			Node* node = m_Tail->Prev;
			delete m_Tail;
			node->Next = m_Head;
			m_Tail = node;
		}
		m_Size--;
		return data;
	}

	T& Remove(const T& item)
	{
		ASSERT(!IsEmpty(), "[Error]: IllegalAccessException thrown from 'Remove(...)'.");
		ASSERT(Contains(item), "[Error]: IllegalArgumentException thrown from 'Remove(...)'.");

		if (item == m_Head->Data)
			return RemoveFirst();
		if (item == m_Tail->Data)
			return RemoveLast();

		T data = item;

		Node* node = m_Head;
		for (; node->Data != item; node = node->Next);
		Node* temp = node;
		node->Prev->Next = node->Next;
		node->Next->Prev = node->Prev;
		node->Data = temp->Data = null;
		delete temp;
		m_Size--;

		return data;
	}

	T& RemoveAt(const size_t& index)
	{
		ASSERT(!IsEmpty(), "[Error]: IllegalAccessException thrown from 'Remove(...)'.");
		ASSERT(index >= 0 && index < m_Size, "[Error]: IllegalArgumentException thrown from 'RemoveAt(...)'.");

		if (index == 0)
			return RemoveFirst();
		if (index == m_Size - 1)
			return RemoveLast();

		size_t counter = 0;
		Node* node = m_Head;
		for (; (node != m_Tail && counter != index); node = node->Next)
			counter++;
		Node* temp = node;
		T data = node->Data;
		node->Prev->Next = node->Next;
		node->Next->Prev = node->Prev;
		node->Data = temp->Data = null;
		delete temp;
		m_Size--;

		return data;
	}
	
	const std::string ToString() const
    {
        std::string string = "[";
        bool iterate = true;
        for (Node* node = m_Head; iterate; node = node->Next)
        {
            std::string right = node == m_Tail ? "]" : ", ";
            string += std::to_string(node->Data) + right;
            if (node == m_Tail)
                iterate = false;
        }
        return string;
    }

    void Print() const
    {
        std::cout << ToString() << std::endl;
    }
};

int main()
{
    CircularLinkedList<int> numbers;
    numbers.Add(1);
    numbers.Add(2);
    numbers.Add(3);
    numbers.Add(4);
    numbers.Insert(12, 4);
    numbers.Insert(120, 1);
    
    numbers.Print();
    std::cin.get();
}
