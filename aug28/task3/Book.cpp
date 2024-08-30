#include <iostream>
#include "Author.h"
#include "Book.h"

Book::Book(std::string title, Author& author) : m_title {title}, m_author {author} { }

Book::Book(Book&& book) : m_title {book.m_title}, m_author {book.m_author} 
{
	book.m_title = "";
}

void Book::display_info()
{
	std::cout << "Title:  " << m_title << std::endl;
	m_author.getname();
}
