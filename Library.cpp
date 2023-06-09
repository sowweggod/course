#include "Library.h"
#include <iostream>
#include <vector>

using namespace std;

void Library::AddBook(Book kniga) {
    books.push_back(kniga);
    cout << "You've added a book." << endl << endl;
}

void Library::DeleteBook(size_t id) {
    for (int i = 0; i < books.size(); i++) {
        if (books[i].GetID() == id) {
            books.erase(books.begin() + i);
            cout << "You've deleted a book." << endl << endl;
            return;
        }
    }
    cout << "No such book." << endl << endl;
}

std::vector<Book> Library::SearchBook(string const& title) {
    vector<Book> t_books;

    for (const auto & book : books) {
        if (book.GetTitle() == title) {
            t_books.push_back(book);
            return t_books;
        }
    }

    if (t_books.empty()) {
        cout << "The book is not found." << endl << endl;
        return t_books;
    }
    else {
        return t_books;
    }
}
