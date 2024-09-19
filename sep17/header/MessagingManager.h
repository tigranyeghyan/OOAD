#pragma once

#include <vector>
#include <string>
#include "Conversation.h"
#include "Message.h"

class MessagingManager
{
public:
	virtual void sendMessage(Message *message, Conversation *conversation) = 0;
	virtual void receiveMessage(Conversation *conversation) = 0;
	virtual void viewConversationHistory(Conversation *conversation) const = 0;
};
