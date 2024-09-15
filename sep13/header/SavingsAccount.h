//Savings account

#pragma once

#include "Account.h"

class SavingsAccount : public Account
{
public:
	void deposit(double amount) override;
	void withdraw(double amount) override;
	void transfer(Account& destination, double amount) override;
	void showBalance() const override;
	std::string getAccountType() const override;
			
	SavingsAccount(const SavingsAccount &) = default;
	SavingsAccount(SavingsAccount &&) = default;
	SavingsAccount& operator=(const SavingsAccount &) = default;
	SavingsAccount& operator=(SavingsAccount &&) = default;
	~SavingsAccount() = default;

private:
	double interestRate;
};
