#pragma once
#include "Shape.h"

class Square : public Shape
{
public:
	Square(int);
	void draw() override;
private:
	int side;
};
