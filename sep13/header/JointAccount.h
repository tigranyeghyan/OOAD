//Joint Account

#pragma once
#include <vector>
#include <string>
#include "Account.h"
#include "Transaction.h"
#include "Customer.h"

class Customer;
class JointAccount : public Account
{
public:
	JointAccount(double balance, const std::string& type);
	
	void addCustomer(Customer *customer);
	void showCustomers() const;

	void deposit(double amount) override;
	void withdraw(double amount) override;
	void transfer(int id, double amount) override;
	void showBalance() const override;
	std::string getAccountType() const override;

private:
	std::vector<Customer*> jointOwners;
};
