#include <iostream>
#include "Library.h"
#include "Author.h"
#include "Book.h"

int main()
{
	Author auth("Tigran");
	Book b1("Polytechnic", auth);
	Book b2("NATIONAL", auth);
	Library lib("LIB");
	lib.add_book(b1);
	lib.add_book(std::move(b2));
	lib.read_book(0);
	lib.read_book(1);
	return 0;
}
