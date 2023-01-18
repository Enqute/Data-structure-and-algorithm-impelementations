#include <iostream>

float getMinimum(float numbers[], unsigned int size)
{
    float min = numbers[0];
    for (int i = 1; i < size; i++)
    {
        if (min > numbers[i])
            min = numbers[i];
    }
    return min;
}

float* getTwoLargestNumbers(float numbers[], unsigned int size)
{
    float first, second;
    first = second = numbers[0];
    for (int i = 1; i < size; i++)
    {
        if (first < numbers[i])
            first = numbers[i];
    }
    for (int i = 1; i < size; i++)
    {
        if (second < numbers[i])
        {
            if (numbers[i] != first)
                second = numbers[i];
        }
    }
    return new float[2]{ first, second };
}

float* getNumbers()
{
    const unsigned int size = 10;
    float numbers[size];

    std::cout << "Enter 10 numbers to display its minimum: ";
    for (int i = 0; i < size; i++)
        std::cin >> numbers[i];

    return numbers;
}

int main()
{
    float* numbers = getNumbers();
    float min = getMinimum(numbers, 10);
    float* twoLargest = getTwoLargestNumbers(numbers, 10);
    std::cout << "\nThe minimum of these numbers is " << min;
    std::cout << "\nAnd the two top largest numbers are: " << twoLargest[0] << " and " << twoLargest[1];
}
