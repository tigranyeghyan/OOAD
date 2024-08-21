#include <iostream>
#include <vector>
#include "header.h"

Account::Account() : username {""}, name {""}, lastname {""}, password {""}, status_id {1}, number{0}, balance {0.0} {}

void Account::set_username(std::string USERNAME)
{
	username = USERNAME;
}

void Account::set_name(std::string NAME)
{
	name = NAME;
}

void Account::set_lastname(std::string LASTNAME)
{
	lastname = LASTNAME;
}

void Account::set_password(std::string PASSWORD)
{
	password = PASSWORD;
}

void Account::set_status_id(int STATUS_ID)
{
	status_id = STATUS_ID;
}	

std::string Account::get_name() const 
{
	return name;
}

std::string Account::get_lastname() const
{
	return lastname;
}	

std::string Account::get_username() const
{
	return username;
}

double Account::get_balance() const 
{
	return balance;
}

std::string Account::get_status() const
{
	switch(status_id)
	{
		case 1:
			return "Basic";
		case 2:
			return "Advanced";
		case 3: 
			return "Enterprice";
		default:
			return "Undefined";
	}
}

int Account::get_number() const
{
	return number;
}

void Account::add_action(const std::vector<string>& action)
{
	transactionhistory.push_back(action);
}

std::vector<std::vector<std::string>>& Account::get_transaction_history() const
{
	return transaction_history;
}

void Account::Deposit(double money)
{
	balance += money;	
}

double Account::Withdraw(double)
{
	balance -=money;
}
