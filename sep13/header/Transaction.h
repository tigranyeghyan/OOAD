//Transaction

#pragma once
#include "Account.h"

class Account;

class Transaction
{
public:
	void log() const;
	Transaction(Account *from, Account *to, double amount, const std::string &type);
private:
	Account* m_fromAccount;
	Account* m_toAccount;
	double m_amount;
	std::string m_transactionType;
};
