#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "../header/Customer.h"

Customer::Customer(const std::string &name, const std::string &contactInfo) : m_name{name}, m_contactInfo {contactInfo} 
{
	std::cout << "Creating Account ..." << std::endl;
	do 
	{
		addAccount();
	}while (m_accounts.empty());
	if(m_accounts.empty())
	{
		throw std::runtime_error("Account dont create!");
	}
	else
	{
		customer_list.push_back(this);
	}
}

static std::vector<Customer*> customer_list = {};

void Customer::addAccount(Account* account)
{
	size_t choice = 0;
	do 
	{
		system("clear");
		std::cout << "Enter Account type" << std::endl;
		std::cout << "1 --> Checking Account:" << std::endl;
		std::cout << "2 --> Savings Account:" << std::endl;
		std::cout << "3 --> Joint Account:" << std::endl;
		std::cout << "0 --> Exit:" << std::endl;
		std::cin >> choice;
	} while(choice <= 3);
	switch (choice)
	{
		case 1:
		{
			system("clear");
			std::cout << "Creating Checking Account ..." << std::endl;		
			size_t overdraft;
			std::cout << "Enter Overdraft Limit: ";
			std::cin >> overdraft;
			CheckingAccount *ptr = new CheckingAccount(0, "CheckingAccount", overdraft);
			m_accounts.push_back(ptr);
			std::cout << "Account Created Successfully!" << std::endl;
			break;
		}
		case 2:
		{
			system("clear");
			std::cout << "Creating Savings Account ..." << std::endl;
			double rate;
			std::cout << "Enter Interest Rate: ";
			std::cin >> rate;
			SavingsAccount *ptr = new SavingsAccount(0, "SavingsAccount", rate);
			m_accounts.push_back(ptr);
			std::cout << "Account Created Successfully!" << std::endl;	
			break;
		}
		case 3:
		{
			system("clear");
			std::cout << "Creating Joint Account ..." << std::endl; 
			JointAccount *ptr = new JointAccount(0, "JointAccount");
			m_accounts.push_back(ptr);
			std::cout << "Account Created Successfully!" << std::endl;	
			break;			
		}
		case 0:
		{
			std::cout<< "Exiting ..." << std::endl;
			return; 
		}
		default:
		{
			system("clear");
			std::cout << "You are invalid!" << std::endl;
			return;
		}
	}
}

void Customer::viewAccounts() const
{	
	std::cout << "My Accounts: " << std::endl;
	for(int i, auto acc : m_accounts)
	{
		std::cout << i + 1 << ": " << acc -> getAccountType() << std::endl; 
		i++;
	}
}

void Customer::viewTransactionHistory() const
{
	for(int i, auto acc : m_accounts)
	{
		std::cout << i + 1 << ": " << acc -> getAccountType() << std::endl; 			
		i++;
		acc -> showTransactionHistory();
		std::cout << "-----------------" << std::endl;
	}

}

void Customer::showCustomerInfo() const
{	
	std::cout  << "Name --> " << m_name <<std::endl;
	std::cout << "Contact Info --> " << m_contactInfo << std::endl;
}

void Customer::CustomerInterface()
{	
	do 
	{	
		size_t chose = 0;
		do
		{
			system("clear");
			std::cout << "1 --> Chose Account: " << std::endl;
			std::cout << "0 --> Exit: " << std::endl;
			std::cin >> chose;
		}while (chose > 1);

		if(chose == 0)
		{	
			std::cout << "Exiting ..." << std::endl;
			return;
		}
		else
		{
			system("clear");
			std::cout << "Chose Account: " << std::endl;
			size_t acc_i;
			size_t i = 0;
			for(auto acc : m_accounts) 
			{
				std::cout << i + 1 << " --> " << acc -> getAccountType() << "\t" << acc -> getAccountNumber() << std::endl;
			}
			do
			{
				std::cin >> acc_i;
			} while(acc_i - 1 < i);

			std::string acc_type = m_accounts[acc_i] -> getAccountType(); 
			size_t acc_type_num = 0;
			size_t action = 0;
			do
			{
				system("clear");
				std::cout << "Chose Action: " << std::endl;	
				std::cout << "1 --> Deposit:" << std::endl;
				std::cout << "2 --> Withdraw:" << std::endl;
				std::cout << "3 --> Transfer:" << std::endl;
				std::cout << "4 --> Show Balance:" << std::endl;				
				if (acc_type == "CheckingAccount")
				{
					acc_type_num = 1;
					std::cout << "5 --> Set Overdraft Limit: " << std::endl;
					std::cout << "6 --> Show Overdraft Limit: " << std::endl;
					break;
				}
				else if (acc_type == "SavingsAccount")
				{
					acc_type_num = 2;
					std::cout << "5 --> Set Interest Rate: " << std::endl;
					std::cout << "6 --> Show Interest Rate: " << std::endl;
					break;	
				}
				else if(acc_type == "JointAccount")
				{
					acc_type_num = 3;
					std::cout << "5 --> Add Customer: " << std::endl;
					std::cout << "6 --> Show Customers: " << std::endl;
					break;
				}
				else
				{
					throw std::runtime_error("Account Type incorrect");
				}
				std::cout << "0 --> Exit: " << std::endl;
				std::cout << "Enter action: ";
				std::cin >> action;
				if(action == 0)
				{
					std::cout << "Exiting ..." << std::endl;
					break;
				}
				else if(action <= 4)
				{
					switch (action)
					{
						case 1:
						{
							double amount;
							std::cout << "Enter Amount to Deposit: ";
							std::cin >> amount;
							m_accounts[acc_i] -> deposit(amount);
							break;
						}
						case 2:
						{
							double amount;
							std::cout << "Enter Amount to Withdraw: ";
							std::cin >> amount;
							m_accounts[acc_i] -> withdraw(amount);
							break;
						}
						case 3:
						{
							double amount;
							int identity;
							std::cout << "Enter Account Number to transfer: ";
							std::cin >> identity;
							std::cout << "Enter Amount to Transfer: ";
							std::cin >> amount;
							m_accounts[acc_i] -> transfer(identity, amount);
							break;
						}
						case 4:
						{
							std::cout << "Viewing Your Balance ..." << std::endl;
							m_accounts[acc_i] -> showBalance();
							break;
						}
					}
				}
				else if (action == 5 || action == 6)
				{
					switch (acc_type_num)
					{
						case 1:
						{
							if(action == 5)
							{
								double limit;
								std::cout << "Enter Overdraft Limit: " << limit;
								std::cin >> limit;
								m_accounts[acc_i] -> setOverdraftLimit(limit);
							}
							else if(action == 6)
							{
								std::cout << "Overdraft Limit: "  << m_accounts[acc_i] -> getOverdraftLimit() << std::endl;
							}
							else
							{
								break;
							}
							break;				
						}
						case 2:
						{
							if(action == 5)
							{
								double rate;
								std::cout << "Enter New Interest Rate: " << limit;
								std::cin >> rate;
								m_accounts[acc_i] -> getInterestRate(rate);
							}	
							else if(action == 6)
							{
								std::cout << "Interest Rate: " << m_accounts[acc_i] -> getInterestRate() << std::endl;
							}
							else
							{
								break;
							}
							break;		
						}
						case 3:
						{
							if(action == 5)
							{
								std::cout << "Adding Customers:" << std::endl;
								std::string name;
								std::cout << "Customer name: ";
								std::cin.clear();
        						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
								std::cin >> name;
								m_accounts[acc_i] -> addCustomer(name);
							}
							else if(action == 6)
							{
								std::cout << "Account Customers: "  << std::endl;
								m_Accounts[acc_i] -> showCustomers();
							}
							else
							{
								break;
							}
							break;
						}
						default:
						{
							std::cout << "Account Type Dont match!" << std::endl;
							break;
						}

					}
				}
				else
				{
					std::cout << "Invalid Action!\n" << "Try again:" << std::endl;

				}
			}while (true);
		}
	}while (true);
}

