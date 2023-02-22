#include <iostream>
#include <string>

struct Student
{
    char Name[20];
    int Age;
    char Dept[25];

    Student* Next;
};

Student* head = NULL;
Student* tail = NULL;
size_t size = 0;

void AddFirst();
void AddLast();
void RemoveFirst();
void RemoveLast();
void Remove(char key[]);
void Insert(char key[]);
bool IsEmpty();
void Display();

int main()
{
    int n = 2;
    std::cout << "Registering " << n << " students" << std::endl;
    for (int i = 1; i <= n; i++)
        AddFirst();

    std::cout << "Displaying " << size << " students" << std::endl;
    Display();
    RemoveLast();
    Display();

    std::cin.get();
    return 0;
}

void AddFirst()
{
    Student* stud = new Student();

    std::cout << "Enter Student's name: ";
    std::cin >> stud->Name;
    std::cout << "Enter Student's age: ";
    std::cin >> stud->Age;
    std::cout << "Enter Student's dept: ";
    std::cin >> stud->Dept;
    stud->Next = NULL;

    if (IsEmpty())
        head = tail = stud;
    else
    {
        stud->Next = head;
        head = stud;
    }
    size++;
    std::cout << std::endl << stud->Name << " is successfully registered!\n";
}

void AddLast()
{
    Student* stud = new Student();

    std::cout << "Enter Student's name: ";
    std::cin >> stud->Name;
    std::cout << "Enter Student's age: ";
    std::cin >> stud->Age;
    std::cout << "Enter Student's dept: ";
    std::cin >> stud->Dept;
    stud->Next = NULL;

    if (IsEmpty())
        head = tail = stud;
    else
    {
        tail->Next = stud;
        tail = stud;
    }
    size++;
    std::cout << std::endl << stud->Name << " is successfully registered!\n";
}

void RemoveFirst()
{
    char choice = '\0';
    std::cout << std::endl << "Are you sure! do you want to delete " << head->Name << " (y/N): ";
    std::cin >> choice;
    if (choice == 'y')
    {
        Student* temp = head;
        char* name = temp->Name;
        head = head->Next;
        temp = temp->Next;
        std::cout << name << " is successfully deleted!";
        return;
    }
    std::cout << "You saved " << head->Name << " from deletion!";
}

void RemoveLast()
{
    char choice = '\0';
    std::cout << std::endl << "Are you sure! do you want to delete " << head->Name << " (y/N): ";
    std::cin >> choice;
    if (choice == 'y')
    {
        Student* stud = head;
        for (; stud->Next != tail; stud = stud->Next);
        Student* temp = stud->Next;
        std::cout << tail->Name << " is successfully deleted!";
        tail = stud;
        tail->Next = NULL;
        delete temp;
        return;
    }
    std::cout << "You saved " << head->Name << " from deletion!";
}

void Remove(char key[])
{

}

void Insert(char key[])
{
    Student* stud = new Student();

    std::cout << "Enter Student's name: ";
    std::cin >> stud->Name;
    std::cout << "Enter Student's age: ";
    std::cin >> stud->Age;
    std::cout << "Enter Student's dept: ";
    std::cin >> stud->Dept;
    stud->Next = NULL;

    if (IsEmpty())
        head = tail = stud;
    else
    {
        Student* temp = head;
        for (; (temp->Next->Name != key && temp != NULL); temp = temp->Next);
        stud->Next = temp->Next;
        temp->Next = stud;
    }
    size++;
    std::cout << std::endl << stud->Name << " is successfully registered\n";
}

bool IsEmpty()
{
    return size == 0;
}

void Display()
{
    Student* stud = head;
    for (; stud != NULL; stud = stud->Next)
    {
        std::cout << std::endl;
        std::cout << "-------------------------------------------------------------\n";
        std::cout << "Student name: " << stud->Name << std::endl;
        std::cout << "Student age: " << stud->Age << std::endl;
        std::cout << "Student dept: " << stud->Dept << std::endl;
        std::cout << "-------------------------------------------------------------\n";
    }
}
