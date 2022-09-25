//user.cpp

#include <string>
#include <vector>

#include "chat.h"
#include "user.h"

using std::string;

User::User(
	const string &login,
	const string &pass,
	const string &nick
)
: Chat(nick), m_login(login), m_pass(pass) {}

User::~User() = default;

void User::sendMsg(const string &nick, const string &msg)
{
	//
}
