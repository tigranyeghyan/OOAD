#pragma once

class Author
{
public:
	Author(std::string);
	void getname() const;
private:
	std::string m_name;
};
