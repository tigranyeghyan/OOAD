#include <iostream>
#include "Car.h"
#include "Driver.h"

int main()
{
	Car mycar;
	Driver dr("Tigran");
	mycar.start();
	mycar.add_driver(dr);
	mycar.start();
	return 0;
}
