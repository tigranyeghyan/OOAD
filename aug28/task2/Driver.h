#pragma once
#include <string>

class Driver
{
public:
	Driver(std::string);
	void go();
private:
	std::string m_name;
};
