#include <iostream>
#include <string>
#include <stdlib.h>

#define ASSERT(x, message) if (!(x)) { std::cout << message << std::endl; system("pause"); exit(0); }

template<typename T>
class Stack
{
private:
    constexpr static size_t m_Capacity = 1000;
    size_t m_Size = 0;
    T* m_Data = (T*)malloc(sizeof(T) * m_Capacity);

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
        m_Data[m_Size++] = item;
    }

    T Pop()
    {
        ASSERT(!IsEmpty(), "[Error]: IllegalAccessException thrown from 'Pop()'. The stack is empty.");
        T data = m_Data[0];
        T* newData = (T*)malloc(sizeof(T) * m_Size);
        for (int i = 0; i < m_Size - 1; i++)
            newData[i] = m_Data[i];
        m_Data = newData;
        m_Size--;
        return data;
    }
    
    const T& Peek() const
    {
        ASSERT(!IsEmpty(), "[Error]: IllegalAccessException thrown from 'Peek()'. The stack is empty.");
        return m_Data[m_Size - 1];
    }

    void Clear()
    {
        m_Size = 0;
        delete[] m_Data;
    }

    const std::string ToString() const 
    {
        std::string string = "[";
        if (m_Size == 0)
            string = "[]";
        else
        {
            for (int i = m_Size - 1; i >= 0; i--)
                string += std::to_string(m_Data[i]) + (i == 0 ? "]" : ", ");
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

