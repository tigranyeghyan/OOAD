#pragma once
#include "Author.h"

class Book
{
public:
	Book(std::string, Author&);
	Book(Book&&);
	Book(const Book&) = default;
	void display_info();
private:
	std::string m_title;
	Author& m_author;
};
