#include <iostream>

int binary_search(int* array, size_t size, int data)
{
    int start = 0;
    int end = size - 1;
    while (start <= end)
    {
        int middle = start + (end - start) / 2;
        if (data == array[middle])
            return middle;
        else if (data > array[middle])
            start = middle + 1;
        else end = middle - 1;
    }
    return -1;
}

int main()
{
    int numbers[] = {1, 2, 3, 4, 5};
    int location = binary_search(numbers, 5, 5);
    std::cout << location;
    return 0;
}