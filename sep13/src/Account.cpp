#include <iostream>
#include "../header/Account.h"

Account(double balance, const std::string& type) : m_accountNumber{0}, m_balance {balance}, m_accountType {type} 
{
	int size = identity.size();
	Account::identity.push_back(size);
	m_accountNumber = size;
}

void Account::logTransaction(Account *from, Account *to, double amount, const std::string& type)
{
	Transaction transaction(from, to, amount, type);
	m_accountTransactions.push_back(transaction);
}

void Account::showTransactionHistory() const
{
	for (int i = 0; i < m_accountTransactions.size(); ++i)
	{
		m_accountTransactions -> log();
		std::cout << "-----------------------" << std::endl;
	}
}

int getAccountNumber() const
{
	return m_accountNumber;
}

static std::vector<int> Account::identity = {}; 

static std::vector<Account*> Account::acounts = {};
