#include <iostream>

const char* calculateGrade(float result)
{
    char* grade;
    if (result >= 85)
        grade = "A";
    else if (result >= 75)
        grade = "B";
    else if (result >= 50)
        grade = "C";
    else if (result >= 40)
        grade = "D";
    else grade = "F";
    return grade;
}

float askFromUser()
{
    float test1, test2, mid, final;

t1:
    std::cout << "Enter test1 result: ";
    std::cin >> test1;
    if (test1 < 0 || test1 > 10)
    {
        std::cout << std::endl << "Enter your test1 result correctly\n";
        goto t1;
    }
t2:
    std::cout << "Enter test2 result: ";
    std::cin >> test2;
    if (test2 < 0 || test2 > 15)
    {
        std::cout << std::endl << "Enter your test2 result correctly\n";
        goto t2;
    }
t3:
    std::cout << "Enter mid exam result: ";
    std::cin >> mid;
    if (mid < 0 || mid > 25)
    {
        std::cout << std::endl << "Enter your mid exam result correctly\n";
        goto t3;
    }
t4:
    std::cout << "Enter final exam result: ";
    std::cin >> final;
    if (final < 0 || final > 50)
    {
        std::cout << "\nEnter your final exam result correctly\n";
        goto t4;
    }

    return (test1 + test2 + mid + final);
}

/*
int main()
{
    float result = askFromUser();
    const char* grade = calculateGrade(result);

    std::cout << "\nYour result is: " << result << " so your grade result is: " << grade;

    return 0;
}
*/

















