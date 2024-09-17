//Customer

#pragma once
#include <vector>
#include <string>
#include "Account.h"
#include "JointAccount.h"

class Customer 
{
public:
	void addAccount(Account* account);
	void viewAccounts() const;
	void viewTransactionHistory() const;
	void showCustomerInfo() const;
	void CustomerInterface();
	std::string getCustomerName() const; 
	Customer(const std::string &name, const std::string &contactInfo);
	Customer(const Customer &) = delete;
	Customer(Customer &&) = delete;
	Customer& operator=(const Customer &) = delete;
	Customer& operator=(Customer &&) = delete;
	~Customer() = default;
	friend void JointAccount::addCustomer(const std::string &name);
private:
	std::string m_name;
	std::string m_contactInfo;
	std::vector<Account*> m_accounts;
	static std::vector <Customer*> customer_list;
};
