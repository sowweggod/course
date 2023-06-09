#include <string>
#include "Library.h"

class Lobby {
	Library library;

	void CallAddBook();

	void CallDeleteBook();

	void CallFindBook();

	void Define(std::string operation);

public:
	Lobby();
	void Listen();
};