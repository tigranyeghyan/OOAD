#include <iostream>
#include <string>
#include "Driver.h"

Driver::Driver(std::string name) : m_name{name} { }

void Driver::go()
{
	std::cout << "Lets go..." << std::endl;
}
