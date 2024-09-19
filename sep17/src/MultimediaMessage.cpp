#include "../header/MultimediaMessage.h"

#include <iostream>
#include <string>

MultimediaMessage::MultimediaMessage(User *sender, Conversation *conversation, const std::string &filePath, const std::string &mediaType) : Message(sender, conversation), m_filePath {filePath}, m_mediaType {mediaType} { }

void MultimediaMessage::displayContent() const
{
	std::cout << m_sender -> getName() << " --> " << m_filePath << "\t" << m_mediaType << std::endl;
}

std::string MultiMediaMessage::getMessageType() const
{
	return "media";
}
