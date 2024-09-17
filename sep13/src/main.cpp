#include <iostream>
#include <string>
#include "../header/Customer.h"

int main()
{
	Customer Tigran("Tigran", "094480442");
	Tigran.CustomerInterface();
	Customer Edgar("Edgar", "044480442");
	Edgar.CustomerInterface();
	return 0;
}
