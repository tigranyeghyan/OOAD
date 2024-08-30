#include <iostream>
#include "Author.h"

Author::Author(std::string name) : m_name {name} { }

void Author::getname() const
{
	std::cout << "Author name: " << m_name << std::endl;
}
