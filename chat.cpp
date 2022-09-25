//chat.cpp

#include <vector>
#include <string>

#include "userMsg.h"
#include "chat.h"

using std::string;

Chat::Chat(const string &name) : m_name(name) {}

Chat::~Chat () = default;

void Chat::addMsg (const UserMsg &message)
{
	MsgVec.push_back(message);
}

const string& Chat::getName() const
{
	return m_name;
}
