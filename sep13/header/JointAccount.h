//Joint Account

#pragma once
#include <vector>
#include <string>
#include "Account.h"
#include "Transaction.h"
#include "Customer.h"

class JointAccount : public Account
{
public:
	JointAccount(int number, double balance, const std::string& type);
	JointAccount(const JointAccount &name);
	~JointAccount() = default;
	
	void addCustomer(const std::string& name);
	void showCustomers() const;

	void deposit(double amount) override;
	void withdraw(double amount) override;
	void transfer(int id, double amount) override;
	void showBalance() const override;
	std::string getAccountType() const override;

private:
	std::vector<std::string> jointOwners;
};
