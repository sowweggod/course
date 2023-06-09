#include <vector>
#include "Book.h"

class Library {
	std::vector<Book> books;

public:

	void AddBook(Book kniga);

	void DeleteBook(size_t id);

	std::vector<Book> SearchBook(std::string const& title);
};