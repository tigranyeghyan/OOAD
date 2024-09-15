//Account

#pragma once

class Account 
{
public:
	virtual void deposit(double amount) = 0;
	virtual void withdraw(double amount) = 0;
	virtual void transfer(Account& destination, double amount) = 0;
	virtual void showBalance() const = 0;
	virtual std::string getAccountType() const = 0;
	virtual ~Account();
protected:
	int accountNumber;
	double balance;
	std::string accountType;
};
