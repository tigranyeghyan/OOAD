#pragma once
#include "Book.h"
#include <vector>

class Library
{
public:
	Library(std::string);
	~Library() = default;
	void add_book(const Book&);
	void add_book(Book&&);
	void read_book(int);
private:
	std::string m_name;
	std::vector<Book> m_books;
};
