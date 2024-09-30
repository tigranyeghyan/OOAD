
#include <iostream>
#include <utility>
#include "Unique_ptr.hpp"

int main ()
{
	Unique_ptr<int>iptr(new int(42));
	Unique_ptr<int>ptr;
	ptr = std::move(iptr);
	std::cout << *ptr << std::endl;
	return 0;
}
