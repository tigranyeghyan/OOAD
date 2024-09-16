#include <iostream>
#include <vector>
#include <string>
#include "../header/CheckingAccount.h"


CheckingAccount::CheckingAccount(double balance, const std::string& type, double limit) : Account(balance, type), overdraftLimit {limit} 
{
	accounts.push_back(this);
}

CheckingAccount::CheckingAccount(const CheckingAccount &other)
{
	m_balance = other.m_balance;
	m_accountType = other.m_accountType;
	m_accountTransactions = other.m_accountTransactions;
	overdraftLimit = other.overdraftLimit;
}

void setOverdraftLimit(double limit)
{
	if (limit >= 0)
	{
		overdraftLimit = limit;
	}
	else
	{
		std::cout << "Invalid overdraft Limit" << std::endl;
	}
}


double CheckingAccount::getOverdraftLimit() const
{
	return overdraftLimit;
}


void CheckingAccount::deposit(double amount)
{
	if(amount > 0)
	{
		logTransaction(nullptr, this, amount, "Deposit");
		m_balance += amount;
	}
	else
	{
		std::cout << "Invalid Deposit" << std::endl;
	}
}

void CheckingAccount::withdraw(double amount)
{
	if(amount <= m_balance + overdraftLimit && amount > 0)
	{
		logTransaction(this, nullptr, amount, "Withdraw");
		m_balance -= amount;

		if(m_balance < 0)
		{
			overdraftLimit += m_balance;
			m_balance = 0;
		}
	}
	else
	{
		std::cout << "Invalid Withdraw" << std::endl;
		return;
	}
}

void CheckingAccount::transfer(int identity, double amount)
{
	if(amount <= m_balance + overdraftLimit && amount > 0)
	{	
		
		logTransaction(this, destination , amount, "Transfer");

		destination -> m_balance += amount;
		destination -> logTransaction(this, destination, amount, "Transfer");

		m_balance -= amount;
		if(m_balance < 0)
		{
			overdraftLimit += m_balance;
			m_balance = 0;
		}
	}
	else
	{
		std::cout << "Invalid Transfer" << std::endl;
	}
}

void CheckingAccount::showBalance() const
{
	std::cout << "Balance = " << m_balance << "\n" << "Overdraft Limit = " << overdraftLimit << std::endl;
}

std::string CheckingAccount::getAccountType() const
{
	return m_accountType;
}
