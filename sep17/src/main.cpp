#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>
#include "../header/User.h"

int main()
{
	std::vector<User*> users;
	bool end = true;
	bool conv = false;
	do 
	{
		size_t action = 0;
		std::cout << "Chose Action:" << std::endl;
		std::cout << "1 --> Create User: " << std::endl;
		if(users.size() >= 1)
		{
			std::cout << "2 --> Manage User Settings:" << std::endl;
			if(users.size() >= 2)
			{
				std::cout << "3 --> Create Conversation:" << std::endl;
				std::cout << "4 --> Manage Conversation:" << std::endl;
			}
		}
		std::cout << "0 --> Exit:" << std::endl;
		std::cin >> action;
		if(action == 0)
		{
			std::cout << "Exiting ..." << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(2));
			end = false;
		}
		else if(action == 1)
		{
			std::string name;
			std::string contact;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Enter Name: ";
			std::getline(std::cin, name);
			std::cout << "Enter contact: ";
			std::getline(std::cin, contact);
			User* ptr= new User(name, contact);
			users.push_back(ptr);
			std::this_thread::sleep_for(std::chrono::seconds(2));
		}
		else if(action == 2)
		{
			if(users.empty())
			{
				std::cout << "Invalid Action! Try Again Later ..." << std::endl;
				std::this_thread::sleep_for(std::chrono::seconds(2));
				continue;
			}
			else
			{
				std::cout << "Chose User to Manage Settings:" << std::endl;
				size_t us = users.size();
				for(int i = 0; i < users.size(); ++i)
				{
					std::cout << i + 1 << " --> " << users[i] -> getName() << std::endl;
				}
				std::cin >> us;
				if(us - 1 >= users.size())
				{
					std::cout << "Invalid option! Please Try Again Later ..." << std::endl;
					std::this_thread::sleep_for(std::chrono::seconds(2));
					continue;
				}
				else
				{
					users[us - 1] -> manageSettings(); 
				}
			}
		}
		else if(action == 3)
		{
			if(users.size() < 2)
			{
				std::cout << "Invalid Option! Try Again Later ..." << std::endl;
				std::this_thread::sleep_for(std::chrono::seconds(2));
				continue;
			}
			else
			{
				std::cout << "Select Your User: " << std::endl;
				size_t user1 = users.size();
				size_t user2 = users.size();
				for(int i = 0; i < users.size(); ++i)
				{
					std::cout << i + 1 << " --> " << users[i] -> getName() << std::endl;
				}
				std::cin >> user1;
				--user1;
				if(user1 >= users.size())
				{
					std::cout << "Invalid Option! Try Again Later ..." << std::endl;
					std::this_thread::sleep_for(std::chrono::seconds(2));
					continue;
				}
				else
				{
					std::cout << "Select Second User:" << std::endl; 
					for(int i = 0; i < users.size(); ++i)
					{
						std::cout << i + 1 << " --> " << users[i] -> getName() << std::endl;
					}
					std::cin >> user2;
					user2--;
					if(user2 >= users.size())
					{
						std::cout << "Invalid Option! Try Again Later ..." << std::endl;
						std::this_thread::sleep_for(std::chrono::seconds(2));
						continue;
					}
					else if(user1 == user2)
					{
						std::cout << "You Cant Message You! Try Again Later ..." << std::endl;
						std::this_thread::sleep_for(std::chrono::seconds(2));
						continue;
					}
					else  
					{
						users[user1] -> createConversation(users[user2]);
						std::cout << "Conversation Created Successfullt:" << std::endl;
						std::this_thread::sleep_for(std::chrono::seconds(2));
					}
				}		
			}
			conv = true;
		}
		else if(action == 4)
		{
			if(users.size() < 2 || conv == false)
			{
				std::cout << "Invalid Opton! Try Again Later ..." << std::endl;
				std::this_thread::sleep_for(std::chrono::seconds(2));
				continue;
			}
			size_t select = users.size();
			std::cout << "Select Your User: " << std::endl;
			for(int i = 0; i < users.size(); ++i)
			{
				std::cout << i + 1 << " --> "  << users[i] -> getName() << std::endl;
			}
			std::cin >> select;
			--select;
			if(select > users.size())
			{
				std::cout << "Invalid Option! Try Again Later ..." << std::endl;
				std::this_thread::sleep_for(std::chrono::seconds(2));
				continue;
			}
			else
			{
				size_t option = 0;
				Conversation* ptr = nullptr;
				bool t = false;
				std::cout << "Chose Conversation:" << std::endl;
				t = users[select] -> viewAllConversations();
				if(t)
				{
					std::cin >> option;
				}
				else
				{
					std::this_thread::sleep_for(std::chrono::seconds(2));
					continue;
				}
				option --;
				ptr = users[select] -> getConversation(option);
				if(ptr == nullptr)
				{
					std::cout << "Invalid option! Try Again Later ..." << std::endl;
					std::this_thread::sleep_for(std::chrono::seconds(2));
					continue;
				}
				else
				{
					size_t todo = 0;
					std::cout << "Select What To Do:" << std::endl;
					std::cout << "1 --> Send Message:" << std::endl;
					std::cout << "2 --> Recieve Message:" << std::endl;
					std::cout << "3 --> View Conversation History:" << std::endl;
					std::cin >> todo;
					if(todo == 1)
					{
						users[select] -> sendMessage(ptr);
					}
					else if(todo == 2)
					{
						users[select] -> receiveMessage(ptr);
					}
					else if(todo == 3)
					{
						users[select] -> viewConversationHistory(ptr);
					}
					else
					{
						std::cout << "Invalid Option! Try Again Later ..." << std::endl;
						std::this_thread::sleep_for(std::chrono::seconds(2));
						continue;
					}
				}
			}
		}
		else
		{
			std::cout << "Invalid Option! Try Again Later ..." << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(2));
			continue;
		}
		

	}while(end);

	return 0;
}
