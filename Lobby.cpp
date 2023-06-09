#include "Lobby.h"
#include <iostream>
#include <cstdlib>
#include <random>
#include <limits>
#include <vector>

using namespace std;

Lobby::Lobby() : library (*new Library()) {};

void Lobby::CallAddBook() {
    string title;
    string author;
    string y;

    cout << "Enter book's title: " << endl;
    getline(cin, title);
    cout << "Enter book's author: " << endl;
    getline(cin, author);
    cout << "Enter book's year: " << endl;
    getline(cin, y);

    int year = atoi(y.c_str());

    time_t now = time(nullptr);

    tm currentTime{};

    localtime_s(&currentTime, &now);

    int currYear = currentTime.tm_year + 1900;


    while (year <= 0 || year > currYear) {
        cout << "Enter actual book's year: " << endl;
        getline(cin, y);
        year = atoi(y.c_str());
    }

    size_t _id = hash<string>()(title + author);

    // Random number generator with current time
    random_device rd;
    mt19937 generator(rd());

    constexpr int imin = numeric_limits<int>::min(); // minimum value
    constexpr int imax = numeric_limits<int>::max(); // max

    uniform_int_distribution<int> distribution(imin, imax);

    int randomInt = distribution(generator);

    _id += randomInt;

    Book b(title, author, year, _id);
    library.AddBook(b);
}
    

void Lobby::CallDeleteBook() {
    cout << "Which book do you want to delete? (Enter an ID) " << endl;
    string input;
    getline(cin, input);
    try {
        library.DeleteBook(stoull(input));
    }
    catch (invalid_argument& excep) {
        cout << "Caught exception in: " << excep.what() << endl;
        }
    }


void Lobby::CallFindBook() {
    cout << "Which book do you want to find? (Enter a title) " << endl;
    string title;
    getline(cin, title);
    vector<Book> found_books = library.SearchBook(title);

    for (const Book& kniga : found_books) {
        cout << "Title: " << kniga.GetTitle() << endl;
        cout << "Author: " << kniga.GetAuthor() << endl;
        cout << "Year: " << kniga.GetYear() << endl;
        cout << "ID: " << kniga.GetID() << endl;
        cout << "Available: " << (kniga.AvaibleCheck() ? "Yes" : "No") << endl << endl;
    }
}


void Lobby::Define(string operation) {
    
    if (operation == "1") {
        CallAddBook();
    }
    
    else if (operation == "2") {
        CallDeleteBook();
    }
    
    else if (operation == "3") {
        CallFindBook();
    }

    else if (operation == "4") {
        exit(0);
    }

    else {
        cout << "No such operation." << endl << endl;
    }
}



void Lobby::Listen() {
    while (true) {

        cout << "What do you want to do?" << endl;
        cout << "1. Add a book." << endl;
        cout << "2. Delete a book." << endl;
        cout << "3. Find a book." << endl;
        cout << "4. Exit." << endl;

        string operation = " ";
        getline(cin, operation);

        Define(operation);
    }
}

