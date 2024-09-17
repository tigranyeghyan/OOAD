#include <iostream>
#include "../header/Account.h"

Account::Account(double balance, const std::string& type) : m_accountNumber{0}, m_balance {balance}, m_accountType {type} 
{
	int size = identity.size();
	identity.push_back(size);
	m_accountNumber = size;
}

void Account::logTransaction(Account *from, Account *to, double amount, const std::string& type)
{
	Transaction * ptr = new Transaction(from, to, amount, type);
	m_accountTransactions.push_back(ptr);
}

void Account::showTransactionHistory() const
{
	for (int i = 0; i < m_accountTransactions.size(); ++i)
	{
		m_accountTransactions[i] -> log();
		std::cout << "-----------------------" << std::endl;
	}
}

int Account::getAccountNumber() const
{
	return m_accountNumber;
}

void Account::setBalance(double amount)
{
	m_balance = amount;
}

double Account::getBalance() const
{
	return m_balance;
}

std::vector<int> Account::identity = {}; 

std::vector<Account*> Account::accounts = {};
