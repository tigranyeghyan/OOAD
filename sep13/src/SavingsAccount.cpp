#include <iostream>
#include <vector>
#include <string>
#include "../header/SavingsAccount.h"


SavingsAccount::SavingsAccount(double balance, const std::string& type, double rate) : Account(balance, type), interestRate {rate} 
{
	accounts.push_back(this);
}

SavingsAccount::SavingsAccount(const SavingsAccount &other)
{
	m_balance = other.m_balance;
	m_accountType = other.m_accountType;
	m_accountTransactions = other.m_accountTransactions;
	interestRate = other.interestRate;
}


void SavingsAccount::setInterestRate(double rate)
{
	if (limit > 0)
	{
		interestRate = rate;
	}
	else
	{
		std::cout << "Invalid Interest Rate" << std::endl;
	}
}


double SavingsAccount::getInterestRate() const
{
	return interestRate;
}


void SavingsAccount::deposit(double amount)
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

void SavingsAccount::withdraw(double amount)
{
	if(amount <= m_balance + m_balance * interestRate / 100  && amount > 0)
	{
		m_balance += m_balance * interestRate / 100;
		logTransaction(this, nullptr, amount, "Withdraw");
		m_balance -= amount;
	}
	else
	{
		std::cout << "Invalid Withdraw" << std::endl;
		return;
	}
}

void SavingsAccount::transfer(int identity, double amount)
{
	Account* dest = nullptr;
	if(id < accounts.size())
	{
		dest = accounts[id];
	}
	if(amount <= m_balance + m_balance * interestRate / 100 && amount > 0 && dest != nullptr)
	{
		m_balance += m_balance * interestRate / 100;		
		logTransaction(this, dest, amount, "Transfer");
		dest -> m_balance += amount;
		dest -> logTransaction(this, dest, amount, "Transfer");

		m_balance -= amount;
	}
	else
	{
		std::cout << "Invalid Transfer" << std::endl;
	}
}

void SavingsAccount::showBalance() const
{
	std::cout << "Balance = " << m_balance + m_balance * interestRate / 100 << std::endl; 
}

std::string SavingsAccount::getAccountType() const
{
	return m_accountType;
}
