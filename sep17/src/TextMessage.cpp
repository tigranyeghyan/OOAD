#include "../header/TextMessage.h"

#include <iostream>
#include <string>

TextMessage::TextMessage(User *sender, Conversation *conversation, const std::string &content) : Message(sender, conversation), m_content {content} { }

void TextMessage::displayContent() const
{
	std::cout << m_sender -> getName() << " --> " << m_content << std::endl;
}

std::string TextMessage::getMessageType() const
{
	return "text";
}
