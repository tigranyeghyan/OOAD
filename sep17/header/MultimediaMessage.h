#pragma once 

#include <string>

#include "Message.h"

class MultimediaMessage : public Message
{
public:
	MultimediaMessage(User *sender, Conversation *conversation, const std::string &filePath, const std::string &mediaType);
	void displayContent() const override;
	std::string getMessageType() const override;
private:
	std::string m_filePath;
	std::string m_mediaType;
};
