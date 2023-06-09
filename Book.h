#include <string>

class Book {

	std::string title;
	std::string author;
	int year;
	bool avaible = true;
	size_t id;

	
public:
	Book(std::string  t, std::string  a, int y, size_t i);

	std::string GetAuthor() const;

	std::string GetTitle() const;

	int GetYear() const;

	bool AvaibleCheck() const;

	void SetAvailable(bool a);

	size_t GetID() const;
};