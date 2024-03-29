#pragma once

#include <string>

struct Date
{
    int Date;
    int Month;
    int Year;
};

enum class MovieType
{
    ACTION = 1, ADVENTURE, COMMEDY, DRAMA,
    FANTANSY, HORROR, MYSTERY, ROMANCE,
    SCIFI, SPORTS, THRILLER, WESTERN
};

enum class Language
{
    AMHARIC = 1, ARABIC, CHINESE, KOREAN, ENGLISH, FRENCH, HINDU, SPANISH
};

struct Movie
{
    int ID;
    std::string Title;
    float Rate;
    float Price;
    float Length;

    MovieType Genre;
    Date ReleasedDate;
    Language Lang;
};

struct Node
{
    Movie Movie;
    Node* Next;
    Node* Prev;
};

void AddFirst(const char* filepath);
void AddFirst(Movie movie);
void AddLast(Movie movie);
void InsertAtIndex(int index, Movie movie);
void InsertById(Movie movie, bool before, int ID);
void InsertByTitle(Movie movie, bool before, std::string title);

void RemoveFirst();
void RemoveLast();
void RemoveById(int ID);
void RemoveByTitle(std::string title);
void RemoveByIndex(int index);
void Remove(Movie movie);
void RemoveByLang(std::string lang);
void RemoveByGenre(std::string genre);
void RemoveByDate(std::string date);
void RemoveByMinPrice();
void RemoveByMinRate();
void RemoveByMaxPrice();
void RemoveByMaxRate();

Movie GetById(int ID);
Movie GetByTitle(std::string title);
Movie GetByIndex(int index);
Movie GetByMinPrice();
Movie GetByMinRating();
Movie GetByMaxPrice();
Movie GetByMaxRating();
float GetByAvePrice();
float GetByAveLength();
void GetByLang(std::string lang);
void GetByGenre(std::string genre);
void GetByDate(std::string releasedDate);
void GetByPrice(float price);
void GetByRate(float rate);
void GetByLength(float length);

void SaveStatus(const std::string& filepath);

int CountByRate(float rate);
int CountByPrice(float price);
int CountByLength(float length);
int CountByGenre(std::string genre);
int CountByDate(std::string date);
int CountByLang(std::string language);

int GetSize();

void UpdateId(int oldID, int newID);
void UpdateTitle(std::string oldTitle, std::string newTitle);
void UpdatePrice(int oldID, float newPrice);
void UpdateLength(int oldID, float newLength);
void UpdateRate(int oldID, float newRate);
void UpdateGenre(int oldID, std::string newGenre);
void UpdateLang(int oldID, std::string newLang);
void UpdateDate(int oldID, std::string newDate);

void SortedByID(Node** head_ref, Node* newNode);
void SortedByTitle(Node** head_ref, Node* newNode);
void SortedByPrice(Node** head_ref, Node* newNode);
void SortedByLength(Node** head_ref, Node* newNode);
void SortedByRate(Node** head_ref, Node* newNode);
void SortedByGenre(Node** head_ref, Node* newNode);
void SortedByLanguage(Node** head_ref, Node* newNode);
void SortedByDate(Node** head_ref, Node* newNode);
void InsertionSort(std::string type);

void TopByID(size_t size);
void TopByTitle(size_t size);
void TopByPrice(size_t size);
void TopByRate(size_t size);
void TopByDate(size_t size);

void DisplayForward();
void DisplayBackward();

inline bool IsEmpty();
int IndexOf(int movieID);
int IndexOf(Movie movie);
bool Contains(int movieID);

void printMovie(Movie movie);
std::string toUpper(std::string string);

Date stringToDate(std::string string);
MovieType stringToGenre(std::string string);
Language stringToLang(const char* string);

std::string dateToString(Date date);
std::string genreToString(MovieType genre);
std::string langToString(Language lang);
