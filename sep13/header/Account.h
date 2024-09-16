//Account

#pragma once
#include "Transaction.h"
#include "Transaction Mnager"
#include <vector>

class Account : public TransactionManager
{
public:
	Account(int number, double balance, const std::string& type);

	void logTransaction(Account *from, Account *to, double amount, const std::string& type) override final;
	void showTransactionHistory() const override final;

	virtual void deposit(double amount) = 0;
	virtual void withdraw(double amount) = 0;
	virtual void transfer(Account& destination, double amount) = 0;
	virtual void showBalance() const = 0;
	
	int getAccountNumber() const;
	virtual std::string getAccountType() const = 0;
	
	virtual ~Account();
protected:
	int m_accountNumber;
	double m_balance;
	std::string m_accountType;
	std::vector<Transaction*> m_accountTransactions;
	static std::vector<int> identity;
	static std::vector<Account*> accounts;
};
