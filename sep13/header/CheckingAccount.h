//Checking Account

#pragma once

#include "Account.h"

class CheckingAccount : public Account
{
public:
	void deposit(double amount) override;
	void withdraw(double amount) override;
	void transfer(Account& destination, double amount) override;
	void showBalance() const override;
	std::string getAccountType() const override;
	
	CheckingAccount(const CheckingAccount &) = default;
	CheckingAccount(CheckingAccount &&) = default;
	CheckingAccount& operator=(const CheckingAccount &) = default;
	CheckingAccount& operator=(CheckingAccount &&) = default;
	~CheckingAccount() = default;
private:
	double overdraftLimit;
};
