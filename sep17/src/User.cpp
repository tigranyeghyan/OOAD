#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <memory>
#include <../header/User.h>


User::User(std::string name, std::string contactInfo) : m_name {name}, m_contacInfo {contactInfo}
{
	std::cout << "User Created Successfully!" << std::endl;
}


void User::createConversation(const User& user)
{
	std::vector<User*> users;
	users.push_back(this);
	users.push_back(&user);
	std::cout << "Conversation Started:" << std::endl;
	Conversation *ptr = new Conversation(users);
	ptr = nullptr;
}


void User::manageSettings()
{
	size_t choice = 0;
	std::cout << "Chose parameter to change:";
	std::cout << "1 --> User Name:" << std::endl;
	std::cout << "2 --> User Contact Info:" << std::endl;
	std::cin >> choice;
	switch(choice)
	{
		case 1:
		{
			std::string name;
			std::cout << "Enter New User Name: ";
			std::cin.clear();
        	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::getline(std::cin, name);
			m_name = name;
		}
		case 2:
		{
			std::string contactInfo;
			std::cout << "Enter New Contact Info: ";
			std::cin.clear();
        	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::getline(std::cin, contactInfo);
			m_contactInfo = contactInfo;
		}
		default:
		{
			std::cout << "Invalid option!" << std::endl;
			break;
		}
	}
}


std::vector<Conversation*> User::getConversations() const
{
	return conversations;
}


void User::viewConversationHistory(Conversation *conversation) const
{
	std::vector<Message*> messages = conversation -> getMessages();
	for(auto message : messages)
	{
		message -> displayContent(); 	
	}
}


void User::sendMessage(Conversation *conversation)
{
	size_t type;
	std::cout << "Chose Message Type:" << std::endl;
	std::cout << "1 --> Send Text Message:" << std::endl;
	std::cout << "2 --> Multimedia:" << std::endl;
	std::cin >> type;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	switch (type)
	{
		case 1: 
		{
			
			std::sting content;
			std::cout << "Enter text: ";
			std::getline(std::cin, content);
			Message* ptr = new TextMessage(this, conversation, content);
			conversation -> addMessage(getName(), ptr);
			ptr = nullptr;
		}
		case 2:
		{
			std::string filePath;
			std::string fileType;
			std::cout << "Enter File Path: ";
			std::getline(std::cin,filePath);
			std::cout << "Enter File Type: ";
			std::getline(std::cin, fileType);
			Message *ptr = new MultimediaMessage(this, conversation, filePath, fileType);
			conversation -> addMessage(getName(), ptr);
		}
		default:
		{
			std::cout << "Incorrect Option!" << std::endl;
			break;
		}
	}
}


void User::receiveMessage(Conversation *conversation)
{
	
}

std::string User::getName() const
{
	retrun m_name;
}

