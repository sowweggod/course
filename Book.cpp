#include "Book.h"
#include <utility>

Book::Book(std::string  t, std::string  a, int y, size_t i) : title(std::move(t)), author(std::move(a)), year(y), id(i) {}


std::string Book::GetAuthor() const {
    return author;
}

std::string Book::GetTitle() const {
    return title;
}

int Book::GetYear() const {
    return year;
}

bool Book::AvaibleCheck() const {
    return avaible;
}

void Book::SetAvailable(bool a) {
    avaible = a;
}

size_t Book::GetID() const {
    return id;
}
