//Transaction Manager

#pragma once
#include <string>
class Account;
class TransactionManager
{
public:
	virtual void logTransaction(Account *from, Account *to, double amount, const std::string& type) = 0;
	virtual void showTransactionHistory() const = 0;
};
