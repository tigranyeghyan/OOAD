#pragma once
#include <string>

#include "User.h"
#include "Conversation.h"

class Message
{
public:
	Message(User *sender, Conversation *conversation);
	virtual void displayContent() const = 0;
	virtual std::string getMessageType() const = 0;
protected:
	User* m_sender;
	Conversation* m_conversation;
};
