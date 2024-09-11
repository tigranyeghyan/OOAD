#include <iostream>
#include "Triangle.h"

Triangle::Triangle(int hgh) : height {hgh} { }

void Triangle::draw()
{
	for (int i = 1; i <= height; ++i) 
	{
        for (int j = 1; j <= i; ++j) 
		{
            std::cout << "* ";
        }
        std::cout << std::endl;
    }
}
