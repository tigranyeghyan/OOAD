#pragma once
#include <string>
#include "Conversation.h"
#include "User.h"

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
