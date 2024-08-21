#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <limits>
#include "header.h"

int main()
{
	system("clear");
	std::vector<User> users;
	int it = 0;
	int choice = 1;
	while(choice != 0)
	{	
		system("clear");
		std::cout << "Choose Action to do!" << std::endl;
		std::cout << "1. Create New User:" << std::endl;
		std::cout << "2. Change User info:" << std::endl;
		std::cout << "3. Show user Info:" << std::endl;
		std::cout << "0. Quit:" << std::endl;

		std::cin >> choice;
		std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		switch(choice)
		{
			case 1:
			{
				User newUser;
                    		newUser.create_user();
                    		users.push_back(newUser);
		    		it++;
				break;
			}
			case 2:
			{
				if(it != 0)
				{
					std::string email;
					std::cout << "Enter your Email: "; 
					std::cin >> email;
			       		for(int i = 0; i < it; ++i)
					{
						if(users[i].get_email() == email)
						{
							users[i].change_user_parametres();
							break;
						}
					}
					std::cout << "User not found!" << std::endl;	
				}
				break;
			}
			case 3:
			{
				if(it != 0)
				{
					std::string email;
		                	std::cout << "Enter your Email: " ; std::cin >> email;
                                       	for(int i = 0; i < it; ++i)
                                       	{
                                       	        if(users[i].get_email() == email)
                                       	        {
                                               	        users[i].show_info();
                                                       	break;
                                               	}
                                       	}
                                       	std::cout << "User not found!" << std::endl;
				}
				break;
			}
			case 0:
			{
				std::cout << "Exiting ..." << std::endl;
				break;
			}
			default:
			{
				std::cout << "Incorrect choice!" << std::endl;
			}
		}
	}
	return 0;
}


