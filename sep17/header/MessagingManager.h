#pragma once

#include <vector>
#include <string>

class Conversation;
class Message;

class MessagingManager
{
public:
	virtual void sendMessage(Conversation *conversation) = 0;
	virtual void receiveMessage(Conversation *conversation) = 0;
	virtual void viewConversationHistory(Conversation *conversation) const = 0;
};
