#pragma once 
#include "Shape.h"

class Circle : public Shape
{
public:
	Circle(int);
	void draw() override;
private:
	int radius;
};
