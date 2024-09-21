#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <memory>

#include "../header/User.h"
#include "../header/TextMessage.h"
#include "../header/MultimediaMessage.h"

User::User(std::string name, std::string contactInfo) : m_name {name}, m_contactInfo {contactInfo}
{
	std::cout << "User Created Successfully!" << std::endl;
}


void User::createConversation(User *user)
{
	std::vector<User*> users;
	users.push_back(this);
	users.push_back(user);
	std::cout << "Conversation Started:" << std::endl;
	Conversation *ptr = new Conversation(users);
	conversations.push_back(ptr);
	user -> conversations.push_back(ptr);
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
	
	if(type == 1) 
	{	
		std::string content;
		std::cout << "Enter text: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::getline(std::cin, content);
		Message* ptr = new TextMessage(this, conversation, content);
		conversation -> addMessage(getName(), ptr);
		ptr = nullptr;
	}
	else if(type == 2)
	{
		std::string filePath;
		std::string fileType;
		std::cout << "Enter File Path: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::getline(std::cin,filePath);
		std::cout << "Enter File Type: ";
		std::getline(std::cin, fileType);
		Message *ptr = new MultimediaMessage(this, conversation, filePath, fileType);
		conversation -> addMessage(getName(), ptr);
	}
	else
	{
		
		std::cout << "Incorrect Option!" << std::endl;
	}
}


void User::receiveMessage(Conversation *conversation)
{	
	conversation -> getNewMessages(this);
}

std::string User::getName() const
{
	return m_name;
}


bool User::viewAllConversations() const
{
	if(conversations.empty())
	{
		std::cout << "There are no conversations! Create Conversation And Try Again Later:"<< std::endl;
		return false;
	}
	
	for(int i = 0; i < conversations.size(); ++i)
	{
		std::cout << i + 1 << " --> " << conversations[i] -> showParticipants() << std::endl; 
	}
	return true;
}

Conversation * User::getConversation(size_t index)
{
	if(index >= conversations.size())
	{
		return nullptr;
	}
	return conversations[index];
}
