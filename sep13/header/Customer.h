//Customer

#pragma once
#include <vector>
#include "Account.h"

class Customer
{
public:
	void addAccount(Account* account);
	void viewAccounts() const;
	void viewTransactionHistory() const;
	
	Customer();
	Customer(const Customer &) = delete;
	Customer(Customer &&) = default;
	Customer& operator=(const Customer &) = delete;
	Customer& operator=(Customer &&) = default;
	~Customer() = default;

private:
	std::string name;
	std::string contactInfo;
	std::vector<Account*> accounts;

};
