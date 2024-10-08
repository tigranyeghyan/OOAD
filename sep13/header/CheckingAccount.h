//Checking Account

#pragma once

#include "Account.h"
#include "Transaction.h"
#include <vector>
#include <string>

class CheckingAccount : public Account
{
public:
	CheckingAccount(double balance, const std::string& type, double limit);
	
	void setOverdraftLimit(double limit);
	double getOverdraftLimit() const; 

	void deposit(double amount) override;
	void withdraw(double amount) override;
	void transfer(int id, double amount) override;
	void showBalance() const override;
	std::string getAccountType() const override;

private:
	double overdraftLimit;
};
