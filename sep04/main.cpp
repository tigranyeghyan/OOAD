#include <iostream>
#include "Shape.h"
#include "Circle.h"
#include "Triangle.h"
#include "Square.h"
#include <vector>

int main()
{	
	std::vector<Shape*> ptr;
	Shape* sh = nullptr;
	Circle circle(5);
	Square square(5);
	Triangle triangle(5);
	ptr.push_back(&circle);
	ptr.push_back(&square);
	ptr.push_back(&triangle);
	for(int i = 0 ;i < 3; ++i)
	{
		ptr[i] -> draw();
		std::cout << std::endl;
	}

	return 0;
}
