#pragma once 
#include "Shape.h"

class Triangle : public Shape
{
public:
	Triangle(int);
	void draw() override;
private:
	int height;
};
