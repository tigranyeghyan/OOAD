#include <iostream>
#include "header.h"

// Bank class member functions

Bank::Bank() : capacity{50}, count {0}, accounts{new Account[capacity]} {}

Bank::~Bank()
{
	delete []accounts;
	accounts = nullptr;
}

// Create Bank account

int Bank::createAccount()
{
	if(count == capacity)
	{
		capacity *= 2;
		Account* create = new Account[capacity];
		for(int i = 0; i < count; ++i)
		{
			create[i] = accounts[i];	
		}
		delete []accounts;
		accounts = create;
		create = nullptr;
	}
	
	std::string name;
        std::cout << "Enter Account Name: ";
        std::cin >> name;
	
	accounts[count].setnumber(count);
	accounts[count].setname(name);
	accounts[count].setbalance(0);
	
	count++;

	std::cout << "Congratulations your Account has been Successfully created:" << std::endl;
	return count-1;
}
 
// Display Account information

void Bank::displayInfo(int index)
{
	std::cout << "Information for account " << index << ":" << std::endl;
	std::cout << "Name:           " << accounts[index].getname() << std::endl;
	std::cout << "Balance:        " << accounts[index].getbalance() << "$" << std::endl; 
}

// Money in out operations

void Bank::Deposit(int index, int money)
{
	accounts[index].deposit(money);	
}

void Bank::Withdraw(int index, int money)
{
	if(money > (accounts[index].getbalance()))
	{
		std::cout << "Not enough Funds!" << std::endl; 
	}
	else
	{
		accounts[index].withdraw(money);
	}
}



// Account class member functions

Account::Account() : number {0}, balance {0}, name {""} {}

// Getters

int Account::getnumber() const 
{
	return number;
}

int Account::getbalance() const 
{
	return balance;
}

std::string Account::getname() const 
{
	return name;
}


// Setters

void Account::setnumber(int number)
{
	this -> number = number;
}
void Account::setname(std::string name)
{
	this -> name = name;
}
void Account::setbalance(int balance = 0)
{
	this -> balance = balance;
}

// Money in out

void Account::deposit(int money)
{
	balance += money;
}

void Account::withdraw(int money)
{
	if(balance >= money)
	{
		balance -= money;
	}
	else
	{
		return; 
	}
}




