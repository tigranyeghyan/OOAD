#pragma once

#include <string>

#include "Message.h"

class TextMessage : public Message
{
public:
	TextMessage(User *sender, Conversation *conversation, const std::string &content);
	void displayContent() const override;
	std::string getMessageType() const override;
private:
	std::string m_content;
};
