#include <iostream>
#include <string>
#include <stdlib.h>

#define ASSERT(x, message) if (!(x)) { std::cout << message << std::endl; system("pause"); exit(0); }

template<typename T>
class Stack
{
private:
    struct Node
    {
        T Data;
        Node* Next;
    }

private:
    constexpr static size_t m_Capacity = 1000;
    size_t m_Size = 0;
    Node* m_Head = nullptr;

public:
    const size_t Size() const
    {
        return m_Size;
    }

    const bool IsEmpty() const
    {
        return m_Size == 0;
    }

    const bool IsFull() const
    {
        return m_Size >= m_Capacity;
    }

    void Push(const T& item)
    {
        ASSERT(!IsFull(), "[Error]: StackOverflowException thrown from 'Push(...)'. The stack is full.");
        Node* node = new Node{ item, nullptr };
        node->Next = m_Head;
        m_Head = node;
        m_Size++;
    }

    T Pop()
    {
        ASSERT(!IsEmpty(), "[Error]: IllegalAccessException thrown from 'Pop()'. The stack is empty.");
        T data = m_Head->Data;
        Node* temp = m_Head;
        m_Head = m_Head->Next;
        delete temp;
        m_Size--;
        return data;
    }
    
    const T& Peek() const
    {
        ASSERT(!IsEmpty(), "[Error]: IllegalAccessException thrown from 'Peek()'. The stack is empty.");
        return m_Head->Data;
    }

    void Clear()
    {
        m_Size = 0;
        delete m_Head;
    }

    const std::string ToString() const 
    {
        std::string string = "[";
        if (m_Size == 0)
            string = "[]";
        else
        {
            for (Node* node = m_Head; node != nullptr; node = node->Next)
                string += std::to_string(node->Data) + (node->Next == nullptr ? "]" : ", ");
        }
        return string;
    }

    const void Print() const
    {
        std::cout << ToString() << std::endl;
    }
};

int main()
{
    Stack<int> numbers;
    numbers.Push(1);
    numbers.Push(2);
    numbers.Push(3);
    numbers.Push(4);
    numbers.Push(5);
    
    numbers.Pop();

    numbers.Print();
    return 0;
}

