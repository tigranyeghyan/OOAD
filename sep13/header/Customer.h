//Customer

#pragma once
#include <vector>
#include <string>
#include "Account.h"

class Customer 
{
public:
	void addAccount(Account* account);
	void viewAccounts() const;
	void viewTransactionHistory() const;
	void showCustomerInfo() const;

	Customer(const std::string &name, const std::string &contactInfo);
	Customer(const Customer &) = delete;
	Customer(Customer &&) = delete;
	Customer& operator=(const Customer &) = delete;
	Customer& operator=(Customer &&) = delete;
	~Customer() = default;

private:
	std::string m_name;
	std::string m_contactInfo;
	std::vector<Account*> m_accounts;
};
