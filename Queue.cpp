#include <iostream>
#include <string>

template<typename T>
class QueueByArray
{
private:
    T* list = nullptr;
    const static size_t m_Capacity = 100;
    size_t m_Size = 0;

public:
    QueueByArray()
        : list(new T[m_Capacity])
    {}

    void EnQueue(const T& item)
    {
        list[m_Size++] = item;
    }

    T& DeQueue()
    {
        T data = list[0];
        T* temp = new T[m_Size - 1];

        for (size_t i = 1, j = 0; i < m_Size; i++, j++)
            temp[j] = list[i];
        delete[] list;
        list = temp;
        m_Size--;
        return data;
    }

    bool IsEmpty()
    {
        return m_Size == 0;
    }

    T& Peek()
    {
        return list[0];
    }

    bool IsFull()
    {
        return m_Size >= m_Capacity;
    }

    void Print()
    {
        std::cout << ToString() << std::endl;
    }

    std::string ToString()
    {
        std::string string = "[";
		for (int i = 0; i < m_Size; i++)
			string += std::to_string(list[i]) + (i == m_Size - 1 ? "]" : ", ");
		return string;
    }
};

template<typename T>
class QueueByLinkedList
{
private:
    LinkedList<T> list;

public:
    void EnQueue(const T& item)
    {
        list.AddLast(item);
    }

    T& DeQueue()
    {
        return list.RemoveFirst();
    }

    bool IsEmpty()
    {
        return list.IsEmpty();
    }

    T& Peek()
    {
        return list.PeekFirst();
    }

    void Print()
    {
        std::cout << list.ToString() << std::endl;
    }
};

int main()
{
    QueueByLinkedList<int> numbers;
    numbers.EnQueue(1);
    numbers.EnQueue(2);
    numbers.EnQueue(3);
    numbers.EnQueue(4);
    numbers.DeQueue();
    numbers.EnQueue(5);

    numbers.Print();
}
