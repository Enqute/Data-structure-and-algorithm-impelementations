#pragma once

#include <iostream>
#include <cstdlib>
#include <string>

#define ASSERT(x, message) if (!(x)) { std::cout << message << std::endl; std::system("pause"); exit(-1); } 

template<typename T>
class CircularLinkedList
{
private:
    struct Node
    {
        T Data;
        Node* Next;
        Node* Prev;
    };
    
private:
    Node* m_Head = nullptr;
    Node* m_Tail = nullptr;
    size_t m_Size = 0;
    
public:
    inline size_t Size() const
    {
        return m_Size;
    }
    
    bool IsEmpty() const
    {
        return m_Size == 0;
    }

    int IndexOf(const T& item) const
    {
        ASSERT(!IsEmpty(), "[Error]: IllegalAccessException is thrown from 'IndexOf(...)'. You are trying to access elements of empty list!");
        int counter = 0;
        for (Node* node = m_Head; node != nullptr; node = node->Next)
        {
            if (node->Data == item)
                return counter;
            counter++;
        }
        return -1;
    }

    bool Contains(const T& item) const
    {
        return IndexOf(item) != -1;
    }

    void Add(const T& item)
    {
        AddLast(item);
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
            m_Tail = node;
        }
        m_Head->Prev = m_Tail;
        m_Tail->Next = m_Head;
        m_Size++;
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
            m_Head = node;
        }
        m_Head->Prev = m_Tail;
        m_Tail->Next = m_Head;
        m_Size++;
    }

    T& PeekFirst() const
    {
        ASSERT(!IsEmpty(), "[Error]: IllegalAccessException is thrown from 'PeekFirst()'. You are trying to access elements of empty list!");
        return m_Head->Data;
    }

    T& PeekLast() const
    {
        ASSERT(!IsEmpty(), "[Error]: IllegalAccessException is thrown from 'PeekLast()'. You are trying to access elements of empty list!");
        return m_Tail->Data;
    }

    T& RemoveFirst()
    {
        ASSERT(!IsEmpty(), "[Error]: IllegalAccessException is thrown from 'RemoveFirst()'. You are trying to remove elements of empty list!");
        if (m_Head == m_Tail)
        {
            delete m_Head, m_Tail;
            m_Head = m_Tail = nullptr;
        }
        else
        {
            m_Tail->Next = m_Head->Next;
            m_Head->Next->Prev = m_Tail;
            m_Head = m_Head->Next;
        }
        m_Size--;
    }

    T& RemoveLast()
    {
        ASSERT(!IsEmpty(), "[Error]: IllegalAccessException is thrown from 'RemoveLast()'. You are trying to remove elements of empty list!");
        if (m_Head == m_Tail)
        {
            delete m_Head, m_Tail;
            m_Head = m_Tail = nullptr;
        }
        else
        {
            m_Head->Prev = m_Tail->Prev;
            m_Tail->Prev->Next = m_Head;
            m_Tail = m_Tail->Prev;
        }
        m_Size--;
    }
};
