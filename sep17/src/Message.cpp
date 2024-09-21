#include "../header/Message.h"


Message::Message(User *sender, Conversation *conversation) : m_sender {sender}, m_conversation {conversation} { }
