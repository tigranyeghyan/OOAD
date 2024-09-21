#pragma once

#include <vector>
#include <string>

class User;
class Message;

class Conversation
{
public:
	Conversation(std::vector<User*> users);
	void addMessage(const std::string &sender, Message *message);
	void getNewMessages(User *ptr);
	std::string showParticipants() const;
	std::vector<Message*> getMessages() const;
private:
	std::vector<User*> participants;
	std::vector<std::string> userHistory;
	std::vector<Message*> messageHistory;
};
