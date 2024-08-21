#include <iostream>
#include <vector>
#include <string>
#include "header.h"

void Bank::createAccount()
{
	Account newAccount;
	
	std::string name = "";
        do
        {
                std::cout << "Enter Your name: ";
                std::cin >> name;
        }while(!is_name(name));
        std::string lastname;
        do
        {
                std::cout << "Enter Your lastname: ";
                std::cin >> lastname;
        }while(!is_name(lastname));
	std::string username = "";
	do
	{
		std::cout << "Enter username: ";
		std::cin >> username;
	}while(!is_username(username) || already_used(username));
	std::string password;
	do
        {
                std::cout << "Enter password that include A-Z, a-z, 0-9, and at least 1 symbol: ";
                std::cin >> password;
        }while(!is_password(password));
        int number = accounts.size() + 1;
	newAccount.set_username(username);
	newAccount.set_name(name);
	newAccount.set_lastname(lastname);
	newAccount.set_password(password);
	newAccount.set_number(number);
	std::cout << "Account has been created successfully!" << std::endl;
}

void Bank::deleteAccount()
{
	std::cout << "Deleting Account!" << std::endl;
	std::string username;
	std::cout << "Enter Account username: ";
	std::cin >> username;
	std::string password;
        std::cout << "Enter Account password: ";
        std::cin >> password;
	int number = 0;
	if(log_in(username, password, number))
	{
		accounts.erase(accounts.begin() + number - 1);
	}
	for(int i = number - 1; i < accounts.size(); ++i)
	{
		accounts[i].number -= 1; 
	}
	std::cout<< "Account has been deleted!" << std::endl;
}

void Bank::changeAccountSettings()
{
	std::string username;
	std::string password;
	int number = 0;
	std::cout << "Log In" << std::endl;
	std::cout << "Enter Username: ";
	std::cin >> ussername;
	std::cout << "Enter Password: ";
	std::cin >> password;
	while(!log_in(username, password, number))
	{
		std::cout << "Invalid username or password:" << std::endl;
		std::cout << "1. Try Again: " << "\t" << "2. Exit: " << std::endl; 
		int choice = 0;
		std::cin >> choice;
		if(choice == 2)
		{
			return;
		}
		else
		{
			std::cout << "Enter Username: ";
        		std::cin >> ussername;
        		std::cout << "Enter Password: ";
	        	std::cin >> password;
		}
	}
	int choice = 0;
	do
	{
		std::cout << "1. Change Account Name:" << std::endl;
       		std::cout << "2. Change Account Lastname:" << std::endl;
		std::cout << "3. Change Account Username:" << std::endl;
		std::cout << "4. Change Account Password:" << std::endl;
		std::cout << "5. Change Account Status:" << std::endl;
		std::cout << "0. EXIT" << std::endl;
	       	switch(choice)
		{
			case 1:
				std::string name;
				do
				{
					std::cin >> name;
					std::cout << "Enter new Name: ";
				}while(!is_name(name))
				accounts[number - 1].name = name;

			case 2:	


			case 3:


			case 4:


			case 5:

			
			case 0:
				std::cout << "Exiting!" << std::endl;
				break;
			default:
				std::cout << "Incorrect choice!" << std::endl;
				break;
		}	
	}while(choice != 0);	
}






