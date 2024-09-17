 #include <iostream>
#include <vector>
#include <string>
#include "../header/JointAccount.h"
#include "../header/Customer.h"


JointAccount::JointAccount(double balance, const std::string& type) : Account(balance, type) 
{
	accounts.push_back(this);
}


void JointAccount::addCustomer(Customer* customer)
{
	jointOwners.push_back(customer);	
	std::cout << "Customer Not Found" << std::endl;
}

void JointAccount::showCustomers() const
{
	for(int i; auto customer : jointOwners)
	{
		std::cout << i++ << "Customer:" << std::endl; 
		customer -> showCustomerInfo();
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

void JointAccount::transfer(int id, double amount)
{	
	Account* dest = nullptr;
	if(id < accounts.size())
	{
		dest = accounts[id];
	}
	if(amount <= m_balance && amount > 0 && dest != nullptr)
	{
		logTransaction(this, dest , amount, "Transfer");
		dest -> setBalance(getBalance() + amount);
		dest -> logTransaction(this, dest, amount, "Transfer");
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

std::string JointAccount::getAccountType() const
{
	return m_accountType;
}
