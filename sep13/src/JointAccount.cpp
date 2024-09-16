 #include <iostream>
#include <vector>
#include <string>
#include "../header/JointAccount.h"


JointAccount::JointAccount(double balance, const std::string& type) : Account(balance, type) 
{
	accounts.push_back(this);
}

JointAccount::JointAccount(const JointAccount &other)
{
	m_balance = other.m_balance;
	m_accountType = other.m_accountType;
	m_accountTransactions = other.m_accountTransactions;
	jointOwners = other.jointOwners;
}


void JointAccount::addCustomer(Customer *customer)
{
	jointOwners.push_back(customer);
}

void JointAccount::showCustomers() const
{
	for(int i, auto customers : jointOwners)
	{
		std::cout << i++ << "Customer:" << std::endl; 
		customers -> showCustomerInfo();
	}
}

void JointAccount::deposit(double amount)
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

void JointAccount::withdraw(double amount)
{
	if(amount <= m_balance && amount > 0)
	{
		logTransaction(this, nullptr, amount, "Withdraw");
		m_balance -= amount;
	}
	else
	{
		std::cout << "Invalid Withdraw" << std::endl;
	}
}

void JointAccount::transfer(Account& destination, double amount)
{
	if(amount <= m_balance && amount > 0)
	{
		logTransaction(this, &destination , amount, "Transfer");
		destination.m_balance += amount;
		destination.logTransaction(this, &destination, amount, "Transfer");
		m_balance -= amount;
	}
	else
	{
		std::cout << "Invalid Transfer" << std::endl;
	}
}

void JointAccount::showBalance() const
{
	std::cout << "Balance = " << m_balance << std::endl; 
}

std::string SavingsAccount::getAccountType() const
{
	return m_accountType;
}
