#pragma once

#include <vector>
#include <string>
#include "Message.h"



class Conversation
{
public:
	Conversation(std::vector<User*> users);
	void addMessage(const std::string &sender, Message *message);
	void addUser(User* user);
	std::vector<Message*> getMessages() const;
private:
	std::vector<User*> participants;
	std::vector<std::string> userHistory;
	std::vector<Message*> messageHistory;
};
