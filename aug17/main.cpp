#include <iostream>
#include "header.h"

int main()
{
	Bank Ameria;
	int acc1 = Ameria.createAccount();
	Ameria.displayInfo(acc1);
	Ameria.Deposit(acc1, 500);
	Ameria.displayInfo(acc1);
	Ameria.Withdraw(acc1, 1000);
	Ameria.Withdraw(acc1, 500);
	Ameria.displayInfo(acc1);
	int acc2 = Ameria.createAccount();
	Ameria.Deposit(acc2, 5000);
	Ameria.displayInfo(acc2);


	return 0;
}
