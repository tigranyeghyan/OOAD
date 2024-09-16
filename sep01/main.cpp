#include <iostream>
#include <utility>
#include "Matrix.h"

int main()
{
	Matrix mtr;
	mtr.fill();
	mtr.print();
	Matrix mtr1(3, 4);
	mtr1.print();
	mtr1.fill();
	mtr1.print();
	mtr1 = std::move(mtr);
	mtr.print();
	mtr1.print(); 
	return 0;
}
