//Transaction

#pragma once

#include "Account.h"

class Transaction
{


public:
	void log();

private:
	Account* fromAccount;
	Account* toAccount;
	double amount;
	std::string transactionType;

};
