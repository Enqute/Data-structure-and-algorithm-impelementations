#include <iostream>

int linear_search(int* array, size_t size, int data)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == data)
            return i;
    }
    return -1;
}

int main()
{
    int numbers[] = {1, 2, 3, 4, 5};
    int location = linear_search(numbers, 5, 2);
    std::cout << location;
    return 0;
}
