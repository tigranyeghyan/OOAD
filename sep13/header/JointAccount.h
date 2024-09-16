//Joint Account

#pragma once
#include <vector>
#include "Account.h"
#include "Transactions"
#include "Customer.h"

class JointAccount : public Account
{
public:
	JointAccount(int number, double balance, const std::string& type);
	JointAccount(const JointAccount &name);
	~JointAccount() = default;
	
	void addCustomer(Customer *customer);
	void showCustomers() const;

	void deposit(double amount) override;
	void withdraw(double amount) override;
	void transfer(Account& destination, double amount) override;
	void showBalance() const override;
	std::string getAccountType() const override;

private:
	std::vector<Customer*> jointOwners;
};
