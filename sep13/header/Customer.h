//Customer

#pragma once
#include <vector>
#include <string>
#include "Account.h"
#include "JointAccount.h"

class Customer 
{
public:
	void addAccount();
	
	void viewAccounts() const;
	void viewTransactionHistory() const;
	void showCustomerInfo() const;
	void CustomerInterface();
	std::string getCustomerName() const; 
	Customer(const std::string &name, const std::string &contactInfo);
	~Customer() = default;
private:
	Customer(const Customer &) = default;
	Customer(Customer &&) = default;
	Customer& operator=(const Customer &) = default;
	Customer& operator=(Customer &&) = default;

private:
	std::string m_name;
	std::string m_contactInfo;
	std::vector<Account*> m_accounts;
	static std::vector <Customer*> customer_list;
};
