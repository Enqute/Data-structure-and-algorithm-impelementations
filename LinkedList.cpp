#include <iostream>
#include <stdlib.h>
#include <string>

#define ASSERT(x, message) if (!(x)) { std::cout << message << std::endl; exit(0); }

template<typename T>
class LinkedList
{
private:
    struct Node
    {
        T Data;
        Node* Next;
    };

private:
    Node* m_Head {};
    Node* m_Tail {};
    size_t m_Size = 0;
    
public:
    LinkedList()
    {
    }

    ~LinkedList()
    {
    }

    inline const size_t Size() const 
    { 
        return m_Size; 
    }

    inline const bool IsEmpty() const 
    { 
        return m_Size == 0; 
    }

    const int IndexOf(const T& item) const 
    {
        Node* node = m_Head;
        int counter = 0;

        while (node != nullptr)
        {
            if (node->Data == item)
                return counter;
            node = node->Next;
            counter++;
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
        Node* node = new Node{item, nullptr};
        if (IsEmpty())
            m_Head = m_Tail = node;
        else
        {
            node->Next = m_Head;
            m_Head = node;
        }
        m_Size++;
    }

    void AddLast(const T& item)
    {
        Node* node = new Node{item, nullptr};
        if (IsEmpty())
            m_Head = m_Tail = node;
        else
        {
            m_Tail->Next = node;
            m_Tail = node;
        }
        m_Size++;
    }

    T& PeekFirst() const
    {
        return m_Head->Data;
    }

    T& PeekLast() const
    {
        return m_Tail->Data;
    }

    T& RemoveFirst()
    {
        ASSERT(!IsEmpty(), "[Error]: IllegalAccessException thrown from 'RemoveFirst()'.");
        T data = m_Head->Data;
        if (m_Head == m_Tail)
            delete m_Head, m_Tail;
        else
        {
            Node* node = m_Head->Next;
            delete m_Head;
            m_Head = node;
        }
        m_Size--;
        return data;
    }

    T& RemoveLast()
    {
        ASSERT(!IsEmpty(), "[Error]: IllegalAccessException thrown from 'RemoveLast()'.");
        T data = m_Head->Data;
        if (m_Head == m_Tail)
            delete m_Head, m_Tail;
        else
        {
            Node* node;
            for (node = m_Head; node->Next != m_Tail; node = node->Next);
            node->Next = m_Tail->Next;
            delete m_Tail;
            m_Tail = node;
        }
        m_Size--;
        return data;
    }

    T& Remove(const T& item)
    {
        ASSERT(!IsEmpty(), "[Error]: IllegalAccessException thrown from 'Remove(...)'.");
        ASSERT(Contains(item), "[Error]: IllegalArgumentException thrown from 'Remove(...)'. The item that you want to delete is not here.");

        T data = item;

        if (m_Head->Data == item)
            return RemoveFirst();
        if (m_Tail->Data == item)
            return RemoveLast();
        if (m_Head == m_Tail)
            delete m_Head, m_Tail;
        else
        {
            Node* node;
            for (node = m_Head; node != nullptr; node = node->Next)
                if (node->Next->Data == item)
                    break;
            Node* temp = node->Next;
            node->Next = temp->Next;
            delete temp;
        }
        m_Size--;
        return data;
    }

    T& RemoveAt(const int index)
    {
        ASSERT(!IsEmpty(), "[Error]: IllegalAccessException thrown from 'RemoveAt(const int)'.");
        ASSERT(index >= 0 && index < m_Size, "[Error]: IndexOutOfBoundException thrown from 'RemoveAt(const int)'.");

        T data;

        if (index == 0)
            return RemoveFirst();
        if (index == m_Size - 1)
            return RemoveLast();
        if (m_Head == m_Tail)
            delete m_Head, m_Tail;
        else
        {
            Node* node;
            int counter = 0;
            for (node = m_Head; node != nullptr; node = node->Next)
            {
                if (index == counter + 1)
                    break;
                counter++;
            }
            Node* temp = node->Next;
            data = temp->Data;
            node->Next = temp->Next;
            delete temp;
        }
        m_Size--;
        return data;
    }

    const std::string ToString() const
    {
        std::string string = "[";
        for (Node* node = m_Head; node != nullptr; node = node->Next)
        {
            std::string right = node == m_Tail ? "]" : ", ";
            string += std::to_string(node->Data) + right;
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
    LinkedList<int> numbers;
    numbers.Add(1);
    numbers.Add(2);
    numbers.Add(3);
    numbers.Add(4);
    
    numbers.Print();
    std::cin.get();
}
