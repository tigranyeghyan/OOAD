#include <iostream>
#include <vector>
#include "Book.h"
#include "Library.h"

Library::Library(std::string name) : m_name {name} {}

void Library::add_book(const Book& book)
{
	m_books.push_back(book);
	std::cout << "Book added to Library:" << std::endl;
}

void Library::add_book(Book&& book)
{
	m_books.push_back(std::move(book));
	std::cout << "Book moved to Library:" << std::endl;
}

void Library::read_book(int index)
{
	m_books[index].display_info(); 
}
