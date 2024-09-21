#pragma once
#include <vector>
#include <string>

#include "Conversation.h"
#include "Message.h"
#include "MessagingManager.h"


class User : public MessagingManager
{
public:
	User(std::string name, std::string contactInfo);	
	// own methods
	void createConversation(User* user);
	void manageSettings();
	std::vector<Conversation*> getConversations() const;
	std::string getName() const;
	
	bool viewAllConversations() const;
	
	Conversation *getConversation(size_t index);
	// Messaging Manager method Implements
	void sendMessage(Conversation* conversation) override;
	void receiveMessage(Conversation *conversation) override;
	void viewConversationHistory(Conversation* conversation) const override;
		
private:
	std::string m_name;
	std::string m_contactInfo;
	std::vector<Conversation*> conversations;
};
