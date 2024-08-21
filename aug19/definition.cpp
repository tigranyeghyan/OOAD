#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <limits>
#include "header.h"

//User::User() : m_email {""}, m_password {""}, m_fullname {""} {}

void User::create_user()
{
	std::cout << "Creating User..." << std::endl;
	set_email();
	set_password();
	set_fullname();
	std::cout << "Account has been created Successfully!" << std::endl;
}

void User::change_user_parametres()
{
	int choice = 0;
	while(true)
	{
		std::cout << "Choose Parameter to change: " << std::endl;
		std::cout << "1. Update Email:" << std::endl;
		std::cout << "2. Change Password:" << std::endl;
		std::cout << "3. Update FullName:" << std::endl;
		std::cout << "0. EXIT:" << std::endl;
		std::cin >> choice;
		std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		switch(choice)
		{
			case 1:
				update_email();
				break;
			case 2:
				change_password();
				break;
			case 3:
				update_fullname();
				break;
			case 0:
				std::cout << "Exiting ..." << std::endl;
				return; 
			default:
			std::cout << "Incorrect Choice!" << std::endl;
		}
	}

}

void User::set_fullname()
{
	std::string fullname;
	int it = 0;
        do
        {
                if(it == 0)
                {
                        std::cout << "Enter FullName: ";
                }
                else
                {
                        std::cout << "Fullname is incorrect! " << std::endl;
                        std::cout << "Enter correct FullName:  " ;
                }
                std::getline(std::cin, fullname);
                it++;
        }while(!is_fullname(fullname));
	m_fullname = fullname;
}

void User::set_email()
{
	std::string email;
	int it = 0;
        do
        {
                if(it == 0)
                {
                        std::cout << "Enter Email: ";
                }
                else
                {
                        std::cout << "Email is Incorrect! " << std::endl;
                        std::cout << "Enter valid Email:  " ;
                }
                std::getline(std::cin, email);
                it++;
        }while(!is_email(email));
	m_email = email;
}

void User::set_password()
{
	std::string password;
	std::cout << "Password Requirements" << std::endl;
        std::cout << "1. At least 6 characters long:" << std::endl;
        std::cout << "2. A combination of uppercase letters, lowercase letters, numbers, and symbols." <<std::endl;
        int it = 0;
        do
        {
                if(it == 0)
                {
                        std::cout << "Enter Password: ";
                }
                else
                {
                        std::cout << "Password does not meet Requirements! " << std::endl;
                        std::cout << "Enter valid Password:  " ;
                }
		std::getline(std::cin, password);
                it++;
        }while(!is_password(password));
	m_password = password;
}

void User::change_password()
{
	std::cout << "Login to account:" << std::endl;
	while(true)
	{
		if(login())
		{
			set_password();
			break;
		}
		else
		{
			std::cout << "Incorrect Email or Password!" << std::endl;
			std::cout << "1. Try Again:" << std::endl;
			std::cout << "0. EXIT:" << std::endl;
			int choice = 0;
	       		std::cin >> choice;
			std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	       		if(choice == 0)
			{
				std::cout << "Exiting ..." << std::endl;
				return;
			}	
		}	
	}	
}

void User::update_email()
{
        std::cout << "Login to account:" << std::endl;
        while(true)
        {
                if(login())
                {
                        set_email();
			break;
                }
                else
                {
                        std::cout << "Incorrect Email or Password!" << std::endl;
                        std::cout << "1. Try Again:" << std::endl;
                        std::cout << "0. EXIT:" << std::endl;
                        int choice = 0;
                        std::cin >> choice;
			std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        if(choice == 0)
                        {       
                                std::cout << "Exiting ..." << std::endl;
                                return;
                        }
                }
        }
}

void User::update_fullname()
{
        std::cout << "Login to account:" << std::endl;
        while(true)
        {
                if(login())
                {
                        set_fullname();
			break;
                }
                else
                {
                        std::cout << "Incorrect Email or Password!" << std::endl;
                        std::cout << "1. Try Again:" << std::endl;
                        std::cout << "0. EXIT:" << std::endl;
                        int choice = 0;
                        std::cin >> choice;
			std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        if(choice == 0)
                        {
                                std::cout << "Exiting ..." << std::endl;
                                return;
                        }
                }
        }
}

bool User::login()
{
	std::string password;
      	std::cout << "Enter password: ";
	std::getline(std::cin, password);
	return (m_password == password);
}

bool User::is_email(std::string email)
{	
	if(email.find_first_of("!#$%^&*()+=/<>?':;[]{}|~`") != std::string::npos || email.find(' ') != std::string::npos)
	{
		return false;
	}
	if(count(email.begin(), email.end(), '@') != 1)
	{
		return false;
	}
	if(count(email.begin(), email.end(), '.') == 0)
	{
		return false;
	}
	return true;
}

bool User::is_password(std::string password)
{
	if(password.size() < 6)
	{
		return false;
	}
	bool uppercase = false;
	bool lowercase = false;
	bool number = false;
	bool symbol = false;
	for(int i = 0; i < password.size(); ++i)
	{
		if(islower(password[i]))
		{
			lowercase = true;
		}
		if(isupper(password[i]))
                {
                        uppercase = true;
                }
		if(isdigit(password[i]))
                {
                        number = true;
                }
		if(ispunct(password[i]))
                {
                        symbol = true;
                }
	}
	if(uppercase && lowercase && number && symbol)
	{
		return true;
	}
	return false;
}

bool User::is_fullname(std::string fullname)
{
	std::string name;
	std::string lastname;
	name = fullname.substr(0, fullname.find(' '));
	lastname = fullname.substr(fullname.rfind(' ') + 1, fullname.size());
	if(!isupper(name[0]))
	{
		return false;
	}
	if(!isupper(lastname[0]))
	{
		return false;
	}
	for(int i = 1; i < name.size(); ++i)
	{
		if(!isalpha(name[i]) || !islower(name[i]))
		{
			return false;
		}
	}
	for(int i = 1; i < lastname.size(); ++i)
        {
                if(!isalpha(lastname[i]) || !islower(lastname[i]))
                {
                        return false;
                }
        }
	return true;
}

void User::show_info() const 
{
	std::cout << "Email:     " << m_email << std::endl;
	std::cout << "Fullname:  " << m_fullname << std::endl;
}

std::string User::get_email() const
{
	return m_email;
}
