#include <iostream>
#include "Plane.h"
#include "Pilot.h"

int main()
{
	Plane Boeing;
	Pilot pilot1("Tigran");
	Pilot pilot2("Yeghyan");
	Boeing.fly();
	Boeing.add_pilot(pilot1);
	Boeing.fly();
	Boeing.add_pilot(pilot1);
	Boeing.add_pilot(pilot2);
	Boeing.fly();
	return 0;
}
