#include <iostream>
#include "WashingMachine.h"
#include "Microwave.h"
#include "Appliance.h"
int main()
{
	WashingMachine wm;
	std::cout << wm.getState() << std::endl;
	wm.turnOn();
	std::cout << wm.getState() << std::endl;
	wm.turnOn();
	wm.turnOff();
	std::cout << wm.getState() << std::endl;
	

	Microwave mw;
	std::cout << mw.getState() << std::endl;
	mw.turnOn();
	std::cout << mw.getState() << std::endl;
	mw.turnOn();
	mw.turnOff();
	std::cout << mw.getState() << std::endl;

	return 0;
}
