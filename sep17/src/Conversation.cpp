#include "../header/Conversation.h"
#include "../header/User.h"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

Conversation::Conversation(std::vector<User*> users) : participants{users} 
{

}

void Conversation::addMessage(const std::string &sender, Message *message)
{
	userHistory.push_back(sender);
	messageHistory.push_back(message);

}


std::vector<Message*> Conversation::getMessages() const
{
	return messageHistory;
}

void Conversation::getNewMessages(User *ptr)
{
	std::string username = ptr -> getName();
	auto lastmessage = std::find(userHistory.rbegin(), userHistory.rend(), username);
	int index = 0;
	if(lastmessage != userHistory.rend())
	{
		index = std::distance(userHistory.rbegin(), lastmessage);
		index -= userHistory.size();
	}
	for (int i = index; i < messageHistory.size(); ++i)
	{
		messageHistory[i] -> displayContent();
	}
}


std::string Conversation::showParticipants() const
{
	std::string result = "";
	for(int i = 0; i < participants.size(); ++i)
	{
		result += participants[i] -> getName() ;
		result += (i == participants.size() - 1) ? ":" : ", ";
	}
	return result;
}
