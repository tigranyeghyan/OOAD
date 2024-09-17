//Savings account

#pragma once

#include "Account.h"
#include "Transaction.h"
#include <vector>
#include <string>

class SavingsAccount : public Account
{
public:
	SavingsAccount(double balance, const std::string& type, double rate);

	void setInterestRate(double rate);
	double getInterestRate() const;

	void deposit(double amount) override;
	void withdraw(double amount) override;
	void transfer(int id, double amount) override;
	void showBalance() const override;
	std::string getAccountType() const override;
private:
	double interestRate;
};
