#include "../heaader/Message.h"

#include <iostream>

Message::Message(User *sender, Conversation *conversation) : m_sender {sender}, m_conversation {conversation} { }
